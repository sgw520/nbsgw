#include "delay.h"
#include "dht11.h"
//延时us   --2*n+5us
void DHT11_delay_us(uchar n)
{
    	while(--n);
}

//延时ms
void DHT11_delay_ms(uint z)
{
   	uint i,j;
 	for(i=z;i>0;i--)
     	for(j=110;j>0;j--);
}

void delay_us(uchar i)
{
	while(i--);
}