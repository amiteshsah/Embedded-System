#include<avr/io.h>
#include<util/delay.h>

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

int main()
{
DDRA=0x00;
DDRB=0XFF;
DDRD=0XFF;
lcd_init();
unsigned int x;
while(1)
{

x=PINA & 0b00001111;

if(x==0b00001010)
{
PORTB=0b00001010;
dis_cmd(0x80);
string_LCD("FORWARD");
_delay_ms(5000);
}
else if(x==0b00000001)
{
PORTB=0b00001000;
dis_cmd(0x80);
string_LCD("LEFT    ");
_delay_ms(5000);
}
else if(x==0b00000100)
{
PORTB=0b00000001;
dis_cmd(0x80);
string_LCD("RIGHT    ");
_delay_ms(5000);
}
else if(x==0b00000101)
{
PORTB=0b00000101;
dis_cmd(0x80);
string_LCD("REVERSE    ");
_delay_ms(5000);
	}
	else
	{
	PORTB=0X00;
	dis_cmd(0x80);
	string_LCD("STOP    ");
	_delay_ms(5000);
	}
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


void write_LCD(unsigned char abc)
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


void dis_write(unsigned char write)
{ 
unsigned char write1;
write1 = (write&0xf0);
write_LCD(write1);
write1 = ((write<<4)&0xf0);
write_LCD(write1);
_delay_ms(1);
}

void string_LCD(unsigned char *str)
{
	int i;
	
	for(i=0;str[i]!='\0';i++) 
	{	dis_write(str[i]);
	 	
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
		dis_write(a+48);
		value=value/10;
	}
	dis_cmd(0x06);// for again incrementing the cursor position
}

