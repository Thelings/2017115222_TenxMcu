#ifndef __main_h
#define __main_h 

#define P_led1 P2_0
#define P_led2 P2_1
#define F_led1On() P_led1 = 0
#define F_led1Off() P_led1 = 1
#define F_led2On() P_led2 = 0
#define F_led2Off() P_led2 = 1
 
// 定义基准时间
//基准时间 4ms
#define D_4ms 1
#define D_250ms  70
#define D_1s   250
//基准时间 1s
#define D_1m   60
//基准时间 1m
#define D_1h   60

#ifdef MAIN_C
    bit b4ms;
    uint8_t timer1Click, timer4ms, timer250ms, timer1s, timer1m, timer1h;
#else
    extern bit b4ms;
    extern uint8_t  timer1Click, timer4ms, timer250ms, timer1s, timer1m, timer1h; ;
#endif

void InitSys();
void DisplayProcess();
void UserSettingProcess();
void TimeProcess();
void TaskProcess();
void Delay(int time);

#endif
