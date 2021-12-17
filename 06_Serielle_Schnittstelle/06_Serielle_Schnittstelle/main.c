// This code waits for a character and transmits the character back (with interrupts)


#include <avr/io.h>
#include <stdint.h>                     // needed for uint8_t
//#include <stdlib.h>
#include <avr/interrupt.h>

#include "usart.h"




volatile char ReceivedChar;

void doIt(char c) {
	ReceivedChar = c;
	usart_sendChar(c);
}


int main( void )
{
	
	usart_Init(doIt);
	usart_sendStringNewLine("Hallo Welt");
	while(1)
	{
		;                                      // Main loop
	}
}

