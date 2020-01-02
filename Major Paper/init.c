#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
  //时钟初始化
  CLKCON = 0x03; // Clock div 1
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
  // IO 模式初始化
  P1MODL = 0xaa;
	P1MODH = P14MOD_2 | P15MOD_2;

  P1MODH |= P14MOD_2;
	P1MODL |= P12MOD_2;
 
  P_led_com = 0; /* 根据电路图，com 口应恒为低 */
	P_led_1 = 0;
	P_led_2 = 0;
}
//=============================================================================
void VarsInit() {}