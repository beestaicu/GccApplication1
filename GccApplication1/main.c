/*
 * GccApplication1.c
 *
 * Created: 18/05/2020 15:05:38
 * Author : bee
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int led_switch();
int led_circle();
//int led_two();



int main(void)
{
	int i = 0;
	DDRD = 0XFF; // set
	PORTD = 0X00;
	DDRB = 0b00000000; // set B0 as input
	PINB |= 0b0000001; // B0 connect pull-up resistor; 
	while(1){

		if (PINB & 0b00000001){
			led_circle();
			_delay_ms(100);
		}
		else{
			led_switch();
			_delay_ms(100);
			}
	}
}

int led_switch() {
	PORTD = 0b01010101;
	_delay_ms(1000);
	PORTD = 0b10101010;
	_delay_ms(1000);	
}

int led_circle(){
	PORTD = 0X00;
	int array[8]= {PORTD0,PORTD1,PORTD2,PORTD3,PORTD4,PORTD5,PORTD6,PORTD7};
	int i,j;
	for (i = 0; i < 8; i ++){
		PORTD |= (1<<array[i]);
		_delay_ms(100);
	}
	for (j = 7; j>-1; j--){
		PORTD &=~(1<<array[j]);
		_delay_ms(100);
	}
}

	
	
	


	