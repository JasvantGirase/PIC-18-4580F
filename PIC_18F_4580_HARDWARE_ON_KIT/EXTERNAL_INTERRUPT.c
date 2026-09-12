#include<p18f4580.h>
#define LED PORTBbits.RB1
#define LED1 PORTDbits.RD2

void Delay(int a)
{
int i ,j;
for(i = 0 ; i < a ; i++)
for(j = 0 ; j < i ; j++);
}

void main(void)
{

//direction

TRISBbits.RB1= 0;
TRISDbits.RD2= 0;
TRISBbits.RB1= 1;

ADCON1 = 0X0F;

//INTERRUPT

RCONbits.IPEN = 0;
INTCON = 0X90;

INTCON2bits.INTEDG0 = 0;    //FALLING EDGE
LED = 0;   // OFF


while(1)
{
LED1 = 1;
Delay(250);
LED1 = 0;
Delay(250);
}

}
#pragma code ISR_Ext = 0x08
#pragma interrupt ISR_Ext  // noraml fun    -- isr

void ISR_Ext()
{
//while(INTCONbits.INT0IF == 0);   // WAIT FOR FLAG

LED = ~LED;
INTCONbits.INT0IF = 0;    // CLEAR FLAG N=BIT
}
