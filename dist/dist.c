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
void ADC_initi();
unsigned int read_ADC(unsigned char ch);

int main()
{
unsigned int x;
DDRA=0X00;	
DDRD=0XFF;
	
	ADC_initi();
	lcd_init();	
	dis_cmd(0x01);
	while(1)
	{ 
   x=read_ADC(0);
  ;
if(x<200)
{
  dis_cmd(0x83);
  LCD_number(x);
  dis_cmd(0xc0);
string_LCD("NO OBSTACLES");
_delay_ms(100);
}


 else if(x>217 && x<230)
{
dis_cmd(0x83);
  LCD_number(x);
  dis_cmd(0xc0);
string_LCD("12cm");
_delay_ms(100);
}
else if(x>250 && x<265)
{
dis_cmd(0x83);
  LCD_number(x);
  dis_cmd(0xc0);
string_LCD("9cm");
_delay_ms(100);
}


else if(x>340 && x<355)
{
dis_cmd(0x83);
  LCD_number(x);
  dis_cmd(0xc0);
string_LCD("6cm");
_delay_ms(100);
}

else if(x>395 &&x<410)
{
dis_cmd(0x83);
  LCD_number(x);
  dis_cmd(0xc0);
string_LCD("3cm");
_delay_ms(100);
}

else if(x>450)
{dis_cmd(0x83);
  LCD_number(x);
  dis_cmd(0xc0);
string_LCD("0cm");
_delay_ms(100);	 
}
else
{ dis_cmd(0x83);
  LCD_number(x);
  dis_cmd(0xc0);
string_LCD("unknown distance");
_delay_ms(100);
dis_cmd(0x01);
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

void ADC_initi(void)
{
ADMUX=(1<<REFS0)|(1<<REFS1);
ADCSRA=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}
unsigned int read_ADC(unsigned char ch)
{
ch=ch&0b00000111;
ADMUX|=ch;
ADCSRA|=(1<<ADSC);
while(!(ADCSRA&(1<<ADIF)));
ADCSRA|=(1<<ADIF);
return(ADC);
}


