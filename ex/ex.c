//#define F_CPU 1000000
#include<avr/io.h>
#include<util/delay.h>

int main()
{
//DDRB=0XFF;
DDRB=0XFF;
while(1)
{
PORTB=0b00001010;
}
return 0;
}
