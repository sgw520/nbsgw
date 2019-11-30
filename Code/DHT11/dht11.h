#ifndef DHT11_H_
#define DHT11_H_
#include <reg51.h>
//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif
/**********************************
PIN口定义
**********************************/
sbit Temp_data=P2^6;  //使用P2^6作为DHT11的数据总线传输端口
/**********************************
函数声明
**********************************/
void DHT11_start();
uchar DHT11_rec_byte();
void DHT11_receive();
#endif