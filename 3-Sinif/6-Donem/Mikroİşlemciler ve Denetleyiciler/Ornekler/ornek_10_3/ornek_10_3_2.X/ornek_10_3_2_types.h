/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_10_3_2_types.h
 *
 * Code generated for Simulink model 'ornek_10_3_2'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Aug 29 21:46:31 2026
 */

#ifndef RTW_HEADER_ornek_10_3_2_types_h_
#define RTW_HEADER_ornek_10_3_2_types_h_
#include "rtwtypes.h"

/* Declare UART1 Tx Circular Buffer Structure */
#define Tx_BUFF_SIZE_UART1             (128)

typedef struct MCHP_UART1_TxStr{
  volatile uint8_T buffer[Tx_BUFF_SIZE_UART1];/* Size Rx_BUFF_SIZE_UART1 is 128 */
  volatile uint_T tail;         /* tail is the index for the next value to be read from the Circular buffer */
  volatile uint_T head;      /* head is the index for the next value to be written into the Circular buffer */
} MCHP_UART1_TxStr;

/* Declare UART1 Rx Circular Buffer Structure */
#define Rx_BUFF_SIZE_UART1             (128)

typedef struct MCHP_UART1_RxStr{
  volatile uint8_T buffer[Rx_BUFF_SIZE_UART1];/* Size Rx_BUFF_SIZE_UART1 is 128 */
  volatile uint_T tail;      /* tail is the index for the next value to be written into the Circular buffer */
  volatile uint_T head;         /* head is the index for the next value to be read from the Circular buffer */
} MCHP_UART1_RxStr;

/* To read the UART1 Rx Circular with a custom code: read the next value: buffer[head], then increment head index by 1 modulo Rx_BUFF_SIZE_UART1 (=128).
   code example:
   if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head)	{  		// is buffer not empty ?
   output = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head ++];     // Read one char
   MCHP_UART1_Rx.head &= (Rx_BUFF_SIZE_UART1-1); 	// modulo : use a simple bitewise "and" operator as <Rx_BUFF_SIZE_UART1> is a power of 2
   }
 */
#endif                                 /* RTW_HEADER_ornek_10_3_2_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
