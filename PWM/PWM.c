#include<avr/io.h>
#include<util/delay.h>

void pwm();

int main()
{

DDRB=0xff;

while(1)
{
pwm();


OCR0=60;
DDRB=0b00001000;
_delay_ms(1000);




OCR0=120;
DDRB=0b00001000;
_delay_ms(1000);


OCR0=180;
DDRB=0b00001000;
_delay_ms(1000);


OCR0=240;
DDRB=0b00001000;
_delay_ms(1000);

}
return 0;
}


void pwm(void)
{
TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
}


