#include<p18f4580.h>
#define LED PORTBbits.RB1

void T0_Delay()     /// timer 0  delay fun 20milse
{
TMR0H  = 0XFF;
TMR0L = 0XB1;     // 20ms
T0CONbits.TMR0ON = 1;   // TIMER START
while(INTCONbits.TMR0IF == 0) ;    /// wait for 20ms
INTCONbits.TMR0IF = 0;    // Clear the flag bit 
T0CONbits.TMR0ON = 0;   // Stop the timer0 
}

void  main(void)
{

//  Declaration


//diirection

TRISBbits.RB1  =  0 ;   /// LED SET   AS    O / P
ADCON1 = 0X0F;
//OTHER INI

T0CON = 0X07;

 while(1)
{
int i  ; 
    LED =  1;
   for( i = 0 ; i < 50 ; i ++)
 {
    T0_Delay();
 }
     LED = 0;
     for( i = 0 ; i < 50 ; i ++)
 {
    T0_Delay();
 }

}
}