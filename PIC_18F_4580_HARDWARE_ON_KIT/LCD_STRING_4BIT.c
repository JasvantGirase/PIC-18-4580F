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

void LCD_Cmd(char val)
{
    char Temp;

    RS = 0;

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

void string(const rom char *s)
{
    while(*s != '\0')
    {
        LCD_Data(*s++);
    }
}

void main(void)
{
    // Direction
    TRISD = 0x00;              // PORTD as output

    TRISCbits.RC0 = 0;         // RS as output
    TRISCbits.RC1 = 0;         // EN as output

    // LCD Initialization
    LCD_Cmd(0x02);             // 4-bit mode
    LCD_Cmd(0x28);             // 4-bit, 2 lines, 5x7 matrix
    LCD_Cmd(0x0C);             // Display ON, Cursor OFF
    LCD_Cmd(0x01);             // Clear display
    LCD_Cmd(0x06);             // Increment cursor
    LCD_Cmd(0x80);             // Cursor at row 1, column 1

    while(1)
    {
        LCD_Cmd(0x83);
        string("RICHY");

        LCD_Cmd(0xC3);
        string("RICH");

        Delay(500);

        LCD_Cmd(0x01);

        LCD_Cmd(0x83);
        string("FC Road");

        LCD_Cmd(0xC3);
        string("Pune");

        Delay(500);

        LCD_Cmd(0x01);
    }
}