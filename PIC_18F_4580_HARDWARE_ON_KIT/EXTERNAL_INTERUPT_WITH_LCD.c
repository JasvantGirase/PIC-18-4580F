#include<p18F4580.h>
#define RS PORTCbits.RC0
#define EN PORTCbits.RC1
#define LED PORTBbits.RB1

void delay(int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<i;j++);
}
void LCD_cmd(int val)
{
PORTD=val;
RS=0;
EN=1;
delay(50);
EN=0;
}
void LCD_data(char val)
{
PORTD=val;
RS=1;
EN=1;
delay(50);
EN=0;
}
 void String(const rom char *s)
{
while(*s)
LCD_data(*s++);
}
 void LCD_Init()
{
LCD_cmd(0X0F);//LCD on and Cursor Blink
LCD_cmd(0X01);//Clear Screen
LCD_cmd(0X06);//INC the Cursor
LCD_cmd(0X38);//Active 2 line & 5X8 matrix
LCD_cmd(0X80);//1st row & 1st Column
}
int i=0;// Global Dec 
void main()
{
//DEC-->No

//DIR-->
TRISC=0x00;//Set as output
TRISD=0x00;//Set as output
ADCON1=0X0F;//ADC enable for rbo pin 

//LCD Init
 LCD_Init();

//Interrupt Init 
RCONbits.IPEN=0;//Priority disabled
 INTCON = 0X90;
INTCON2bits.INTEDG0=0;//Rising Edge

//Operation-->
while(1)
{
String("Main_Code");
LCD_cmd(0X0C);
String("Evecution");
delay(200);
LCD_cmd(0X01);
LCD_cmd(0X80);
}
}
//Interrupt ISR function
#pragma code EXT_ISR=0X08//Interrupt set as high
#pragma interrupt EXT_ISR // ISR 
  void EXT_ISR()
{
while(INTCONbits.INT0IF==0);//Wait until the interrupt is occured
LCD_cmd(0X01);
String("INTERRUPT ON");
for(i=0;i<5;i++)
{
LED=1;
delay(100);
LED=0;
delay(100);
}
delay(100);
LCD_cmd(0X01);
LCD_cmd(0X80);
INTCONbits.INT0IF=0;//Flag bit zero

}