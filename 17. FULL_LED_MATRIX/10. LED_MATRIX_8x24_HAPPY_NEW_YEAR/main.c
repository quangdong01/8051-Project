#include <regx52.h>

unsigned char code Cot[]= { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

unsigned char code Data[] = {
														  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
															0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
															0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
															0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
	                            0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
															0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
															0x80, 0x80, 0xF7, 0xF7, 0x80, 0x80,                 // H    
															0xFF,
															0xC0, 0x80, 0xB7, 0xB7, 0x80, 0xC0,                 // A
															0xFF,
	                            0x80, 0x80, 0xBB, 0xBB, 0x83, 0xC7,                 // P
															0xFF,
		                          0x80, 0x80, 0xBB, 0xBB, 0x83, 0xC7,                 // P
															0xFF,
															0x8F, 0x87, 0xF0, 0xF0, 0x87, 0x8F,                 // Y
															0xFF, 0xFF, 0xFF,
															0x80, 0x80, 0xCF, 0xE7, 0xF3, 0x80, 0x80,           // N
															0xFF,
															0x80, 0x80, 0xB6, 0xB6, 0xBE, 0xBE,                 // E
															0xFF,
															0x80, 0x80, 0xF9, 0xF3, 0xF9, 0x80, 0x80,           // W
															0xFF, 0xFF, 0xFF,
															0x8F, 0x87, 0xF0, 0xF0, 0x87, 0x8F,                 // Y
															0xFF,
															0x80, 0x80, 0xB6, 0xB6, 0xBE, 0xBE,                 // E
															0xFF,
															0xC0, 0x80, 0xB7, 0xB7, 0x80, 0xC0,                 // A
															0xFF, 
															0x80, 0x80, 0xB3, 0xB1, 0x84, 0xCE,                 // R
															0xFF, 0xFF, 0xFF,
															0xDC, 0x98, 0xBA, 0xB6, 0x86, 0xCE,                 // 2
															0xFF,
															0xC1, 0x80, 0xAE, 0xB6, 0x80, 0xC1,                 // 0
															0xFF,
															0xDC, 0x98, 0xBA, 0xB6, 0x86, 0xCE,                 // 2
															0xFF,
															0xDC, 0x98, 0xBA, 0xB6, 0x86, 0xCE,                 // 2
															0xFF,
															0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
															0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
	                            0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
															0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
															0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
															0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     // Space 
														};
sbit SH_CP = P2^0;
sbit DS = P2^1;
sbit ST_CP = P2^3;
														
#define Port P0 					
														
void Sleep_ms(unsigned int t)
{
	unsigned char i, j;
	for(i = 0; i < t; i++)
	{
		for(j = 0; j < 123; j++);
	}
}


void Send_Data(unsigned char _data)
{
	unsigned char i;
	for(i = 0;i < 8; i++)
	{
		DS = _data & (0x80 >> i);
		SH_CP = 0;
		SH_CP = 1;
	}
	ST_CP = 0;
	ST_CP = 1;
}


void main()
{
	unsigned char i, j, k;
	while(1)
	{
		for(i = 0; i < 200; i++)
		{
			for(k = 0; k < 5; k++)
			{
				for(j = 0; j < 8; j++)
				{
					Send_Data(Data[i+j]);
					Send_Data(Data[i+j+8]);
					Port = Cot[j];
					Sleep_ms(1);
					Port = 0x00;
				}
			}
		}
	}
}








































