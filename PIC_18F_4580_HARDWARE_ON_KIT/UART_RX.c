#include<p18f4580.h>
#define LED PORTBbits.RB1
void Delay(int a)
{
int i,j;
for(i=0 ; i<a ; i++)
 for(j=0 ; j<i ; j++);
}

void main()
{
// Dec --> 
char RX_var;

// Dir
TRISCbits.RC6 = 0; // TX Set as O/P
TRISCbits.RC7 = 1; // Rx Set as I/P
TRISBbits.RB1 = 0; // LED Set as O/P
ADCON1=0X0F;

// Other Init
TXSTA = 0x24;
RCSTA = 0x90;
SPBRG = 129;
while(1)
{
while(PIR1bits.RCIF == 0); // wait For Rec
RX_var = RCREG; // Store Data Reg to Var

if(RX_var == '1')
{
LED = 1; // LED ON
}
else if(RX_var == '0')
{
LED = 0; // LED OFF
}
}
}