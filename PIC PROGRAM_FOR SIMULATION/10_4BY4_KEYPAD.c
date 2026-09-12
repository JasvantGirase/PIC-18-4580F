#include <p18f4580.h>

#define RS PORTCbits.RC0
#define EN PORTCbits.RC1

void Delay(int a)
{
    int i, j;

    for(i = 0; i < a; i++)
        for(j = 0; j < i; j++);
}

void LCD_DATA(char val)
{
    PORTD = val;
    RS = 1;
    EN = 1;
    Delay(100);
    EN = 0;
}

void LCD_CMD(int val)
{
    PORTD = val;
    RS = 0;
    EN = 1;
    Delay(100);
    EN = 0;
}

void LCD_INIT(void)
{
    LCD_CMD(0x0F);
    LCD_CMD(0x01);
    LCD_CMD(0x06);
    LCD_CMD(0x38);
    LCD_CMD(0x80);
}

void main(void)
{
    TRISD = 0x00;          // LCD data pins output

    TRISCbits.RC0 = 0;     // RS output
    TRISCbits.RC1 = 0;     // EN output

    TRISB = 0xF0;          // RB7-RB4 input, RB3-RB0 output

    ADCON1 = 0x0F;         // Digital I/O

    LCD_INIT();

    while(1)
    {
        /* ================= ROW 1 ================= */
        PORTB = 0x0E;      // Row 1 LOW

        if((PORTB & 0xF0) == 0xE0)
        {
            LCD_DATA('7');

            while((PORTB & 0xF0) == 0xE0);
        }

        if((PORTB & 0xF0) == 0xD0)
        {
            LCD_DATA('8');

            while((PORTB & 0xF0) == 0xD0);
        }

        if((PORTB & 0xF0) == 0xB0)
        {
            LCD_DATA('9');

            while((PORTB & 0xF0) == 0xB0);
        }

        if((PORTB & 0xF0) == 0x70)
        {
            LCD_DATA('/');

            while((PORTB & 0xF0) == 0x70);
        }


        /* ================= ROW 2 ================= */
        PORTB = 0x0D;

        if((PORTB & 0xF0) == 0xE0)
        {
            LCD_DATA('4');

            while((PORTB & 0xF0) == 0xE0);
        }

        if((PORTB & 0xF0) == 0xD0)
        {
            LCD_DATA('5');

            while((PORTB & 0xF0) == 0xD0);
        }

        if((PORTB & 0xF0) == 0xB0)
        {
            LCD_DATA('6');

            while((PORTB & 0xF0) == 0xB0);
        }

        if((PORTB & 0xF0) == 0x70)
        {
            LCD_DATA('*');

            while((PORTB & 0xF0) == 0x70);
        }


        /* ================= ROW 3 ================= */
        PORTB = 0x0B;

        if((PORTB & 0xF0) == 0xE0)
        {
            LCD_DATA('1');

            while((PORTB & 0xF0) == 0xE0);
        }

        if((PORTB & 0xF0) == 0xD0)
        {
            LCD_DATA('2');

            while((PORTB & 0xF0) == 0xD0);
        }

        if((PORTB & 0xF0) == 0xB0)
        {
            LCD_DATA('3');

            while((PORTB & 0xF0) == 0xB0);
        }

        if((PORTB & 0xF0) == 0x70)
        {
            LCD_DATA('-');

            while((PORTB & 0xF0) == 0x70);
        }


        /* ================= ROW 4 ================= */
        PORTB = 0x07;

        if((PORTB & 0xF0) == 0xE0)
        {
            LCD_DATA('C');

            while((PORTB & 0xF0) == 0xE0);
        }

        if((PORTB & 0xF0) == 0xD0)
        {
            LCD_DATA('0');

            while((PORTB & 0xF0) == 0xD0);
        }

        if((PORTB & 0xF0) == 0xB0)
        {
            LCD_DATA('=');

            while((PORTB & 0xF0) == 0xB0);
        }

        if((PORTB & 0xF0) == 0x70)
        {
            LCD_DATA('+');

            while((PORTB & 0xF0) == 0x70);
        }
    }
}	