#include <p18f4580.h>

void Delay(int a)
{
    int i, j;

    for(i = 0; i < a; i++)
    {
        for(j = 0; j < i; j++);
    }
}

void main(void)
{
    // Declaration
    int Arr[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    int i = 0;

    // Direction
    TRISC = 0x00;       // PORTC all pins as output

    while(1)
    {
        for(i = 0; i < 10; i++)
        {
            PORTC = Arr[i];
            Delay(150);
        }
    }
}