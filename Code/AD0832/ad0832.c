#include "ad0832.h"
#include "delay.h"
#include "dht11.h"

uchar ADC0832(void) //把模拟电压值转换成8位二进制数并返回 
{ 

	uchar i,data_c; 
	data_c=0; 
	ADC_CS=0; 
	ADC_CLK=1; 
	ADC_DO=0;//片选，DO为高阻态 
	//ADC_DI=0; //先拉低

	for(i=0;i<10;i++)    
	{;}

	ADC_CLK=0; 
	delay_us(2); 
	ADC_CLK=1; 
	ADC_DI=1; //启始位  
	delay_us(2); 

	ADC_CLK=0; //第一个脉冲下降沿，DI=1为起始位 
	delay_us(2); 
	ADC_CLK=1; 
	ADC_DI=1;   //1 
	delay_us(2); 

	ADC_CLK=0;  //第二个脉冲下降沿，DI=1;
	delay_us(2); 
	ADC_DI=1;  //1 若为0则选择CH0 
	ADC_CLK=1; 
	delay_us(2); 

	ADC_CLK=0; //第三个脉冲下降沿，DI=1，选择 ADC0832 的CH1(1 1) 
	delay_us(2); 
	ADC_DI=1;   //已不关心 
	ADC_DO=1; //高阻 
	ADC_CLK=1; 
	delay_us(2); 

	for (i=0; i<8; i++)  
 	{ 
 	ADC_CLK=0; //第四个开始读数据 
 	delay_us(2);   
	data_c=(data_c<<1)|ADC_DO;//在每个脉冲的下降沿DO输出一位数据，最终ch为8位二进制数 
 	ADC_CLK=1; 
 	delay_us(2);   
 	} 

 	ADC_CS=1;//取消片选，一个转换周期结束 
 	return(data_c);//把转换结果返回 
 }