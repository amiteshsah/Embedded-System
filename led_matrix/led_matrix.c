#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRB=0XFF;
DDRD=0XFF;
while(1)
{
PORTB=0b10000000;
PORTD=0X00;
}
return 0;
}
