
#include<p18f4580.h>
#define RS PORTCbits.RC0
#define EN PORTCbits.RC1

void Delay(int a)
{
int i,j;
for(i = 0 ; i < a;i++)
for(j = 0 ; j < i ; j++);
}
void LCD_DATA(char val)
{
PORTD = val;
RS = 1; 
EN  = 1 ; 
Delay(100);
EN = 0 ;
}

void LCD_CMD(int val)
{
PORTD = val;
RS = 0; 
EN  = 1 ; 
Delay(100);
EN = 0 ;
}

void LCD_INIT()
{
LCD_CMD(0X0F);
LCD_CMD(0X01);
LCD_CMD(0X06);
LCD_CMD(0X38);
LCD_CMD(0X80);
}

void string(const rom char *s)
{

while(*s)
LCD_DATA(*s++);
}

void main()
{
//dec
int temp, i = 0;
int Arr[4];

// dire

TRISD = 0X00;
TRISCbits.RC0  =0;
TRISCbits.RC1  =0;      // SET AS O/P

// OTHRE
//ADC

ADCON0 =  0X03;     //ANO  = SET
ADCON1 = 0X0E;  //   ANO  ASCT AAS   ANG AND REM DIG
ADCON2 =  0X88;    //  RIGHT JUST & A TO D TIME (_0.25uSEC)



}