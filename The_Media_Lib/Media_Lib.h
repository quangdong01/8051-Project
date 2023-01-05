#ifndef _MEDIA_LIB_H_
#define _MEDIA_LIB_h-

#include <regx52.h>
#define FREQ_OSC 11059200
#define BAUD_RATE 9600

// Ham Initialize truyen thong che do 1 8bit toc do baud cau boi timer 1
void Init_Uart();

// Ham gui du lieu tu vi dieu khien ra ngoai
void Uart_Write(unsigned char _data);

// Ham gui chuoi du lieu tu vi dieu khien ra ngoai vi 
void Uart_Write_Text(unsigned char *p);

// Ham kiem tra xem co phat hien du lieu ngoai gui vao khong
unsigned char Uart_Ready();

// Ham lay du lieu tu ngoai vao cho vi dieu khien 
unsigned char Uart_Read();


#endif