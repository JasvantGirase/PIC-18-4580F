#include<p18f4580.h>
 void delay(int a)
{
int i ,j ;
for(i =  0; i < a ; i++)
for(j  =  0 ;  j < i ; j ++);
}
void main()
{
//dec
char data[] =  "Pune_12\r\n";
int i = 0;
//direction
TRISCbits.RC6 =  1;   //SET AS TX
TRISCbits.RC7 =  0;   //SET AS RC
//OTHER INITILAIZATION
TXSTA = 0X24;
RCSTA  =  0X90;
SPBRG = 129;

while(1)
{
for(i =  0 ; data[i]  != '\0' ; i++)
{
TXREG = data[i];
while(PIR1bits.TXIF == 0 );     // WIAT FOR TX
 PIR1bits.TXIF = 0;    // Flag bit clear
}
delay(250);
}
}