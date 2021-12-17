#include "USART.h"


static void DEFAULT_CALLBACK_FKT(char c){}
static USART_RECEIVE_CALLBACK _callback = DEFAULT_CALLBACK_FKT;



void usart_init() {

	/*Set baud rate */
	UBRR0H = (UBRRVAL >> 8);
	UBRR0L = UBRRVAL;
	
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Enable receiver and transmitter
	UCSR0B |= (1 << RXCIE0);                    // Enable reciever interrupt
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stp
	
	
	//set_sleep_mode(SLEEP_MODE_IDLE);

	//globale Interrupts erlauben
	sei();

}


void usart_send(char value){

	while ( !(UCSR0A & (1 << UDRE0)) ) ;
	UDR0 = value;

}
uint8_t usart_receive(){
	 while(!(UCSR0A & (1 << RXC0)));
	 // return data
	 return UDR0;
}

void usart_send_string(char * s){

	while (*s)
		usart_send(	*s ++);
}

void usart_send_string_new_line(char *message) {
	usart_send_string(message);
	usart_send_string("\r\n");
}

void usart_set_receive_callback(USART_RECEIVE_CALLBACK callback) {
	_callback = callback;
}

ISR (USART_RX_vect)
{
	//_callback(UDR0);
}


