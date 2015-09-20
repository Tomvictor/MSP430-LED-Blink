/*
This is a simple demo project for all beginers in Texaas instruments MSP430
MSP430 is aultra low voltage microcontroller family from texas instruments. This demo project
describes how to blink and led on P1.0, using software delay.
Registers:
PxOUT is the outputregisterof msp430
PxDIR is the port direction register, ie 1=out/0=input
WDTCTL is the Watchdog control register, here we are disabling it.
Author: Tomvictor
www.buildfromzero.com
*/
#include <msp430.h>

void main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	P1DIR |= BIT0;					// Set P1.0 to output direction

	while(1) {
		volatile unsigned int i;	// volatile to prevent optimization

		P1OUT ^= BIT0;				// Toggle P1.0 using exclusive-OR

		i = 10000;					// SW Delay
		do i--;
		while(i != 0);
	}

	//return ;
}
