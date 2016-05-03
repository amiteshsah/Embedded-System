#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRA=0X00;
DDRC=0b00001000;
DDRB=0XFF;
void pwm();


while(1)
{
pwm();

unsigned int x;
x=PINA & 0b00000011;
if(x==0b00000001)
{
OCR0=60;
PORTC=0b00001000;
PORTB=0b00001000;
}
else if(x==0b00000010)
{
OCR0=120;
PORTC=0b00001000;
PORTB=0b00001000;
}
else if(x==0b00000011)
{
OCR0=180;
PORTC=0b00001000;
PORTB=0b00001000;
}
else
PORTC=0X00;
PORTB=0X00;
}
return 0;
}


void pwm(void)
{
TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
}
