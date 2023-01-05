#include <regx52.h>


// Delay trong ? Milisecond
void Sleep_ms(unsigned int t)
{
	unsigned int i, j;
	for(i = 0; i < t; i++)
		{
			for(j = 0; j < 123; j++);
		}
}
void main()
{
	while(1)
	{
		Sleep_ms(100);
		P2_0 = !P2_0;
	}
}
