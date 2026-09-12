#include <p18f4580.h>
//#define led PORTDbits.RD0
void delay(int);
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
    for(j=0;j<123;j++);
}

//UART TRANSMIT 

void main()
{
    char str[]="TECHNO_\r\n";
TRISCbits.RC6=0; //TX
TRISCbits.RC7=1; //RX

//UART unit
TXSTA=0x24; //Async mode, transmit enable, 8bit
RCSTA=0x90; //Recieve enable, RX,TX pin configure
SPBRG=129; //Generate the 9600 Baud Rate

while(1)
{
    int i;
    for(i=0;str[i]!='\0';i++)
{
TXREG=str[i]; //load value in buffer reg
while(PIR1bits.TXIF==0); //waiting for transmission, continuous transmission
// while(PIR1bits.TXIF==1) one-time transmission
PIR1bits.TXIF=0;
delay(1000);
}

}
}