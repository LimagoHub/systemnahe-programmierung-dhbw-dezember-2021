/*
 * usart.h
 *
 * Created: 17.12.2021 09:55:36
 *  Author: JoachimWagner
 */ 


#ifndef USART_H_
#define USART_H_
#include <avr/io.h>
#include <stdint.h>                     // needed for uint8_t
//#include <stdlib.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL                       // Clock Speed
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD -1


typedef void (*RECEIVER_FUNCTION)(char);




inline void usart_sendChar(char value) {
	while ( !(UCSR0A & (1 << UDRE0)) ) ;
	UDR0 = value;
}

inline void usart_sendString(char *message) {
	while(*message)
	usart_sendChar(*message ++);
}

inline void usart_sendStringNewLine(char *message) {
	usart_sendString(message);
	usart_sendString("\r\n");
}




void usart_Init(RECEIVER_FUNCTION myFunction) ;



#endif /* USART_H_ */