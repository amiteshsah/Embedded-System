#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRA=0X00;
DDRB=0b00001111;
DDRC=0b00001000;
unsigned int x;
while(1)
{
x=PINA & 0b00000001;
if(x==0b00000001)
{
PORTB=0X00;
PORTC=0b00001000;
_delay_ms(200);
PORTC=0X00;

}
else 
{
PORTB=0b00001010;
}
}
return 0;
}
