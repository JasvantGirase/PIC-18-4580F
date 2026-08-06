	#include <p18f4580.h>
	
	void Delay(void)
	{
	    int i = 0;
	    int j = 0;
	
	    for(i = 0; i <= 255; i++)
	    {
	        for(j = 0; j <= i; j++)
	        {
	        }
	    }
	}
	
	void main(void)
	{
	    TRISDbits.RD2 = 0;
	
	    while(1)
	    {
	        PORTDbits.RD2 = 1;
	        Delay();
	
	        PORTDbits.RD2 = 0;
	        Delay();
	    }
	}
	