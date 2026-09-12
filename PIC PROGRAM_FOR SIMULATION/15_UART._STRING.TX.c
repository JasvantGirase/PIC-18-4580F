#include<p18f4580.h>

void Delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<i;j++);
}

void main()
{
    //Dec -->
    char Data[]="Pune_12\r\n";
    int i=0;
    
    //Dir
    TRISCbits.RC6=0;//Set as TX
    TRISCbits.RC7=1;//Set as Rc

    //Other Init
    TXSTA = 0x24;
    RCSTA = 0x90;s
    SPBRG = 0x19;

    while(1)
    {
	    for(i=0;Data[i]!='\0';i++)
	    {
		    TXREG=Data[i];
		    
        
        while(PIR1bits.TXIF == 0);//wait for TX
        PIR1bits.TXIF = 0; //Flag Bit Clear
        Delay(500);
    }
}
}