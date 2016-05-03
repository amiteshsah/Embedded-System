#define F_CPU 1000000
#include<avr/io.h>
#include<util/delay.h>

#define LCD_data_cntrl PORTC
#define en PC2		//enable lcd 1 or disable lcd 0 lcd prepare for geting data
#define rw PC1		//rw=read/write to LCD 1 for read and 0 for write
#define rs PC0		//rs=register select 0 for comm. 1 for Data

void lcd_init();
void dis_cmd(unsigned char cmd);
void dis_write(unsigned char data);
void write_LCD(unsigned char);
void cmd_LCD(unsigned char);
void string_LCD(unsigned char *str);
void LCD_number(unsigned int value);

#define USART_BAUDRATE 1200	// Baud Rate value
#define BAUD_PRESCALE ((F_CPU / (USART_BAUDRATE * 16)) - 1)
  

void init(void);
void putcha(unsigned char send);
unsigned int getcha(void);



int main()
{
DDRB=0XFF;
DDRD=0xFF;
DDRC=0XFF;
unsigned int x;
lcd_init();
while(1)
{
init();
x=getcha();
putcha(x);
dis_cmd(0x80);
//dis_write('x');
string_LCD('x');

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
	{	dis_write(x);
	 	
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



void init()
{
	UCSRB |= (1 << RXEN)|(1<<TXEN);   // Turn on the transmission and reception circuitry
	UCSRC |= (1 << URSEL) | (1<<USBS) | (1 << UCSZ0) | (1 << UCSZ1); 
											// Use 8-bit character sizes
 
	UBRRL = BAUD_PRESCALE; 
			// Load lower 8-bits of the baud rate value into the low byte of the UBRR register
	UBRRH = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value..
									// into the high byte of the UBRR register
}
 
unsigned int getcha()
{	unsigned int ret;
	while ((UCSRA & (1 << RXC)) == 0); 
	{	
	}	// Do nothing until data has been received and is ready to be read from UDR
	
	return UDR; // return the byte
}
 

void putcha(unsigned char send)
{	while(!(UCSRA & (1<<UDRE)))
   {
   }
   UDR=send;
}
