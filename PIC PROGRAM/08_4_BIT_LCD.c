#include <p18f4580.h>

#define RS PORTCbits.RC0
#define EN PORTCbits.RC1

void Delay(int a)
{
    int i, j;

    for(i = 0; i < a; i++)
        for(j = 0; j < i; j++);
}

void LCD_Data(char val)
{
    char Temp;

    RS = 1;

    // Send upper nibble
    Temp = val & 0xF0;
    PORTD = Temp;
    EN = 1;
    Delay(50);
    EN = 0;

    // Send lower nibble
    Temp = val & 0x0F;
    Temp = Temp << 4;
    PORTD = Temp;
    EN = 1;
    Delay(50);
    EN = 0;
}