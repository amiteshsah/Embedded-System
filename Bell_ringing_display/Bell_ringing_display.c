#include<avr/io.h>
#include<util/delay.h>

#define LCD_data_cntrl PORTD
#define en PD2		//enable lcd 1 or disable lcd 0 lcd prepare for geting data
#define rw PD1		//rw=read/write to LCD 1 for read and 0 for write
#define rs PD0		//rs=register select 0 for comm. 1 for Data

void lcd_init();
void dis_cmd(unsigned char cmd);
void dis_data(unsigned char data);
void data_LCD(unsigned char);
void cmd_LCD(unsigned char);
void string_LCD(unsigned char *str);
void LCD_number(unsigned int value);
void pattern1();
void pattern2();
void pattern3();
int main()
{	DDRD=0XFF;
DDRC=0b00001000;
lcd_init();
dis_cmd(0x01);

		while(1)
		{

dis_cmd(0xc0);
string_LCD("BELL IS RINGING");		
	dis_cmd(0x82);
	dis_data(0);
		pattern1();
		_delay_ms(500);
	dis_cmd(0x82);
	dis_data(1);
		pattern2();
		_delay_ms(500);
		PORTC=0b00001000;
		_delay_ms(50);
		PORTC=0x00;
	dis_cmd(0x82);
	dis_data(2);
		pattern3();
		_delay_ms(500);
	PORTC=0b00001000;
	_delay_ms(50);
	PORTC=0X00;
	}

	return 0;
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

void pattern1(void)
{
dis_cmd(0x40);
dis_data(0b00000100);
dis_data(0b00000100);
dis_data(0b00001110);
dis_data(0b00011111);
dis_data(0b00011111);
dis_data(0b00000000);
dis_data(0b00000100);
dis_data(0x00);

}
void pattern2(void)
{
dis_cmd(0x48);
/*
(0x04);
data_LCD(0x0E);
data_LCD(0x0E);
data_LCD(0x0E);
data_LCD(0x1F);
data_LCD(0x00);
data_LCD(0x01);
data_LCD(0x00);
*/

dis_data(0b00000100);
dis_data(0b00000100);
dis_data(0b00001110);
dis_data(0b00011111);
dis_data(0b00011111);
dis_data(0b00000000);
dis_data(0b00000001);
dis_data(0x00);
}

void pattern3(void)
{
dis_cmd(0x50);

/*
data_LCD(0x04);
data_LCD(0x0E);
data_LCD(0x0E);
data_LCD(0x0E);
data_LCD(0x1F);
data_LCD(0x00);
data_LCD(0x10);
data_LCD(0x00);
*/

dis_data(0b00000100);
dis_data(0b00000100);
dis_data(0b00001110);
dis_data(0b00011111);
dis_data(0b00011111);
dis_data(0b00000000);
dis_data(0b00010000);
dis_data(0x00);
}
