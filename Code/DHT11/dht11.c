#include "dht11.h"
#include "lcd.h"
#include "delay.h"

void DHT11_start()	
{
	Temp_data=1;
	DHT11_delay_us(2);
	Temp_data=0;
	DHT11_delay_ms(20);
	Temp_data=1;
	DHT11_delay_us(13);
}

uchar DHT11_rec_byte()
{
	uchar i,dat;
	for(i=0;i<8;i++)
	{
			while(!Temp_data);
		  DHT11_delay_us(8);
			dat<<=1;
			if(Temp_data==1)
			{
				dat+=1;
			}
			while(Temp_data);
	}
	return dat;
}

void DHT11_receive()
{
	uint R_H,R_L,T_H,T_L;
	uchar RH,RL,TH,TL,revise;
	DHT11_start();
	Temp_data=1;
	if(Temp_data==0)
	{
	while(Temp_data==0);  
        	DHT11_delay_us(40);  
					R_H=DHT11_rec_byte();   
					R_L=DHT11_rec_byte();   
					T_H=DHT11_rec_byte();   
					T_L=DHT11_rec_byte();   
					revise=DHT11_rec_byte(); 
					DHT11_delay_us(25);    
					if((R_H+R_L+T_H+T_L)==revise)     
      	  {
        		    RH=R_H;
         		    RL=R_L;
         	 	    TH=T_H;
          		  TL=T_L;	
          } 
      	  rec_dat[0]=RH;
      	  rec_dat[1]=RL;
      	  rec_dat[2]=TH;
      	  rec_dat[3]=TL;
	}
}