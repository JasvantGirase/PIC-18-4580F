#include<p18f4580.h>
#define SW PORTCbits.RC0
#define LED PORTDbits.RD0
void main()
{
	//dec-no
	//direc
	TRISCbits.RC0=1;
	TRISDbits.RD0=0;
	//init-no
	//operation
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