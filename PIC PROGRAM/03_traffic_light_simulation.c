#include <p18f4580.h>

#define RED     PORTCbits.RC3
#define GREEN   PORTCbits.RC7
#define YELLOW  PORTDbits.RD4

void Delay(int a)
{
    int i, j;

    for(i = 0; i <= a; i++)
    {
        for(j = 0; j <= i; j++)
        {
        }
    }
}

void main(void)
{
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC7 = 0;
    TRISDbits.TRISD4 = 0;

    while(1)
    {
        RED = 1;
        GREEN = 0;
        YELLOW = 0;
        Delay(200);

        RED = 0;
        GREEN = 1;
        YELLOW = 0;
        Delay(200);

        RED = 0;
        GREEN = 0;
        YELLOW = 1;
        Delay(80);
    }
}