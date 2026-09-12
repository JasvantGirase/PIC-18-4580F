#include<p18f4580.h>
#define RS PORTCbits.RC0
#define EN PORTCbits.RC1

void Delay(int a)
{
int i,j;
for(i=0; i<a; i++)
 for(j=0 ; j<i; j++);
}

void LCD_DATA(char a)
{
PORTD = a;
RS = 1;
EN = 1;
Delay(100);
EN = 0;

}

void LCD_CMD(int a)
{
PORTD = a;
RS = 0;
EN = 1;
Delay(100);
EN = 0;
}

void String(const rom char *s)
{
while(*s)
 LCD_DATA(*s++);
}

void main(void)
{

// Dir
TRISD = 0x00;
TRISCbits.RC0 = 0;
TRISCbits.RC1 = 0;

LCD_CMD(0x0F);
LCD_CMD(0x01);
LCD_CMD(0x06);
LCD_CMD(0x38);
LCD_CMD(0x80);

while(1)
{
LCD_CMD(0x83);
String("NAME");
LCD_CMD(0xC3);
String("SURNAME");

Delay(1000);
LCD_CMD(0x01);

LCD_CMD(0x83);
String("DATA");
LCD_CMD(0xC3);
String("PUNE");


Delay(1000);
LCD_CMD(0x01);
}
}