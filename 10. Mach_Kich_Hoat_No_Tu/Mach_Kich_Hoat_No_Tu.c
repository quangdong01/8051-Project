#include "Mach_Kich_Hoat_No_Tu.h"
unsigned char code LED[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


void Sleep_ms(unsigned int t)
{
	unsigned int a,b;
	for(a = 0; a < t; a++)
	{
		for(b = 0; b < 123; b++);
	}
}

void Kich_Hoat()
{
	if( Button == 0)
	{
		signed char i, j;
		for(i = 1; i >= 0; i--)
		{
			LED1 = LED[i];
			for(j = 9; j>=0 ; j--)
			{
				LED2 = LED[j];
				Sleep_ms(1000);
			}
		}	
		Activate = 0;
		for(i = 1; i >= 0; i--)
		{
			LED1 = LED[i];
			if(i == 1)
			{
				for(j = 0; j >= 0; j--)
				{
					LED2 = LED[j];
					Sleep_ms(1000);
				}
			}
			else
			{
				for(j = 9; j>=0 ; j--)
					{
						LED2 = LED[j];
						Sleep_ms(1000);
					}
			}
		}	
		Activate = 1;
	}
}