#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"

//static UART_u8ReceivedFlag=0;
//static UART_u8TransmitFlag=0;

void UART_voidInit(void)
{
	/* PUT SOME CODE HERE */
  // Set BaudRate -> 9600 or whatever
  
  // Set Frame Format -> 8 data, 1 stop, No Parity or what ever
  
  // Enable Sending and Recieving by Enabling RXE and TXE bits in USCRB register
  
}

void UART_voidSendChar(u8 data)
{
  /* PUT SOME CODE HERE */
  
    // wait for the trasmitting flag (UDRE bit in UCSRA register)
	//send data
  
}

u8 UART_voidGetChar(void)
{
  u8 data;
  /* PUT SOME CODE HERE */
  
  
  // wait for the receiving flag (RXC bit in UCSRA register)
  //read data
  

  return data;
  
}

void UART_voidGetString(u8* str)
{
  
  /* PUT SOME CODE HERE */
  
  
  
}

void UART_voidSendString(const u8* str)
{
  
  /* PUT SOME CODE HERE */
  
  
  
}

/*
UART ISRs
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	//UART_u8ReceivedFlag=1;
}


void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	//UART_u8TransmitFlag=1;
}
*/