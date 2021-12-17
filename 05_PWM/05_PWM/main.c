/*
 * 05_PWM.c
 *
 * Created: 10.02.2018 14:50:01
 * Author : Joachim
 */ 

// this code sets up counter0 for an 8kHz PWM wave @ 16Mhz Clock


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR (INT0_vect)
{
	OCR0A = 64;
	OCR2A = 64;
}

ISR (INT1_vect)
{
	OCR0A = 64 +128;
	OCR2A = 64 +128;
}

int main(void)
{
	uint8_t weite = 0;
	uint8_t richtung = 1;
	DDRD |= (1 << DDD6);
	// PD6 is now an output
	
	DDRB |= (1 << DDB3);
	// PD6 is now an output
	
	DDRD &= ~(1 << DDD2);     // Clear the PD2 pin
	// PD2 (PCINT0 pin) is now an input

	PORTD |= (1 << PORTD2);    // turn On the Pull-up
	// PD2 is now an input with pull-up enabled

	DDRD &= ~(1 << DDD3);     // Clear the PD3 pin
	// PD3 (PCINT1 pin) is now an input

	PORTD |= (1 << PORTD3);    // turn On the Pull-up
	// PD3 is now an input with pull-up enabled


	
	EICRA |= (1 << ISC00);    // set INT0 to trigger on ANY logic change
	EIMSK |= (1 << INT0);     // Turns on INT0
	
	EICRA |= (1 << ISC10);    // set INT0 to trigger on ANY logic change
	EIMSK |= (1 << INT1);     // Turns on INT0
	
	

	OCR0A = 64+128;
	// set PWM for 75% duty cycle


	TCCR0A |= (1 << COM0A1);
	// set none-inverting mode

	TCCR0A |= /*(1 << WGM02) | */(1 << WGM01)  | (1 << WGM00);
	// set fast PWM Mode

	TCCR0B |= (1 << CS01);
	// set prescaler to 8 and starts PWM
	
	OCR2A = 64+128;
	// set PWM for 75% duty cycle


	TCCR2A |= (1 << COM0A1);
	// set none-inverting mode

	TCCR2A |= (1 << WGM00);
	// set fast PC Mode

	TCCR2B |= (1 << CS01);
	// set prescaler to 8 and starts PWM

	sei();
	while (1);
	{
		
	}
}
