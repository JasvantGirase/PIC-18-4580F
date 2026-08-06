#include <p18f4580.h>

void Delay(int a)
{
    volatile int i, j;

    for(i = 0; i < a; i++)
        for(j = 0; j < 500; j++);
}

void main(void)
{
    // ON : Top -> Bottom
    int LED_ON[8] =
    {
        0x80,
        0xC0,
        0xE0,
        0xF0,
        0xF8,
        0xFC,
        0xFE,
        0xFF
    };

    // OFF : Top -> Bottom
    int LED_OFF[8] =
    {
        0x7F,
        0x3F,
        0x1F,
        0x0F,
        0x07,
        0x03,
        0x01,
        0x00
    };

    int i;

    TRISC = 0x00;
    PORTC = 0x00;

    while(1)
    {
        // LEDs ON (Top -> Bottom)
        for(i = 0; i < 8; i++)
        {
            PORTC = LED_ON[i];
            Delay(200);
        }

        Delay(500);

        // LEDs OFF (Top -> Bottom)
        for(i = 0; i < 8; i++)
        {
            PORTC = LED_OFF[i];
            Delay(200);
        }

        Delay(500);
    }
}