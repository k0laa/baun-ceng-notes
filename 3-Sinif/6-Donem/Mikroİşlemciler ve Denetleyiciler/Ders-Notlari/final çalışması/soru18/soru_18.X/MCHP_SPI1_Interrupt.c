#include "soru_18.h"
#include "soru_18_private.h"

/* Implement SPI 1 Interrupts */
void __attribute__((__interrupt__,__no_auto_psv__)) _SPI1Interrupt(void) /* SPI1 ISR */
{
  _SPI1IF = 0;                         /* Clear SPI1 Interrupt Flag */

  /* Declaration of Variables */
  uint_T tmp;
  switch (MCHP_SPI1_State)
  {
   case 0:                             /* Idle */
    break;

   case 1:                             /* Start a new SPI Sequence */
    LATBbits.LATB3 = 1;                /* pin RB3 = 1 switch output pin value to 1 */

    /* Write only Sequence */
    _SPI1IF = 0;                       /* Clear SPI1 Interrupt Flag */
    SPI1BUF = 0x80;
    MCHP_SPI1_State++;
    break;

   case 2:
    /* Write only Sequence */
    tmp = SPI1BUF;
    _SPI1IF = 0;                       /* Clear SPI1 Interrupt Flag */
    SPI1BUF = 0x00;
    MCHP_SPI1_State++;
    break;

   case 3:
    LATBbits.LATB3 = 0;                /* pin RB3 = 0 switch output pin value to 0 */

    /* Delay */
    __delay32(8000000);                /* Delay  */
    LATBbits.LATB3 = 1;                /* pin RB3 = 1 switch output pin value to 1 */

    /* Write only Sequence */
    tmp = SPI1BUF;
    _SPI1IF = 0;                       /* Clear SPI1 Interrupt Flag */
    SPI1BUF = 0x02;
    MCHP_SPI1_State++;
    break;

   case 4:
    /* Read only Sequence */
    tmp = SPI1BUF;
    _SPI1IF = 0;                       /* Clear SPI1 Interrupt Flag */
    SPI1BUF = 0xFFFF;
    MCHP_SPI1_State++;
    break;

   case 5:
    LATBbits.LATB3 = 0;                /* pin RB3 = 0 switch output pin value to 0 */
    SPI1_Buff8[0] = SPI1BUF;
    MCHP_SPI1_State = 0;               /* End of SPI Sequence. SPI is available for a new sequence */
    break;

   default:                            /* Sequence finished */
    MCHP_SPI1_State = 0;               /* Should never happend */
    break;
  }                                    /* End of switch case sequence*/
}                                      /* Enf of interrupt */
