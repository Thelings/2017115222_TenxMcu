#ifndef __main_h
#define __main_h
// Hal: exp: #define P_led P10 -----------------

// Const: exp: #define D_data 1 ----------------

// Globle Var -----------------------------------------
#define soo 3686400/784 //中音'5'
#define dao 3686400/1047	//宏定义高音‘1’频率为1047Hz
#define re 3686400/1175
#define mi 3686400/1319
#define fa 3686400/1397
#define so 3686400/1568
#define la 3686400/1760
#define xi 3686400/1967

#ifdef __main_c
#else


#endif


// Action Macro: exp: #define F_getData() ------

// Function ------------------------------------
void delayMs(uint16_t time);
void TimeProcess();
void TaskSetting();
void TaskProcess();
void DisplayProcess();

#endif