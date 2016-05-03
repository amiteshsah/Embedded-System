#include<avr/io.h>
#include<util/delay.h>
int main()
{
unsigned int x;
DDRA=0X00;
DDRB=0b00001111;
while(1)
{
x=PINA & 0b00000011;
if(x==0b00000010)
{PORTB=0b00001010;}
else if(x==0b00000011)
{PORTB=0b000001000;}
else if(x==0b00000000)
{PORTB=0b00000000;}
}
return 0;
}
