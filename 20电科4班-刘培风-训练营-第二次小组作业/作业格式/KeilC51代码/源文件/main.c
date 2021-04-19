#include <REGX52.H>
#include "Beep.h"
#include "delay.h"

unsigned char code  leddata[] = 
{              0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e
};

int main()
{
	int i=0;
	while(1)
	{
		P1=0xFE;//1111 1110
		Delay(100);
		P1=0xFD;//1111 1101
		Delay(100);
		P1=0xFB;//1111 1011
		Delay(100);
		P1=0xF7;//1111 0111
		Delay(100);
		P1=0xEF ;//1110 1111
		Delay(100);
		P1=0xDF  ;//1101 1111
		Delay(100);
		P1=0xBF  ;//1011 1111
		Delay(100);
		P1=0x7F  ;//0111 1111
		Delay(100);
		beep=~beep;
		i++;
		if(i>=10)
		{
			i=0;
		}
		else 
		{
			P2_0=0;
			P2_1=1;
			P0=leddata[i];
			Delay(1000);
			P2_1=0;
			P2_0=0;
		}
		Delay(500);
	}	
	return 0;
}

