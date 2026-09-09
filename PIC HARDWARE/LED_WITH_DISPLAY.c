#include <p18f4580.h>

#define LED PORTBbits.RB1
#define SW  PORTCbits.RC3

void main(void)
{
    TRISBbits.RB1 = 0;    
    TRISCbits.RC3 = 1;   

    while(1)
    {
        if(SW == 0)
        {
            LED = 1;
        }
        else
        {
            LED = 0;
        }
    }
}