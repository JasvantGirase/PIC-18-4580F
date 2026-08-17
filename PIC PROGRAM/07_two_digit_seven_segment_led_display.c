#include <p18f4580.h>

#define S1 PORTDbits.RD0
#define S2 PORTDbits.RD1

void Delay(int a)
{
    int i,j;

    for(i=0;i<a;i++)
        for(j=0;j<255;j++);
}

void main(void)
{
    int Arr[10] = {
        0X3F, 0X06, 0X5B, 0X4F, 0X66,
        0X6D, 0X7D, 0X07, 0X7F, 0X6F
    };

    int temp;

    TRISC = 0X00;

    TRISDbits.RD0 = 0;
    TRISDbits.RD1 = 0;

    while(1)
    {
        // Tens digit = 7
        temp = 73 / 10;

        S1 = 0;
        S2 = 1;

        PORTC = Arr[temp];

        Delay(50);

        // Units digit = 3
        temp = 73 % 10;

        S1 = 1;
        S2 = 0;

        PORTC = Arr[temp];

        Delay(50);
    }
}
			