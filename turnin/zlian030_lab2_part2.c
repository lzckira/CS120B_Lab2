/*	Author: zlian030
 *      Partner(s) Name: Xiaojun He
 *  	Lab Section: 021
 *	Assignment: Lab #2  Exercise #2
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
    DDRA = 0x00; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; // Configure port B's 8 pins as outputs
    PORTA = 0x00; // Initialize PORTB output to 0’s
    PORTC = 0x00; // Initialize PORTB output to 0’s
    unsigned char tmpA = 0x00;
    unsigned char cntavail;
    while(1){
	tmpA = PINA;
	cntavail = 4;
	if ((tmpA & 0x01) == 1) {
	    cntavail--;
	}
	if ((tmpA & 0x02) == 1) {
	    cntavail--;
	}	    
	if ((tmpA & 0x04) == 1) {
	    cntavail--;
	}	    
	if ((tmpA & 0x08) == 1) {
	    cntavail--;
	}
	if (cntavail == 4) {
            PORTC = 0x04;
	}
	else if (cntavail == 3) {
	    PORTC = 0x03;
	}
	else if (cntavail == 2) {
  	    PORTC = 0x02;
	}
	else if (cntavail == 1) {
	    PORTC = 0x01;
	}
	else{
	    PORTC = 0x00;
	}
    }

    return 1;
}
