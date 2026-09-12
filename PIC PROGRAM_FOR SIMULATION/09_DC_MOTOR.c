#include<p18f4580.h>
#define IN1 PORTCbits.RC0
#define IN2 PORTCbits.RC1
#define EN1 PORTCbits.RC2

void main()
{
	//dec-no
	//dir
	TRISC=0x00;
	while(1)
	{
		EN1 = 1;//enable the motor 1
		IN1 = 0;
		IN2 = 1;//CLK wise rotation 
	}
}		