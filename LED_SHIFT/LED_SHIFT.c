#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRB=0b11111111;
DDRC=0b00001000;
while(1)
{  
	PORTB=0b00000001;
	_delay_ms(100);
	PORTB=0b00000010;
	_delay_ms(100);
	PORTB=0b00000100;
	_delay_ms(100);
	PORTB=0b00001000;
	_delay_ms(100);
	PORTB=0b00010000;
	_delay_ms(100);
	PORTB=0b00100000;
	_delay_ms(100);
	PORTB=0b01000000;
	_delay_ms(100);
	PORTB=0b10000000;
	_delay_ms(100);
	PORTB=0b00000000;
	PORTC=0b00001000;
	_delay_ms(250);
	PORTC=0b00000000;
}
return 0;
}
