#include<avr/io.h>
#include<util/delay.h>

int key(void);

#define LCD_data_cntrl PORTD
#define en PD2		//enable lcd 1 or disable lcd 0 lcd prepare for geting data
#define rw PD1		//rw=read/write to LCD 1 for read and 0 for write
#define rs PD0		//rs=register select 0 for comm. 1 for Data

void lcd_init();
void dis_cmd(unsigned char cmd);
void dis_write(unsigned char data);
void write_LCD(unsigned char);
void cmd_LCD(unsigned char);
void string_LCD(unsigned char *str);
void LCD_number(unsigned int value);

void pwm();

int main(void)
{	DDRA=0b00000000;
  	DDRB=0b11111111;
  	DDRD=0b11111111;

	DDRC=0b00001000;
  	int y=0;
	pwm();


	PORTA=0x0F;                                                                                                                                                                                                                       		
  	while(1)
  	{	
	lcd_init();
	y=key();
if(y==1)
		{
		PORTB=0b00001000;
		dis_cmd(0X80);
		string_LCD("RIGHT   ");
		}
if(y==2)
		{
		OCR0=120;
		PORTC=0b00001000;
		}
if(y==3)
		{
		OCR0=180;
		PORTC=0b00001000;
		}
if(y==4)
		{
		OCR0=240;
		PORTC=0b00001000;
		}
if(y==5)
 		{
		OCR0=60;
		PORTC=0b00001000;
		}
if(y==6 ||y==7||y==9)
		{
		lcd_init();
	for(int i=0;i<=12;i++)
	{	dis_cmd(0x81);
	LCD_number(i);
	_delay_ms(1000);
	for(int j=0;j<60;j++)
		{ dis_cmd(0x85);
		LCD_number(j);
		_delay_ms(1000); 
			for(int k=0;k<60;k++)
			{dis_cmd(0x89);
			LCD_number(k);
			_delay_ms(1000);}dis_cmd(0x01);
		}dis_cmd(0x01);
}
	}
	
if(y==8)
	{
	dis_cmd(0x01);
	PORTB=0X00;
	PORTC=0X00;
	}
if(y==10)
		{
		PORTB=0b00000101;
		dis_cmd(0X80);
		string_LCD("BACKWARD");}
if(y==11)
		{
		PORTB=0b00000000;
		dis_cmd(0X80);
		string_LCD("STOP   ");
		}
if(y==12)
		{
		PORTB=0b01010101;
		_delay_ms(100);
		PORTB=0b10101010;
		_delay_ms(100);
		}
if(y==13)
		{
		PORTB=0b00001010;
		dis_cmd(0X80);
		string_LCD("FORWARD");
		}

if(y==14)
		{
		PORTB=0b00000010;
		dis_cmd(0X80);
		string_LCD("LEFT   ");
		}
if(y==15)
		{
		PORTB=0X0F;
		_delay_ms(50);
		PORTB=0X00;
		_delay_ms(50);
		}
if(y==16)
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
 }	
	return 0;
}

int key()
{	int key=1;
	while(key)
	{	PORTC=0b11101111;
		if((PINA & 0b00000001) == 0){return 1;key=0;}
		if((PINA & 0b00000010) == 0){return 2;key=0;}
		if((PINA & 0b00000100) == 0){return 3;key=0;}
		if((PINA & 0b00001000) == 0){return 4;key=0;}
		

		PORTC=0b11011111;
		if((PINA & 0b00000001) == 0){return 5;key=0;}
		if((PINA & 0b00000010) == 0){return 6;key=0;}
		if((PINA & 0b00000100) == 0){return 7;key=0;}
		if((PINA & 0b00001000) == 0){return 8;key=0;}

		PORTC=0b10111111;
		if((PINA & 0b00000001) == 0){return 9;key=0;}
		if((PINA & 0b00000010) == 0){return 10;key=0;}
		if((PINA & 0b00000100) == 0){return 11;key=0;}
		if((PINA & 0b00001000) == 0){return 12;key=0;}

		PORTC=0b01111111;
		if((PINA & 0b00000001) == 0){return 13;key=0;}
		if((PINA & 0b00000010) == 0){return 14;key=0;}
		if((PINA & 0b00000100) == 0){return 15;key=0;}
		if((PINA & 0b00001000) == 0){return 16;key=0;}
	key=1;
	}
}




void cmd_LCD(unsigned char xyz)
{ 
	LCD_data_cntrl=xyz;
	LCD_data_cntrl &=~ (1<<rs);
	LCD_data_cntrl &=~ (1<<rw);
	LCD_data_cntrl |= (1<<en);
	_delay_ms(1);
	LCD_data_cntrl &=~ (1<<en);
}


void data_LCD(unsigned char abc)
{

	LCD_data_cntrl=abc;
	LCD_data_cntrl |= (1<<rs);
	LCD_data_cntrl &=~ (1<<rw);
	LCD_data_cntrl |= (1<<en);
	_delay_ms(1);
	LCD_data_cntrl &=~ (1<<en);
}


void dis_cmd(unsigned char cmd)
{ 
unsigned char cmd1;
cmd1 = (cmd&0xf0);
cmd_LCD(cmd1);
cmd1 = ((cmd<<4)&0xf0);
cmd_LCD(cmd1);
_delay_ms(1);
}


void dis_data(unsigned char data)
{ 
unsigned char data1;
data1 = (data&0xf0);
data_LCD(data1);
data1 = ((data<<4)&0xf0);
data_LCD(data1);
_delay_ms(1);
}

void string_LCD(unsigned char *str)
{
	int i;
	
	for(i=0;str[i]!='\0';i++) 
	{	dis_data(str[i]);
	 	
  	}
	return 0;
	}


void lcd_init(void)
{
	
	dis_cmd(0x02);
	dis_cmd(0x28);
	dis_cmd(0x0c);
	dis_cmd(0x01);
}

void LCD_number(unsigned int value)
{	dis_cmd(0x04);//for decrementing the cursor position
	unsigned int a=0;
	while(value!=0)
	{	a=value%10;
		dis_data(a+48);
		value=value/10;
	}
	dis_cmd(0x06);// for again incrementing the cursor position
}
void pwm(void)
{
TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
}
