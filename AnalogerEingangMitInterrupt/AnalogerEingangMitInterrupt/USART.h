/*********************************************************************


	USART - API by Jo Wagner 


**********************************************************************/

#ifndef __JO_S_UART__

	#define __JO_S_LCD__

	#ifndef F_CPU
		#define F_CPU 16000000UL
	#endif
	
	#include <avr/io.h>
	#include <util/delay.h>
	#include <avr/interrupt.h>
	#include <avr/sleep.h>

	//baud rate
	#define BAUDRATE 9600
	//berechne UBRR value
	#define UBRRVAL ((F_CPU/(BAUDRATE*16UL))-1)

	
	typedef void(*USART_RECEIVE_CALLBACK)(char);

	void usart_init(void);
	void usart_send(char);
	void usart_send_string(char *);
	uint8_t usart_receive();
	void usart_send_string_new_line(char *message);
	void usart_set_receive_callback(USART_RECEIVE_CALLBACK callback);

#endif

