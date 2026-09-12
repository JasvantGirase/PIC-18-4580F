	#include <p18f4580.h>

void main(void)
{
    TRISC = 0x00;

    while(1)
    {
        PORTC = 0xFF;
    }
}