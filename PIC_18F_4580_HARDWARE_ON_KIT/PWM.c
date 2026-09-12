#include<p18f4580.h>
#define LED PORTCbits.RC2
void delay();
void main()
{
int i;
 //Dirction 
  TRISCbits.RC2=0; // RC2 as O/p
CCP1CON=0x0C ; //10%
//CCP1CON=0x2C ; //50% 
T2CON=0x02;
 PR2=1023;

T2CONbits.TMR2ON=1;

  while(1)
{
for(i=0;i<250;i++)
{
 CCPR1L=i;
delay(); 
}
for(i=250;i>0;i--)
{
 CCPR1L=i;
delay(); 
}
}
}

void delay()
{
int i,j;
for(i=0;i<60;i++)
for(j=0;j<i;j++);
}