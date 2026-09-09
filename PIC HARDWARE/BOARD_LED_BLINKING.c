#include <p18f4580.h>

#define LED1 PORTBbits.RB1
#define LED2 PORTBbits.RB2
#define LED3 PORTBbits.RB3

void delay(int a)
{
    int i, j;

    for(i = 0; i < a; i++)
    {
        for(j = 0; j < i; j++);
    }
}

void main()
{
    TRISB = 0x00;
    ADCON1 = 0x0F;

    while(1)
    {
        LED1 = 1;
        LED2 = 1;
        LED3 = 1;

        delay(500);

        LED1 = 0;
        LED2 = 0;
        LED3 = 0;

        delay(500);
    }
}