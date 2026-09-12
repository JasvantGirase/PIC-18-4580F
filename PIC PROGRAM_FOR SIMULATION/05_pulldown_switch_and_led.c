#include<p18f4580.h>
#define SW PORTCbits.RC7
#define LED PORTDbits.RD7
void main()
{
	//dec-no
	//direc
	TRISCbits.RC7=1;
	TRISDbits.RD7=0;
	//init-no
	//operation
	while(1)
	{
		if(SW==1)
		{
			LED=1;
		}	
		else
		{
			LED=0;
		}
	}
}