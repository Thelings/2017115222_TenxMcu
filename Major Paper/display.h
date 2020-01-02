#ifndef __display_h
#define __display_h
// Hal: exp: #define P_led_1 P1.1 -----------------
#define P_led_1 P1_4
#define P_led_2 P1_2
#define P_led_com P1_0

// Const: exp: #define D_data 1 ----------------
#define D_ledOn 1  //高电位亮
#define D_ledOff 0 //低点位灭
// Globle Var -----------------------------------------
#ifdef __display_c
#else
#endif

// Action Macro: exp: #define F_getData() ------
#define F_led1On()  P_led_1 = D_ledOn
#define F_ledO1ff()  P_led_1 = D_ledOff
#define F_led1Neg()  P_led_1 = ~P_led_1

#define F_led2On()  P_led_2 = D_ledOn
#define F_ledO2ff()  P_led_2 = D_ledOff
#define F_led2Neg()  P_led_2 = ~P_led_2
// Function ------------------------------------
extern void LED_Disable(void);
#endif