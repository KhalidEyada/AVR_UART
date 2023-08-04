#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"
#include "UART_config.h"




c
Copy code
/**
 * @brief Initialize UART communication.
 *
 * This function initializes the UART communication by setting the baud rate, frame format, and enabling the transmission and reception.
 * The specific configuration values are defined in CONFIG_UCSRC and CONFIG_UCSRB.
 * The baud rate value is defined as BAUD_RATE, which should be set to the desired baud rate for UART communication.
*/
void UART_voidInit(void)
{
	/* PUT SOME CODE HERE */	
  // Set BaudRate -> 9600 or whatever
  // Set Frame Format -> 8 data, 1 stop, No Parity or what ever
  // Enable Sending and Recieving by Enabling RXE and TXE bits in USCRB register
   UCSRC=CONFIG_UCSRC;
   UCSRB=CONFIG_UCSRB;
   UBRRL=BAUD_RATE;
   UBRRH = (BAUD_RATE >> 8);	
}

/**
 * @brief Send a character over UART communication.
 *
 * This function sends a single character (data) over UART communication.
 * It waits for the UART Data Register Empty (UDRE) flag in the UCSRA register to be set, indicating that the transmit buffer is empty and ready to accept data.
 * Once the flag is set, the data is written to the UART Data Register (UDR) to be sent.
 *
 * @param data: The character to be sent over UART communication.
 *
 * @note Before calling this function, ensure that the UART communication is initialized and properly configured using UART_voidInit().
 **/
void UART_voidSendChar(u8 data)
{
  /* PUT SOME CODE HERE */
  
    // wait for the trasmitting flag (UDRE bit in UCSRA register)
	//send data
	while (! (UCSRA & (1<<u8_PIN5)));  /* Wait for empty transmit buffer */
		UDR_T=data;
}

/**
* @brief Receive a character over UART communication.
*
* This function receives a single character from UART communication.
* It waits for the UART Receive Complete (RXC) flag in the UCSRA register to be set, indicating that data has been received and is available in the receive buffer.
* Once the flag is set, the data is read from the UART Data Register (UDR) and returned as the result of the function.
*
* @return The received character from UART communication.
**/
u8 UART_voidGetChar(void)
{
  
  /* PUT SOME CODE HERE */
  u8 data='\0';
  
  // wait for the receiving flag (RXC bit in UCSRA register)
  //read data
  while ((UCSRA & (1 << u8_PIN7)) == 0);/* Wait till data is received */
  data = UDR_R;		

  return data;		/* Return the byte */
  
}


/**
 * @brief Receive a string from UART communication terminated by the newline character ('\n').
 *
 * This function receives a string of characters from UART communication and stores it in the provided buffer (str) until the newline character is encountered.
 * It uses the UART_voidGetChar() function to receive individual characters and appends them to the buffer until the newline character ('\n') is received.
 *
 * @param str: Pointer to the buffer where the received string will be stored.
 *
 * @note Before calling this function, ensure that the UART communication is initialized and properly configured using UART_voidInit().
 */
void UART_voidGetString(u8* str)
{
   u8 receivedChar;
  /* PUT SOME CODE HERE */
  do 
  {
	  receivedChar = UART_voidGetChar();
	  *str = receivedChar;
	  str++;
  } while (receivedChar!='\n');
  
}

/**
 * @brief Send a string over UART communication.
 *
 * This function sends a string of characters (character array) over UART communication.
 * It uses the UART_voidSendChar() function to send each character one by one until the null terminator '\0' is encountered.
 * The null terminator marks the end of the string and is not sent over UART.
 *
 * @param str: Pointer to the string (character array) to be sent over UART.
 *
 * @note Before calling this function, ensure that the UART communication is initialized and properly configured using UART_voidInit().
 */

void UART_voidSendString(const u8* str)
{
  
  /* PUT SOME CODE HERE */
	while(*str!='\0')
	{
		UART_voidSendChar(*str);
		str++;
	}	
  
}


/*
//UART ISRs
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	UART_u8ReceivedFlag=1;	
}


void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	UART_u8TransmitFlag=1;
}*/
