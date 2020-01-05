#ifndef __display_h
#define __display_h
// Hal: exp: #define P_led P10 -----------------
#define P_ledcom P1_0	
#define P_led2 P1_2
#define P_led1 P1_4


#define P_D P1_7
// Const: exp: #define D_data 1 ----------------
#define D_ledOn 1  //高电位亮
#define D_ledOff 0 //低点位灭
// Globle Var -----------------------------------------
#ifdef __display_c

#else

#endif

// Action Macro: exp: #define F_getData() ------
#define F_ledOn1() P_led1 = D_ledOn
#define F_ledOff1() P_led1 = D_ledOff
#define F_ledNeg1() P_led1 = ~P_led1

#define F_ledOn2() P_led2 = D_ledOn
#define F_ledOff2() P_led2 = D_ledOff
#define F_ledNeg2() P_led2 = ~P_led2

// Function ------------------------------------

#endif