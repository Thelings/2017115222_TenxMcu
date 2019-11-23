#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
  F_ledOn();
  DelayMs(500);
  //使能看门狗
  F_turnOnWDT();
  while (1) {
    //喂狗
    F_clearWDT();
    //业务代码
    TimeProcess();
    TaskProcess();
    TaskSetting();
    DisplayProcess();
}
//=============================================================================
void DelayMs(uint16_t msCount) {
  uint16_t i, j;
  for (i = 0; i < msCount; i++) {
    for (j = 0; j < 1000; j++) {
      /* code */
      F_clearWDT();
    }
  }
}

void TimeProcess(){
  static uint16_t second = 0;
  if (b1ms)
  {
    b1ms = 0;
    second++;
  }
  if (second >= D_1000ms)
  {
    second = 0;
  }
  
  
}

void TaskProcess(){

}

void TaskSetting(){
  GetKeys();
    if (D_keyValue1 == keyValue) {
      F_ledNeg();
    }
    keyValue = D_keyNull;
  }
}

void DisplayProcess(){

}