#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRA=0X00;
DDRB=0XFF;
void pwm();


while(1)
{
pwm();

unsigned int x;
x=PINA & 0b00011111;
if(x==0b00000001)
{
OCR0=60;
PORTB=0b00000001;
}
else if(x==0b00000010)
{
OCR0=120;
PORTB=0b00001000;
}
else if(x==0b00000100)
{
OCR0=180;
PORTB=0b00001000;
}
else if(x==0b00001000)
{
OCR0=240;
PORTB=0b00001000;
}
else if(x==0b00010000)
{
OCR0=255;
PORTB=0b00001000;
}
else
{
OCR0=0;
PORTB=0X00;
}
}
return 0;
}


void pwm(void)
{
TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
}
