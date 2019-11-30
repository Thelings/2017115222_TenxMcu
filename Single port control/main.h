#ifndef __main_h
#define __main_h
// Hal: exp: #define P_led1 P11 -----------------

// Const: exp: #define D_data 1 ----------------

// 
#define D_5ms 5
#define D_1000ms 1000


// Globle Var -----------------------------------------
#ifdef _main_c

#else

#endif


#define model_Switch() model = ~model


void TimeProcess();
void DisplayProcess();
void TaskSetting();
void TaskProcess();


void DelayMs(int time);

#endif 