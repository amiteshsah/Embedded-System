#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRA=0b00000000;
DDRB=0b00001111;
unsigned int x;
while(1)
{
x=PINA & 0b00000011;
if(x==0b00000011)
{
PORTB=0b00001010;
}
else if(x==0b00000001)
{
PORTB=0b00000010;
}
else if(x==0b00000010)
{
PORTB=0b00001000;
}
else
{
PORTB=0b00000000;
}
}
return 0;
}
