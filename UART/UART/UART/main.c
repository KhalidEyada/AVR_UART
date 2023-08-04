/*
 * UART.c
 *
 * Created: 8/1/2023 2:35:58 PM
 * Author : khale
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include "MCAL/UART_interface.h"
#include "util/delay.h"

int main(void)
{
    /* Replace with your application code */
	UART_voidInit();
	
    while (1) 
    {
		u8 data=UART_voidGetChar();
		if (data!='\0')
		{
			UART_voidSendChar(data);
		}
		
    }
}

