/*
 * AnalogerEingangMitInterrupt.c
 *
 * Created: 14.12.2021 09:23:25
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include <stdlib.h>   
#include "USART.h"
#include "analog.h"

volatile uint8_t ADCvalueA;    // Global variable, set to volatile if used with ISR
volatile uint8_t ADCvalueB;
char buffer[10];
volatile uint8_t conversion = 0; 

int main(void)
{
	analog_init();
	usart_init();
	
	
    /* Replace with your application code */
    while (1) 
    {
		
		
		usart_send_string("Channel 0: ");
		usart_send_string(itoa(ADCvalueA,buffer, 10));
		usart_send('\n');
		usart_send('\r');
		
		usart_send_string("Channel 1: ");
		usart_send_string(itoa(ADCvalueB,buffer, 10));
		usart_send('\n');
		usart_send('\r');
			
		
    }
}

ISR(ADC_vect)
{
	ADCSRA &=  ~(1 << ADIE);    // disable Interrupts
	
	if(ADMUX % 2 ){
		ADCvalueB = ADCH;          // only need to read the high value for 8 bit
		set_channel(0);
	}
	else{
		ADCvalueA = ADCH;          // only need to read the high value for 8 bit
		set_channel(1);
	}
	
	
	ADCSRA |= (1 << ADIE);    // Enable Interrupts
	
}

