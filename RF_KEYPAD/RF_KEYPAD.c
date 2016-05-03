#include <avr/io.h>
#include <util/delay.h>

int key(void);

int main(void)
{	DDRA=0b00000000;
  	DDRB=0b11111111;
  	DDRD=0b11111111;
  	int y=0;
	PORTA=0x0F;                                                                                                                                                                                                                       		
  	while(1)
  	{	y=key();
  		if(y==1){PORTB=0X00;}
		if(y==2){PORTB=0b00000001;}
		if(y==3){PORTB=0X00;}
		if(y==4){PORTB=0X00;}
 		if(y==5){PORTB=0X00;}
		if(y==6){
		PORTB=0b00000010;}
		if(y==7){		PORTB=0b00000100;}
		if(y==8){PORTB=0X00;}
 		if(y==9){		PORTB=0b00001000;}
		if(y==10){		PORTB=0b00010000;}
		if(y==11){PORTB=0X00;}
		if(y==12){PORTB=0X00;}
 		if(y==13){PORTB=0X00;}
		if(y==14){PORTB=0X00;}
		if(y==15){PORTB=0X00;}
		if(y==16){PORTB=0X00;}
  	}	
	return 0;
}

int key()
{	int key=1;
	while(key)
	{	PORTD=0b11101111;
		if((PINA & 0b00000001) == 0){return 1;key=0;}
		if((PINA & 0b00000010) == 0){return 2;key=0;}
		if((PINA & 0b00000100) == 0){return 3;key=0;}
		if((PINA & 0b00001000) == 0){return 4;key=0;}
		

		PORTD=0b11011111;
		if((PINA & 0b00000001) == 0){return 5;key=0;}
		if((PINA & 0b00000010) == 0){return 6;key=0;}
		if((PINA & 0b00000100) == 0){return 7;key=0;}
		if((PINA & 0b00001000) == 0){return 8;key=0;}

		PORTD=0b10111111;
		if((PINA & 0b00000001) == 0){return 9;key=0;}
		if((PINA & 0b00000010) == 0){return 10;key=0;}
		if((PINA & 0b00000100) == 0){return 11;key=0;}
		if((PINA & 0b00001000) == 0){return 12;key=0;}

		PORTD=0b01111111;
		if((PINA & 0b00000001) == 0){return 13;key=0;}
		if((PINA & 0b00000010) == 0){return 14;key=0;}
		if((PINA & 0b00000100) == 0){return 15;key=0;}
		if((PINA & 0b00001000) == 0){return 16;key=0;}
	key=1;
	}
}

