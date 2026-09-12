// Timer 0 --> 16 Bit

#include <p18f4580.h>

#define LED PORTCbits.RC3

void T0_Delay()       // Timer 0 Delay Function
{
    TMR0H = 0xFF;
    TMR0L = 0xB1;     // 20 ms

    T0CONbits.TMR0ON = 1;       // Timer Start

    while (INTCONbits.TMR0IF == 0);   // Wait for 20 ms

    INTCONbits.TMR0IF = 0;      // Clear the Flag Bit

    T0CONbits.TMR0ON = 0;       // Stop Timer0
}

void main(void)
{
    // Dec No
    // Dir

    TRISCbits.TRISC3 = 0;       // LED Set as O/P

    // Other Init
    T0CON = 0x07;

    while(1)
    {
        LED = 1;
    }
}