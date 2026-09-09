#include<p18f4580.h>
#define LED PORTDbits.RD1
#define SW PORTCbits.RC2
void main(void)
{
	TRISCbits.RC2=1;
	TRISDbits.RD1=0;
	while(1)
	{
		if(SW==0)
		{
			LED=1;
		}
		else
		{
			LED=0;
		}
	}
}				