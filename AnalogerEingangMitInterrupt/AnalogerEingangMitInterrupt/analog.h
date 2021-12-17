/*
 * analog.h
 *
 * Created: 14.12.2021 10:44:19
 *  Author: JoachimWagner
 */ 


#ifndef ANALOG_H_
	#define ANALOG_H_

	
	
	#ifndef F_CPU
		#define F_CPU 16000000UL
	#endif
	
	#include <avr/io.h>
	#include <util/delay.h>
	#include <avr/interrupt.h>
	#include <avr/sleep.h>
	
	
	inline void set_channel(uint8_t channel) {
		ADMUX &= 0xF0; 
		ADMUX |= channel;	
	}
	
	inline uint8_t get_channel() {
		return ADMUX & 0xF;
	}

	void analog_init();

#endif /* ANALOG_H_ */