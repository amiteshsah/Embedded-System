#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRA=0X00;
DDRD=0X0F;
DDRB=0xFF;
while(1)
{
/*PORTD=0b00001110;
_delay_ms(50);
if(PINA==0b11111110){PORTB=0b00000001;}
if(PINA==0b11111101){PORTB=0b00000010;}
if(PINA==0b11111011){PORTB=0b00000100;}
if(PINA==0b11110111){PORTB=0b00001000;}

PORTD=0b00001101;
_delay_ms(50);
if(PINA==0b11111110){PORTB=0b00010000;}
if(PINA==0b11111101){PORTB=0b00100010;}
if(PINA==0b11111011){PORTB=0b01000100;}
if(PINA==0b11110111){PORTB=0b10001000;}
PORTD=0b00001011;
_delay_ms(50);
if(PINA==0b11111110){PORTB=0b00000001;}
if(PINA==0b00011101){PORTB=0b00000010;}
if(PINA==0b11111011){PORTB=0b00000100;}
if(PINA==0b11110111){PORTB=0b00001000;}
PORTD=0b00000111;
_delay_ms(50);
if(PINA==0b11111110){PORTB=0b00000001;}
if(PINA==0b00011101){PORTB=0b00000010;}
if(PINA==0b11111011){PORTB=0b00000100;}
if(PINA==0b11110111){PORTB=0b00001000;}

else 
PORTB=0X00;
*/
PORTD=0X0E;
_delay_ms(50);
if(PINA==0XFE){PORTB=0X01;}
if(PINA==0XFD){PORTB=0X02;}
if(PINA==0XF){PORTB=0b00000100;}
if(PINA==0b11110111){PORTB=0b00001000;}

PORTD=0X0D;
_delay_ms(50);
if(PINA==0b11111110){PORTB=0b00010000;}
if(PINA==0b11111101){PORTB=0b00100010;}
if(PINA==0b11111011){PORTB=0b01000100;}
if(PINA==0b11110111){PORTB=0b10001000;}
PORTD=0X0C;
_delay_ms(50);
if(PINA==0b11111110){PORTB=0b00000001;}
if(PINA==0b00011101){PORTB=0b00000010;}
if(PINA==0b11111011){PORTB=0b00000100;}
if(PINA==0b11110111){PORTB=0b00001000;}
PORTD=0X0B;
_delay_ms(50);
if(PINA==0b11111110){PORTB=0b00000001;}
if(PINA==0b00011101){PORTB=0b00000010;}
if(PINA==0b11111011){PORTB=0b00000100;}
if(PINA==0b11110111){PORTB=0b00001000;}
}
return 0;
}
