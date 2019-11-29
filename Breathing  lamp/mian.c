#define __main_c
#include "includeAll.h"

int test = 0;   // 定义一个test变量用于表示LedOn时的延时时间
int flag = 1;  // flag = 1 代表led从暗逐渐变到亮

//============================================
void main() {
  F_turOnWDT(); // 看门狗寄存器
  InitSys();

  TH2 = (65536 - 900) / 256; // 0.25ms==4khz timer2 interrupt
  RCP2H = TH2;
  TL2 = (65536 - 900) % 256;
  RCP2L = TL2;

  EA = 1;  // 开总中断
  ET2 = 1; // timer2 interrupt enable
  TR2 = 1; // timer2 running

  while (1) {

      TimeProcess();

  }
}
//============================================
void InitSys() {
  // system clock
  CLKCON = 0x03; // Clock div 1
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;

  // I/O init
  P2MOD = 0xa;
}
//============================================
void DisplayProcess() {}
//============================================
void UserSettingProcess() {}
//============================================
void TaskProcess() {}
//============================================
void TimeProcess() {
  if (b4ms == 1) {
    b4ms = 0;
    timer4ms++;
    timer250ms++;
    timer1s++;
  }

  if ((timer4ms >= D_4ms)) {
    timer4ms = 0;
    // do something
    
    if(test > 300){
      test = 300;
      flag = 0;  // flag = 0 代表led从亮逐渐变到暗      
    }

    if(test < 0){
      test = 0;
      flag = 1; // flag = 1 代表led从暗逐渐变到亮
    }

    F_led1On();
    Delay(test);
    F_led1Off();
    Delay(3000);

    if(test <= 300 && flag == 1){
      test += 1;
    }

    if(test <= 300 && flag == 0){
      test -= 1;
    }

  }

  if (timer250ms >= D_250ms) {
    timer250ms = 0;
    // do something
  }

  if (timer1s >= D_1s) {
    // 1s
    timer1s = 0;
    // do something
    timer1m++;
    if (timer1m >= D_1m) {
      // 1m
      timer1m = 0;
      // do something
      timer1h++;
      if (timer1h >= D_1h) {
        timer1h = 0;
        // do something
      }
    }
  }
}

//=============================================================================
// Function:	void TIMER2_int(void)
// Purpose:	TIMER2 interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void TIMER2_int(void) interrupt 5 { // 4Khz == 0.25ms
  TF2 = 0;                          // clear interrupt flag
  TR2 = 1;

  TH2 = (65536 - 900) / 256; // 重新给定时器赋初值
  RCP2H = TH2;
  TL2 = (65536 - 900) % 256;
  RCP2L = TL2;

  timer1Click++;
  if (timer1Click > 16) { // 16=4ms@0.25ms
    b4ms = 1;
    timer1Click = 0;
  }
}

// 用于LED灯的延时
void Delay(int time) {
  int i;
  for (i = 0; i < time; i++)
    CLRWDT = 1;
}
