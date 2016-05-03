#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRA=0X00;
DDRB=0XFF;
int x;
while(1)
{
x=PINA & 0b00001111;
if(x==0b00000010)
PORTB=0b00001010;
else if(x==0b00000100)
PORTB=0b00001000;
else if(x==0b00000101)
PORTB=0b00000000;
else if(x==0b00000110)
PORTB=0b00000010;
else if(x==0b00001000)
PORTB=0b00000101;
else
PORTB=0X00;
}
return 0;
}
