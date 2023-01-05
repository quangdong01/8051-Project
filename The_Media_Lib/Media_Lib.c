#include "Media_Lib.h"

// Neu Tan so thach anh khac 11059200 thi thong bao thay doi thach anh 
#if(FREQ_OSC != 11059200)
	error "Chi ap dung voi tan so thach anh 11059200"
#endif
	
// Ham Initialize truyen thong che do 1 8bit toc do baud cau boi timer 1
void Init_Uart()
{
	// Thiet lap chon timer 1 che do 8bit tu nap lai 
	TMOD &= 0x0F;
	TMOD |= 0x20;
	
	// Chon che do truyen 1 8bit toc do baud cai boi timer 1
	SM0 = 0;
	SM1 = 1;
	
	// Thiet lap che do Baud
	#if(BAUD_RATE == 9600)
		TH1 = 0xFD;
	#elif(BAUD_RATE == 2400)
		TH1 = 0xF4;
	#elif(BAUD_RATE == 1200)
		TH1 = 0xE8;
	#elif(BAUD_RATR == 19200)
		PCON |= 0x80;
		TH1 = 0xFD;
	#else
		error"BAUD_RATE Chi Nam Trong Cac Gia Tri 9600, 2400, 1200, 19200"
	#endif
	
	// Thiet Lap Che Do Nhan Du Lieu 
	REN = 1;
	// Thiet Lap Co Truyen = 1
	TI = 1;
	// Khoi Dong Timer 1;
	TR1 = 1;
}

// Ham gui du lieu tu vi dieu khien ra ngoai
void Uart_Write(unsigned char _data)
{
	while(TI == 0);
	TI = 0;
	SBUF = _data;
}

// Ham gui chuoi du lieu tu vi dieu khien ra ngoai vi 
void Uart_Write_Text(unsigned char *p)
{
	unsigned char i = 0;
	while(p[i] != 0)
	{
		Uart_Write(p[i]);
		i++;
	}
}

// Ham kiem tra xem co phat hien du lieu ngoai gui vao khong
unsigned char Uart_Ready()
{
	return RI;
}

// Ham lay du lieu tu ngoai vao cho vi dieu khien 
unsigned char Uart_Read()
{
	RI = 0;
	return SBUF;
}
