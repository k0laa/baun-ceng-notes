#include "ornek_7_2.h"
#include "ornek_7_2_private.h"

/* Input Capture - Data-Interrupt: <Root>/Input Capture */
volatile uint16_T MCHP_ic1ChangeDetectedFlag;
volatile uint16_T MCHP_ic2ChangeDetectedFlag;

/* Implement Input Capture Interrupts if required */
void __attribute__((__interrupt__,__no_auto_psv__)) _IC1Interrupt(void)
{
  static uint16_T IC1BUF_Old;
  uint16_T IC1BUF_New;
  while (IC1CONbits.ICBNE == 1)
    IC1BUF_New = IC1BUF;               /* take the last value */
  IC1BUF_Old = IC1BUF_New;
  MCHP_ic1ChangeDetectedFlag++;
  _IC1IF = 0;                          /* Clear Interrupt Flag */
}

void __attribute__((__interrupt__,__no_auto_psv__)) _IC2Interrupt(void)
{
  static uint16_T IC2BUF_Old;
  uint16_T IC2BUF_New;
  while (IC2CONbits.ICBNE == 1)
    IC2BUF_New = IC2BUF;               /* take the last value */
  IC2BUF_Old = IC2BUF_New;
  MCHP_ic2ChangeDetectedFlag++;
  _IC2IF = 0;                          /* Clear Interrupt Flag */
}
