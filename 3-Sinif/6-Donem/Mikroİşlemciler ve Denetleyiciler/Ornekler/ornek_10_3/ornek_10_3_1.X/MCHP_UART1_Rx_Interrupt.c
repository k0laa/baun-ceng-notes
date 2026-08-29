#include "ornek_10_3_1.h"
#include "ornek_10_3_1_private.h"

MCHP_UART1_RxStr MCHP_UART1_Rx = { .head = 0, .tail = 0 };/* UART1 Rx FIFO */

void __attribute__((__interrupt__,__shadow__,__no_auto_psv__)) _U1RXInterrupt(void)
{
  uint_T Tmp;
  Tmp = ~(MCHP_UART1_Rx.tail - MCHP_UART1_Rx.head);/* head - tail - 1 */
  Tmp &= (Rx_BUFF_SIZE_UART1-1);
  /* Tmp =  (head - tail - 1) modulo buffersize Rx_BUFF_SIZE_UART1) ; tmp <~ Rx_BUFF_SIZE_UART1 - (head - tail) - 1*/
  _U1RXIF = 0;                         /*  */
  while (0U != U1STAbits.URXDA) {
    if (Tmp--) {
      MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.tail] = (uint8_T) U1RXREG;
      MCHP_UART1_Rx.tail = (MCHP_UART1_Rx.tail+1) & (Rx_BUFF_SIZE_UART1-1);
    } else {
      do
        U1RXREG;
      while (0U != U1STAbits.URXDA);
      break;
    }
  }

  if (1U == U1STAbits.OERR )
    U1STAbits.OERR = 0;                /* U1 Buffer Overflow cleared */
}
