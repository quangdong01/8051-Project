#include <regx52.h>


sbit SH_CP = P2^0;
sbit DS = P2^1;
sbit ST_CP = P2^3;



unsigned char code Cot[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned char code Data[] = { 	
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xC3, 0x81, 0x7E, 0x7E, 0x81, 0xC3, 0xFF,  // So 0
													   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xDE, 0xBE, 0x00, 0xFE, 0xFE, 0xFF,  // So 1 
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
                             0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
													 	 0xFF, 0x9E, 0x3C, 0x78, 0x72, 0x26, 0x8E, 0xFF,  // So 2
													 	 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0x24, 0x24, 0x24, 0x24, 0x00, 0x00, 0xFF,  // So 3
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xF3, 0xE3, 0xC3, 0x93, 0x33, 0x00, 0x00, 0xFF,  // So 4	
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0x04, 0x04, 0x24, 0x24, 0x20, 0x20, 0xFF,  // So 5
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
                             0xFF, 0x00, 0x00, 0x66, 0x66, 0x20, 0x20, 0xFF,  // So 6
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0x3F, 0x3C, 0x38, 0x31, 0x03, 0x07, 0xFF,  // So 7
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0xFF,  // So 8 
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,   // Delay
														 0xFF, 0x04, 0x04, 0x24, 0x24, 0x00, 0x00, 0xFF,  // So 9 
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
	                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Delay
														};

														
void Sleep_ms(unsigned int t)
{
	unsigned int i,j;
	for(i = 0; i < t; i++)
	{
		for(j = 0; j < 123; j++);
	}
}


void SEND_DATA(unsigned char a)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		DS = a & (0x80 >> i);
		SH_CP = 0;
		SH_CP = 1;
	}
	ST_CP = 0;
	ST_CP = 1;
}

void MATRIX_8_32()
{
	while(1)
	{
		unsigned int i,j,k;
		for(i = 0; i < 400; i++)
		{
			for(k = 0; k < 5; k++)
			{
				for(j = 0; j < 8; j++)
				{
					SEND_DATA(Data[i+j+0]);
					SEND_DATA(Data[i+j+8]);
					SEND_DATA(Data[i+j+16]);
					SEND_DATA(Data[i+j+24]);
					
					P0 = Cot[j];
					Sleep_ms(1);
					P0 = 0x00;
					
				}
			}
		}
	}
}


void main()
{
	P0 = 0x00;
	MATRIX_8_32();
	
}





























