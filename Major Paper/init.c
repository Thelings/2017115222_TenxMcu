#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
	F_clearWDT();
  
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  // IO 口初始化
	P1MODL = 0xaa;		//将模式设置为推挽输出
	P1MODH = 0xaa;
	//P1MODL = 0xa8;		//上拉输入
	P1_2 = 1;

	
  // T2  7.3728Mhz/2 = 3686400Hz
  //  3686400Hz/3686.4 = 1000Hz = 1ms timer2 
	TH2 = (65536 - 3686) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 3686) % 256;
  RCP2L = TL2;
  TR2 = 1;
  ET2 = 1;
  EA = 1; 
}
//=============================================================================
void VarsInit() {}