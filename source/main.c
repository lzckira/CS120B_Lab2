/*	Author: zlian030
 *      Partner(s) Name: Xiaojun He
 *  	Lab Section: 021
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
    DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char tmpD = 0x00;
    unsigned short totalWeight = 0x0000;
    unsigned char weightDiff = 0x00;
    while(1){
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	tmpD = 0x00;
	totalWeight = tmpA + tmpB +tmpC;
	if (totalWeight > 0x008C) {
	    tmpD = tmpD | 0x01;
	}
	if (tmpA >= tmpC) {
	    weightDiff = tmpA - tmpC;
	}
	else {
	    weightDiff = tmpC - tmpA;
	}
	if (weightDiff > 0x50) {
	   tmpD = tmpD | 0x02;
	}
	PORTD = tmpD;
    }
    return 1;
}
