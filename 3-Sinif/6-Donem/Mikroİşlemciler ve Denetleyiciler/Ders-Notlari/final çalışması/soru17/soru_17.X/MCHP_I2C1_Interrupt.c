#include "soru_17.h"
#include "soru_17_private.h"

/* I2C - Interrupt: <Root>/BUS I2C MASTER */
/* Implement I2C 1 Interrupts */
void __attribute__((__interrupt__,__shadow__,__no_auto_psv__)) _MI2C1Interrupt(void) /* MI2C1 ISR */
{
  _MI2C1IF = 0;                        /* Clear I2C1 Master Interrupt */

  /* Declaration of Variables */
  switch (MCHP_I2C1_State)
  {
   case 0:                             /* Idle */
    break;

   case 1:                             /* Problem: try Reset of I2C BUS : Repeated Start sequence and Stop */
    TRISBbits.TRISB9 = 1;              /* Set I2C PIN as Port Input */
    TRISBbits.TRISB8 = 1;

    /* Set-up I2C 1 peripheral with Fsck = 99950   (100000 with  0.050025012506253574% error) */
    I2C1BRG = 0x018A;                  /* I2C clock = 99950  (100000 with  0.050025012506253574% error) */
    I2C1CON = 0x8300;
    I2C1STAT &= 0xFFF6;                /* Reset I2C Error States */
    I2C1CONbits.RSEN = 1;              /* REPEATED-START sequence */
    MCHP_I2C1_State++;
    break;

   case 2:
    /* Problem: try Reset of I2C BUS : Stop sequence*/
    I2C1STAT &= 0xFFF6;                /* Reset I2C Error States */
    I2C1CONbits.PEN = 1;               /* STOP sequence*/
    MCHP_I2C1_State++;
    break;

   case 3:
    I2C1STAT &= 0xFFF6;                /* Reset I2C Error States */
    MCHP_I2C1_State = 0;
    break;

   case 4:                             /* Start a new I2C Sequence */
    I2C1CONbits.SEN = 1;               /* START sequence  */
    MCHP_I2C1_State++;
    break;

   case 5:
    /* send 7 bit address: 77  (0x4D) */
    I2C1TRN = 0x9A;                    /* Send I2C Address : [A6 ... A0 RW] */
    MCHP_I2C1_State++;
    break;

   case 6:
    I2C1TRN = 0x00;                    /* Write I2C data */
    MCHP_I2C1_State++;
    break;

   case 7:
    I2C1CONbits.PEN = 1;               /* STOP sequence*/
    MCHP_I2C1_State++;
    break;

   case 8:
    I2C1CONbits.SEN = 1;               /* START sequence  */
    MCHP_I2C1_State++;
    break;

   case 9:
    /* send 7 bit address: 77  (0x4D) */
    I2C1TRN = 0x9B;                    /* Send I2C Address : [A6 ... A0 RW] */
    MCHP_I2C1_State++;
    break;

   case 10:
    I2C1CONbits.RCEN = 1;              /* RECEIVE sequence */
    MCHP_I2C1_State++;
    break;

   case 11:
    I2C1_Buff8[0] = I2C1RCV;           /* Read I2C data */
    I2C1CONbits.ACKDT = 1;             /* set to NACK */
    I2C1CONbits.ACKEN = 1;             /* Start Not Acknowledge sequence */
    MCHP_I2C1_State++;
    break;

   case 12:
    I2C1CONbits.PEN = 1;               /* STOP sequence*/
    MCHP_I2C1_State++;
    break;

   case 13:
    MCHP_I2C1_Request = 0;             /* Reset counter for error */
    MCHP_I2C1_State = 0;               /* End of I2C Sequence. I2C is available for a new sequence */
    break;

   default:                            /* Sequence finished */
    MCHP_I2C1_State = 0;               /* Should never happend */
    break;
  }                                    /* End of switch case sequence*/
}                                      /* Enf of interrupt */
