#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRB=0b11111111;
DDRD=0X00;
while(1)
{
PORTB=0XFF;
PORTD=0X00;

}

return 0;
}
