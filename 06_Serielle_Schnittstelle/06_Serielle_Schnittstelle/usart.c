/*
 * usart.c
 *
 * Created: 17.12.2021 09:57:41
 *  Author: JoachimWagner
 */ 
#include "usart.h"

static volatile RECEIVER_FUNCTION callback; 

void usart_Init(RECEIVER_FUNCTION myFunction) {
	
	callback = myFunction;
	/*Set baud rate */
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;
	
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Enable receiver and transmitter
	UCSR0B |= (1 << RXCIE0);                    // Enable reciever interrupt
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stp

	sei();                                      // Lets not forget to enable interrupts =P
}

ISR (USART_RX_vect)
{
	callback(UDR0);
}