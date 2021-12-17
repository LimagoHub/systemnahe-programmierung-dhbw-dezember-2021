/*
 * Blink.c
 *
 * Created: 05.02.2018 18:54:38
 * Author : Joachim
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    //DDRB  |= (1 << DDB5) | (1 << DDB4) | (1 << DDB3);
	DDRB = 0b00000111;
    PORTB |= 1 << PORTB5;
    while (1)
    {
	    PORTB |=1 <<PORTB5;
	    _delay_ms(100);
	    PORTB=0;
	    _delay_ms(500);
	    
    }
}

