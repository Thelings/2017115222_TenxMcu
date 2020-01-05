#define __SMG_C_
#include "includeAll.h"



char mask[]={0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80};//掩码，用来判断0~7位是否为1
/*
*数码管显示*
*x:显示的字符（例如：0x3f->0;0x3f的D0~D7即a~g）
*number:第几号管脚(1右2左)
*/
void smg_display(char x,uint8_t number){
    if(number==1){
        SMG_COM1=0;
        SMG_COM2=1;
    }
    if(number==2){
        SMG_COM1=1;
        SMG_COM2=0;
    }
    /*a*/
    if (x&mask[0])
    {
        SMG_A=1;
    }else
    {
        SMG_A=0;
    }
    /*b*/
    if (x&mask[1])
    {
        SMG_B=1;
    }else
    {
        SMG_B=0;
    }
    /*c*/
    if (x&mask[2])
    {
        SMG_C=1;
    }else
    {
        SMG_C=0;
    }
    /*d*/
    if (x&mask[3])
    {
        SMG_D=1;
    }else
    {
        SMG_D=0;
    }
    /*e*/
    if (x&mask[4])
    {
        SMG_E=1;
    }else
    {
        SMG_E=0;
    }
    /*f*/
    if (x&mask[5])
    {
        SMG_F=1;
    }else
    {
        SMG_F=0;
    }
    /*g*/
    if (x&mask[6])
    {
        SMG_G=1;
    }else
    {
        SMG_G=0;
    }
    SMG_DG=0;
}
/*
*两个数码管亮*
*左管显示x，右管显示y*
*/
void smg_double(char x,char y){
    uint8_t a,b;
    for(a=0;a<1000;a++){
    for(b=0;b<100;b++){
        smg_display(x,2);
        delayMs(1);
        smg_display(y,1);
        delayMs(1);
    }
   // delayMs(10);
    GetKeys();
    if(keyValue2==D_keyValue1){
        break;
    }
    }

}

/*关闭数码管*/
void smg_close(){
  SMG_COM1=1;
  SMG_COM2=1;
}