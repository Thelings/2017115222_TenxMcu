#define __main_c
#include "includeAll.h"
//=============================================================================
void main()
{

	SysInit();  //系统初始化
	VarsInit(); //变量初始化
	//使能看门狗
	F_turnOnWDT();
	F_led1On();
	F_led2On();
	while (1)
	{
		//喂狗
		F_clearWDT();
		//业务代码
		TimeProcess();
		TaskSetting();
		TaskProcess();
		// DisplayProcess();
	}
}
void TimeProcess()
{

}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting()
{
}
//=============================================================================
void DisplayProcess()
{
	//F_ledOn();
}
void delayMs(uint16_t msCount)
{
	uint16_t i, j;
	for (i = 0; i < msCount; i++)
	{
		for (j = 0; j < 1000; j++)
		{
			/* code */
			F_clearWDT();
		}
	}
}