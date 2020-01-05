#define __main_c
#include "includeAll.h"
//=============================================================================
uint8_t ledValue2=0;//led2�?与否1/0
void main() {
  
  SysInit();
  VarsInit();
	//使能看门�?
	F_turnOnWDT();

	P_buzz = 0;

	delayMs(500);

	P_ledcom=0;
	F_ledOff1();
	F_ledOff2();
	  smg_init();
	while(1){
		//清看门狗
		F_clearWDT();
		//业务代码
		TimeProcess();
		TaskSetting();
		TaskProcess();
		DisplayProcess();
	    
	}
}

//=============================================================================
	void TimeProcess(){
		static uint8_t timer5ms = 0;
		
		if (b1ms) {
			// 1ms 执�?�一�?
			b1ms = 0;
			timer5ms++;
		}
		if (timer5ms >= 5) {
            	
			GetKeys();
		}
	}
//=============================================================================
bit smgval=0;

	void TaskSetting(){	
		if(D_keyValue1==keyValue3){
			//led_init();
			F_ledNeg2();
            buzzCounter=1000;
		}
	    if(D_keyValue1==keyValue2){
			
			smg_init();
			buzzCounter=1000;
			
			if (smgval==0)
			{
				smg_double(0x3f,0x71);
				smgval=1;
			}else
			{
				
				smg_close();
				smgval=0;
			}
			KeyInit();
			led_init();
		}
		if (D_keyValue1==keyValue1)
		{
			F_ledNeg1();
			buzzCounter=1000;
		}

		
		
        keyValue1=D_keyNull;
		keyValue3=D_keyNull;
		keyValue2=D_keyNull;
		//keyValue4=D_keyNull;
	} 
//=============================================================================
	void TaskProcess(){

	}
//=============================================================================
	void DisplayProcess(){
	
	}
//=============================================================================
//延时函数
void delayMs(uint16_t time){
	uint16_t i,j;
	for(i=0; i<time; i++){
		for(j=0; j<1000; j++){
			F_clearWDT();
		}
	}
}

