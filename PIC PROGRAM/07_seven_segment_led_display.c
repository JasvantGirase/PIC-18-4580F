#include<p18f4580.h>
void main()
{
//Dec-->No
//Dir
TRISC = 0x00;//Set as o/p
while(1)
{
PORTC = 0x66;
}
}