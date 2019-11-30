#ifndef AD0832_H
#define AD0832_H
/**********************************
包含头文件
**********************************/
#include <reg51.h>
#include "delay.h"
#include "dht11.h"
/**********ADC0832接口程序************************************/ 
sbit ADC_CS =P3^4; 
sbit ADC_CLK=P3^5; 
sbit ADC_DO =P3^6; 
sbit ADC_DI =P3^7; 
extern data_c;
/**********************************
函数声明
**********************************/
uchar ADC0832(void);
void delay_us(uchar i);				  
#endif