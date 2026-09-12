#include<p18f4580.h>
void  main()
{
// dec

//direction

TRISCbits.RC2 =  0;   // CCP1 set as O/P

//OTHER INITILAIZATION

//PWM
CCP1CON  =  0X0C;
PR2 =  11;    // 100% Vaalue

CCPR1L =  1;   // duty cyle valu


// TIMER2
T2CON = 0X02;   // PRESCALER VALUE IS 16
T2CONbits.TMR2ON =  1;   // Timer 2 ON

TMR2 = 0;

while(1)
{

} 



}