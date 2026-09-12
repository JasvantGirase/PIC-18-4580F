#include<p18f4580.h>
#define RS PORTCbits.RC0
#define E PORTCbits.RC1


void delay(int d);
void cmd(int a);
void data(char x);
char KEY();
//void str(const rom char *s);
void main()
{

char val;
//Direction
ADCON1=0x0f; // For using PORT-B
TRISB=0xf0;
TRISC=0x00;
TRISD=0x00;
//COMMADS
cmd(0x0F);
cmd(0x01);
cmd(0x38);
cmd(0x06);
cmd(0x80);

  while(1)
{
val = KEY();
data(val);
delay(200);

}


}


char KEY()
{

while(1)
{
 PORTB=0xFE;  // ROW 1 ZERO & OTHER ROW 1
 if(PORTB==0xEE)
{
while(PORTB==0xEE);
return '7';
//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0xDE)
{
while(PORTB==0xDE);
return '8';
//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0xBE)
{
while(PORTB==0xBE);
return '9';
//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0x7E)
{
while(PORTB==0x7E);
return '/';
//delay(200);
//cmd(0x01); //clear screen
}


PORTB=0xFD;    //ROW 2 ZERO & OTHER ROW 1
if(PORTB==0xED)
{
while(PORTB==0xED);
return '4';
//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0xDD)
{
while(PORTB==0xDD);
return '5';
//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0xBD)
{
while(PORTB==0xBD);
return '6';
//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0x7D)
{
while(PORTB==0x7D);
return '*';
//delay(200);
//cmd(0x01); //clear screen
}


PORTB=0xFB;      //ROW 3 ZERO & OTHER ROW 1

if(PORTB==0xEB)
{
while(PORTB==0xEB);
return '1';
//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0xDB)
{
while(PORTB==0xDB);
return '2';
//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0xBB)
{
while(PORTB==0xBB);
return '3';
//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0x7B)
{
while(PORTB==0x7B);
return '-';
//delay(200);
//cmd(0x01); //clear screen
}

PORTB=0xF7;
if(PORTB==0xE7)
{
while(PORTB==0xE7);
return 'C';

delay(200);
cmd(0x01); //clear screen
}
if(PORTB==0xD7)
{
while(PORTB==0xD7);
return '0';

//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0xB7)
{
while(PORTB==0xB7);
return '=';

//delay(200);
//cmd(0x01); //clear screen
}
if(PORTB==0x77)
{
while(PORTB==0x77);
return '+';
//delay(200);
//cmd(0x01); //clear screen
}

}
}
void cmd(int a)
{
 PORTD=a;
RS=0;
E=1;
delay(100);
E=0;
}
void data(char x)
{
 PORTD=x;
RS=1;
E=1;
delay(100);
E=0;
}
void str(const rom char *s)
{
while(*s)
data(*s++);
}
void delay(int d)
{
int i,j;
for(i=0;i<d;i++)
for(j=0;j<i;j++);
}