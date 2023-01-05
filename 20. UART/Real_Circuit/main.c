#include <regx52.h>

sbit SHCP = P2^0;
sbit DS = P2^1;
sbit STCP = P2^3;

// Ham gui du lieu tu vi dieu khien ra cho 74HC595

void Send_Data(unsigned char _data)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		DS = _data & (0x80 >> i);
		SHCP = 0;
		SHCP = 1;
	}
	STCP = 0;
	STCP = 1;
}

unsigned char code Cot[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
	
unsigned char code Text[26][8] = {
                              0xFF, 0xC0, 0x80, 0xB7, 0xB7, 0x80, 0xC0, 0xFF,     // A
															0xFF, 0x80, 0x80, 0xB6, 0xB6, 0x80, 0xC9, 0xFF,     // B 
															0xFF, 0xC1, 0x80, 0xBE, 0xBE, 0x9C, 0xDD, 0xFF,     // C
															0xFF, 0x80, 0x80, 0xBE, 0xBE, 0x80, 0xC1, 0xFF,     // D
															0xFF, 0x80, 0x80, 0xB6, 0xB6, 0xBE, 0xBE, 0xFF,     // E
															0xFF, 0x80, 0x80, 0xB7, 0xB7, 0xBF, 0xBF, 0xFF,     // F
															0xFF, 0xC1, 0x80, 0xBE, 0xBA, 0x98, 0xD9, 0xFF,     // G
															0xFF, 0x80, 0x80, 0xF7, 0xF7, 0x80, 0x80, 0xFF,     // H
															0xFF, 0xFF, 0xBE, 0x80, 0x80, 0xBE, 0xFF, 0xFF,     // I
															0xFF, 0xF9, 0xF8, 0xBE, 0x80, 0x81, 0xBF, 0xFF,     // J
															0xFF, 0x80, 0x80, 0xE3, 0xC9, 0x9C, 0xBE, 0xFF,     // K
															0xFF, 0x80, 0x80, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF,     // L
   		                        0xFF, 0x80, 0x80, 0xCF, 0xE7, 0xCF, 0x80, 0x80,     // M
															0xFF, 0x80, 0x80, 0xCF, 0xE7, 0xF3, 0x80, 0x80,     // N
															0xFF, 0xC1, 0x80, 0xBE, 0xBE, 0x80, 0xC1, 0xFF,     // O
	                      	    0xFF, 0x80, 0x80, 0xBB, 0xBB, 0x83, 0xC7, 0xFF,     // P
															0xFF, 0xC3, 0x81, 0xBD, 0xBD, 0x80, 0xC2, 0xFF,     // Q
	                            0xFF, 0x80, 0x80, 0xB3, 0xB1, 0x84, 0xCE, 0xFF,     // R
															0xFF, 0xCD, 0x84, 0xB6, 0xB6, 0x90, 0xD9, 0xFF,     // S
	                        		0xFF, 0x9F, 0xBF, 0x80, 0x80, 0xBF, 0x9F, 0xFF,     // T
															0xFF, 0x81, 0x80, 0xFE, 0xFE, 0x80, 0x80, 0xFF,     // U
															0xFF, 0x83, 0x81, 0xFC, 0xFC, 0x81, 0x83, 0xFF,     // V
															0xFF, 0x80, 0x80, 0xF9, 0xF3, 0xF9, 0x80, 0x80,     // W
															0xFF, 0x9C, 0x88, 0xE3, 0xF7, 0xE3, 0x88, 0x9C,     // X
															0xFF, 0x8F, 0x87, 0xF0, 0xF0, 0x87, 0x8F, 0xFF,     // Y
															0xFF, 0xBC, 0xB8, 0xB2, 0xA6, 0x8E, 0x9E, 0xFF,     // Z
                              };
	
unsigned char code Number[10][8] = {
	                            0xFF, 0xC1, 0x80, 0xAE, 0xB6, 0x80, 0xC1, 0xFF,     // 0
	                            0xFF, 0xFE, 0xEE, 0x80, 0x80, 0xFE, 0xFE, 0xFF,     // 1
															0xFF, 0xDC, 0x98, 0xBA, 0xB6, 0x86, 0xCE, 0xFF,     // 2
															0xFF, 0xDD, 0x9C, 0xB6, 0xB6, 0x80, 0xC9, 0xFF,     // 3
															0xFF, 0xF3, 0xEB, 0xDB, 0x80, 0x80, 0xFB, 0xFF,     // 4
															0xFF, 0x8D, 0x8C, 0xAE, 0xAE, 0xA0, 0xB1, 0xFF,     // 5
															0xFF, 0xC1, 0x80, 0xB6, 0xB6, 0x90, 0xD9, 0xFF,     // 6
															0xFF, 0x9F, 0x9F, 0xB8, 0xA0, 0x87, 0x9F, 0xFF,     // 7
															0xFF, 0xC9, 0x80, 0xB6, 0xB6, 0x80, 0xC9, 0xFF,     // 8
															0xFF, 0xCD, 0x84, 0xB6, 0xB6, 0x80, 0xC1, 0xFF,     // 9
                                   };
	 
// Dung chuong trinh trong ? milisecond
void Sleep_ms(unsigned int t)
{
	unsigned int i, j;
	for(i = 0; i < t; i++)
	{
		for(j = 0; j <123; j++);
	}
}

// Cau hinh cho truyen thong noi tiep 

void Uart_Init()
{
	// Chon timer1 che do 8bit tu nap lai 
	TMOD &= 0x0F;
	TMOD |= 0x20;
	
	// Chon che do truyen not tiep 8bit toc do baud duoc cai boi timer1 
	SM0 = 0;
	SM1 = 1;
	
	// Chon che do nhan di lieu 
	REN = 1;
	
	// Nap thanh ghi TH de cai dat toc do Baud
	TH1 = 0xFD;
	
	// Khoi dong timer1;
	TR1 = 1;
	
	// Gan TI = 1 de thong bao san sang truyen du lieu di
	TI = 1;
	
}

// Ham gui du lieu tu vi dieu khien ra cho thiet bi ngoai 

void Uart_Write(unsigned char _data)
{
	while(TI == 0);
	TI = 0;
	SBUF = _data;
}

// Ham gui chuoi ki tu
void Uart_Write_Text(unsigned char *p)
{
	unsigned char i = 0;
	while(p[i] != 0)
	{
		Uart_Write(p[i]);
		i++;
	}
}

// Ham kiem tra xem co du lieu duoc gui tu ngoai vao trong vi dieu khien khong 
unsigned char Uart_Ready()
{
	return RI;
}

// Ham lay du lieu tu ben ngoai vao cho vi dieu khien 
unsigned char Uart_Read()
{
	RI = 0;
	return SBUF;
}

void Uart_Read_Matrix()
{
	while(1)
	{
		unsigned char i, _data;
		if(Uart_Ready())
		{
			_data = Uart_Read();
			if((_data >= 48) && (_data <= 57))
			{
				while(Uart_Ready() == 0)
				{
					for(i = 0; i < 8; i++)
					{
						Send_Data(Number[_data - 48][i]);
						P0 = Cot[i];
						Sleep_ms(1);
						P0 = 0x00;
					}
				}
			}
			else if((_data >= 65) && (_data <= 90))
			{
				while(Uart_Ready() == 0)
				{
					for(i = 0; i < 8; i++)
					{
						Send_Data(Text[_data - 65][i]);
						P0 = Cot[i];
						Sleep_ms(1);
						P0 = 0x00;
					}
				}
			}
			else if((_data >= 97) &&(_data <= 122))
			{
				while(Uart_Ready() == 0)
				{
					for(i = 0; i < 8; i++)
					{
						Send_Data(Text[_data - 97][i]);
						P0 = Cot[i];
						Sleep_ms(1);
						P0 = 0x00;
					}
				}
			}
		}
	}
}


void main()
{
	Uart_Init();
	Uart_Read_Matrix();
	
}























