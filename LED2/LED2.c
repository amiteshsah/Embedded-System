#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRB=0b11111111;
while(1)
{
PORTB=0b10101010;
_delay_ms(1000);
PORTB=0b01010101;
_delay_ms(1000);
}
return 0;
}
