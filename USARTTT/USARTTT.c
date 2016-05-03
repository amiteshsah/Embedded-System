#define F_CPU 8000000
#include<avr/io.h>
#include<util/delay.h>



#define USART_BAUDRATE 1200	// Baud Rate value
#define BAUD_PRESCALE ((F_CPU / (USART_BAUDRATE * 16)) - 1)
  
void USART_write_string(unsigned char *str);
void usart_init(void);
void usart_putch(unsigned char send);
unsigned int usart_getch(void);




int main()
{	unsigned int value;
	DDRD=0xff;
	DDRB=0XFF;
	
	usart_init();
	
	while(1)
	{
		value=usart_getch();
		//usart_putch(value);
		
	
				if (value=='f')
				{
				
				PORTB=0b00000101;
				
				}
				else if(value=='b')
				{
				
				PORTB=0b00001010;
				}


				
				else if (value=='l')
				{
				
				PORTB=0b00000001;
				
				}
				else if(value=='r')
				{
				
				PORTB=0b00001000;
				}

				else
				{
				PORTB=0X00; 
				}
			}
	return 0;
}
 
 
void usart_init()
{
	UCSRB |= (1 << RXEN)|(1<<TXEN);   // Turn on the transmission and reception circuitry
	UCSRC |= (1 << URSEL) | (1<<USBS) | (1 << UCSZ0) | (1 << UCSZ1); 
											// Use 8-bit character sizes
 
	UBRRL = BAUD_PRESCALE; 
			// Load lower 8-bits of the baud rate value into the low byte of the UBRR register
	UBRRH = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value..
									// into the high byte of the UBRR register
}
 
unsigned int usart_getch()
{	unsigned int ret;
	while ((UCSRA & (1 << RXC)) == 0); 
	{	
	}	// Do nothing until data has been received and is ready to be read from UDR
	
	return UDR; // return the byte
}
 

void usart_putch(unsigned char send)
{	while(!(UCSRA & (1<<UDRE)))
   {
   }
   UDR=send;
}



