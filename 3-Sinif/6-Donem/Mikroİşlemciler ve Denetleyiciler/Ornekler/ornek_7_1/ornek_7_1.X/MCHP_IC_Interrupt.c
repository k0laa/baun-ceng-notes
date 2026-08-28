#include "ornek_7_1.h"
#include "ornek_7_1_private.h"

/* Input Capture - Data-Interrupt: <Root>/Input Capture */
volatile uint16_T MCHP_ic1up;
volatile uint16_T MCHP_ic1ChangeDetectedFlag;
volatile uint16_T MCHP_ic2up;
volatile uint16_T MCHP_ic2ChangeDetectedFlag;

/* Implement Input Capture Interrupts if required */
void __attribute__((__interrupt__,__no_auto_psv__)) _IC1Interrupt(void)
{
  static uint16_T IC1BUF_Old;
  uint16_T IC1BUF_New;
  while (IC1CONbits.ICBNE == 1)
    IC1BUF_New = IC1BUF;               /* take the last value */
  if (IC1CON & 1)                      /* This is a rising edge */
  {
    IC1CON &= 0xFFFE;                  /* detect next falling edge */
    MCHP_ic1ChangeDetectedFlag++;
  } else                               /* falling edge */
  {
    IC1CON |= 1;                       /* detect next rising edge */
    MCHP_ic1up = IC1BUF_New - IC1BUF_Old;/* Compute Up time */
  }

  IC1BUF_Old = IC1BUF_New;
  _IC1IF = 0;                          /* Clear Interrupt Flag */
}

void __attribute__((__interrupt__,__no_auto_psv__)) _IC2Interrupt(void)
{
  static uint16_T IC2BUF_Old;
  uint16_T IC2BUF_New;
  while (IC2CONbits.ICBNE == 1)
    IC2BUF_New = IC2BUF;               /* take the last value */
  if (IC2CON & 1)                      /* This is a rising edge */
  {
    IC2CON &= 0xFFFE;                  /* detect next falling edge */
    MCHP_ic2ChangeDetectedFlag++;
  } else                               /* falling edge */
  {
    IC2CON |= 1;                       /* detect next rising edge */
    MCHP_ic2up = IC2BUF_New - IC2BUF_Old;/* Compute Up time */
  }

  IC2BUF_Old = IC2BUF_New;
  _IC2IF = 0;                          /* Clear Interrupt Flag */
}
