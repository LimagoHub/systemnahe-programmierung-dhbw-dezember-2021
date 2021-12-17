/*
 * 03_Interrupt.c
 *
 * Created: 05.02.2018 19:01:55
 * Author : Joachim
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

// Interrupt Service Routine für Pin D2
ISR (INT0_vect)
{
	
	PORTB=0x00;
}

ISR (INT1_vect)
{
	PORTB=0xFF;
}

int main(void)
{
	
	DDRB=0xFF;
	PORTB=0xFF;
	
	DDRD &= ~(1 << DDD2);     // Clear the PD2 pin
	// PD2 (PCINT0 pin) is now an input

	PORTD |= (1 << PORTD2);    // turn On the Pull-up
	// PD2 is now an input with pull-up enabled
	
	DDRD &= ~(1 << DDD3);     // Clear the PD3 pin
	// PD3 (PCINT1 pin) is now an input

	PORTD |= (1 << PORTD3);    // turn On the Pull-up
	// PD3 is now an input with pull-up enabled

	// 0-ler Leitung (d2)
	EICRA |= (1 << ISC01);    // set INT0 to trigger on ANY logic change
	
	// 1-ler Leitung (d3)
	EICRA |= (1 << ISC11);    // set INT1 to trigger on ANY logic change
	
	EIMSK |= (1 << INT0);     // Turns on INT0
	EIMSK |= (1 << INT1);     // Turns on INT1


	sei();                    // turn on interrupts (Global = SET enabled Interrupt)
	
	while(1)
	{
		
	}
}




