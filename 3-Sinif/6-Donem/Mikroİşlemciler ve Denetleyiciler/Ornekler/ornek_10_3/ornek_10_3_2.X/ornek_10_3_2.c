/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_10_3_2.c
 *
 * Code generated for Simulink model 'ornek_10_3_2'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Aug 29 21:46:31 2026
 */

#include "ornek_10_3_2.h"
#include "rtwtypes.h"
#include "ornek_10_3_2_private.h"

/* Block signals and states (default storage) */
DW_ornek_10_3_2_T ornek_10_3_2_DW;

/* Model step function */
void ornek_10_3_2_step(void)
{
  uint16_T rtb_DataTypeConversion;

  /* S-Function (MCHP_UART_Rx): '<Root>/UART Rx' */
  /* MCHP_UART_Rx Block: <Root>/UART Rx/Outputs */
  /* Circular Buffer implementation for UART1 */
  /* Circular Buffer implementation for UART1 */
  {                                    /* Start of Rx reception block */
    static uint8_T UART1LastValue ;
    if (0U != U1STAbits.URXDA) {       /* Flush internal UART buffer */
      uint_T Tmp;
      int cpu_ipl_switchVar;
      cpu_ipl_switchVar = 5 << 5;      /* new IPL (SR bits 5,6,7) */
      cpu_ipl_switchVar ^= SR;         /* bit to reverse */
      cpu_ipl_switchVar &= 0xE0;       /* mask to not change other SR bits */
      SR ^= cpu_ipl_switchVar;         /* mimic Rx interrupt, disable Tx & thread switching interrupts */

      {
        uint_T LocalTail = MCHP_UART1_Rx.tail;
        Tmp = ~(LocalTail - MCHP_UART1_Rx.head);/* head - tail - 1 */
        Tmp &= (Rx_BUFF_SIZE_UART1 - 1);
        /* Tmp =  (head - tail - 1) modulo buffersize Rx_BUFF_SIZE_UART1)	<==> Rx_BUFF_SIZE_UART1 - (head - tail) - 1*/
        _U1RXIF = 0;                   /* Reset interrupt */
        while (0U != U1STAbits.URXDA) {
          if (0U != Tmp) {
            Tmp--;
            MCHP_UART1_Rx.buffer[LocalTail++] = (uint8_T) U1RXREG;
            LocalTail = (LocalTail) & (Rx_BUFF_SIZE_UART1 - 1);
          } else {
            do
              U1RXREG;
            while (0U != U1STAbits.URXDA);
            break;
          }
        }

        MCHP_UART1_Rx.tail = LocalTail;/* push back volatile variable */
      }

      SR ^= cpu_ipl_switchVar;         /* stop mimic UART RX interrupt IPL level */
    }

    if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head) {
      ornek_10_3_2_DW.UARTRx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_UART1 - 1);
      UART1LastValue = ornek_10_3_2_DW.UARTRx;
    } else {                           /* Buffer is empty */
      if (1U == U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* U1 Buffer Overflow cleared */
      ornek_10_3_2_DW.UARTRx = UART1LastValue;/* Rx buffer empty. fill-in output vector with repeated last value */
    }
  }                                    /* end of Rx reception block */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_DataTypeConversion = ornek_10_3_2_DW.UARTRx;

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */
}

/* Model initialize function */
void ornek_10_3_2_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_UART_Config): '<Root>/UART Configuration' */

  /* MCHP_UART_Config Block for UART 1: <Root>/UART Configuration/Initialize */
  U1BRG = 0x56;                        /* Baud rate: 115200 (-0.22%) */
  U1MODE = 0x8008;
  U1STA = 0x8400;

  /* Configure UART1 using Tx Interruption */
  _U1TXIP = 5;                         /*  Tx Interrupt priority set to 5 */
  _U1TXIF = 0;                         /*  */
  _U1TXIE = 1;                         /* Enable Interrupt */

  /* Configure UART1 Rx Interruption for <Root>/UART Configuration */
  _U1RXIP = 5;                         /* Rx Interrupt priority set to 5 */
  _U1RXIF = 0;                         /*  */
  _U1RXIE = 1;                         /* Enable Interrupt */
}

/* Model terminate function */
void ornek_10_3_2_terminate(void)
{
  /* Terminate for S-Function (MCHP_UART_Config): '<Root>/UART Configuration' */
  while (0U == U1STAbits.TRMT) ;       /* Wait until all byte are sent */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    /* Re-enable timer or interrupt */
    _T1IF = 0;                         /*  */
    MCHP_Scheduler();
  }
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  /* Call model Scheduler */

  /* Step the model for base rate */
  ornek_10_3_2_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
