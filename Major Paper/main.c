#define __main_c
#include "includeAll.h"
//=============================================================================
uint8_t ledValue2=0;//led2�?与否1/0
int code song[]={dao,re,mi,dao,dao,re,mi,dao,mi,fa,so,mi,fa,so,so,la,so,fa,mi,dao,so,la,so,fa,mi,dao,re,soo,dao,re,soo,dao};	//以0xff为音符结束标志
	//以下为每个音符节拍,4个延时单位为1拍
	//'4'对应4个延时单位，'2'对应2个延时单位，'1'对应1个
char code JP[]={4,4,4,4,4,4,4,4,3,3,8,3,3,8,3,1,3,1,4,4,3,1,3,1,4,4,4,4,8,4,4,8};
	int8_t i=0;
bit music;	
void main() {


  SysInit();
  VarsInit();
	//使能看门�?
	F_turnOnWDT();

	P_buzz = 0;
    buzzCounter=0;
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
			music=~music;
			if(music==0){
				buzzCounter=0;
				TR2=0;
			TH2 = (65536 - 922) / 256;
            RCP2H = TH2;
            TL2 = (65536 - 922) % 256;
            RCP2L = TL2;
		    TR2=1;
			i=0;
			}
			
		}

		
		
        keyValue1=D_keyNull;
		keyValue3=D_keyNull;
		keyValue2=D_keyNull;
		//keyValue4=D_keyNull;
	} 
//=============================================================================

	void TaskProcess(){
		if(music==1){
		if (buzzCounter==0)
		{
			TR2=0;
			TH2 = (65536 - song[i]) / 256;
            RCP2H = TH2;
            TL2 = (65536 - song[i]) % 256;
            RCP2L = TL2;
		    TR2=1;
			buzzCounter=500*JP[i];
			i++;
			if (i==32)
			{
				i=0;
			}
		}
		}
		else
		{
			
		}
		
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

