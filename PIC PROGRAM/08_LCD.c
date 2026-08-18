#include<p18f4580.h>
#define RS PORTCbits.RC0
#define RW PORTCbits.RC1
#define EN PORTCbits.RC2

void Delay(int a)
{
	int i,j;
	for (i=0;i<a;i++)
	for (j=0;j<i;j++);
}
void LCD_Data(char val)
{
	PORTD = val;
	RS = 1;
	RW = 0;
	EN = 1;
	Delay(100);
	EN = 0;
}
void LCD_Cmd(int val)
{
	PORTD = val;
	RS = 0;
	RW = 0;
	EN = 1;
	Delay(100);
	EN = 0;
}
void main(void)
{
	//Dec --> No
	//Dir
	TRISD= 0x00;//LCD Data Pins Set as o/p
	TRISCbits.RC0 = 0; //RS set as op
	TRISCbits.RC1 = 0; //RW set as op
	TRISCbits.RC2 = 0; //EN set as op
	
	// Other Init
LCD_Cmd(0x0F); // LCD On & Cursor Blink
LCD_Cmd(0x01); // Clear the screen
LCD_Cmd(0x06); // Inc The Cursor
LCD_Cmd(0x38); // Active 2 Lines & 5x7 Matrix
LCD_Cmd(0x80); // Cursor -> R1 & CO

while(1)
{
	LCD_Data('@'); //Sending '@' to LCD Data Fun
	Delay(250);
}
}