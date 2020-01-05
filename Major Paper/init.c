#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
	F_clearWDT();
  //鏃堕挓鍒濆?嬪寲
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

  
  smg_init();
	KeyInit();
  led_init();
  // T2 ???  7.3728Mhz/2 = 3686400Hz
  //  3686400Hz/3686.4 = 1000Hz = 1ms timer2 
	TH2 = (65536 - 922) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 922) % 256;
  RCP2L = TL2;
  TR2 = 1;
  ET2 = 1;
  EA = 1; 
}
//=============================================================================
void VarsInit() {}

/*数码管初始化，将a~dg设为推挽输出*/
void smg_init(){
  /*a 1.4 || d 1.7 */
  P1MODH &= 0x3c;
  P1MODH |= 0x82;
  /*b 3.4 || c 3.5 || e 3.6*/
  P3MODH &= 0x00;
  P3MODH |= 0x2a;
  /*f 1.2||dg 1.3 */
  P1MODL &= 0x0f;
  P1MODL |= 0xa0;
  /*g 3.2*/
  P3MODL &= 0xcf;
  P3MODL |= 0x20;
}

void led_init(){
  P1MODL &= P12MOD_Mask;
	P1MODL |= P12MOD_2;

	P1MODH &= P14MOD_Mask;
	P1MODH |= P14MOD_2;
}
void KeyInit()
{
	/* key 1 */
	P3MODH &= P34MOD_Mask;
	P3MODH |= P34MOD_0;

	/* key 2 */
	P3MODL &= P32MOD_Mask;
	P3MODL |= P32MOD_0;

	/* key 3 */
	P1MODH &= P17MOD_Mask;
	P1MODH |= P17MOD_0;

	/* key 4 */
	P1MODL &= P12MOD_Mask;
	P1MODL |= P12MOD_0;
}
