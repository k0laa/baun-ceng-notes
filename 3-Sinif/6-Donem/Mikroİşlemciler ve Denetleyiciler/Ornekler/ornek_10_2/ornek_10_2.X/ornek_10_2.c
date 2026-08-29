/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_10_2.c
 *
 * Code generated for Simulink model 'ornek_10_2'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Aug 29 21:36:28 2026
 */

#include "ornek_10_2.h"
#include "rtwtypes.h"
#include "ornek_10_2_private.h"

/* Block signals and states (default storage) */
DW_ornek_10_2_T ornek_10_2_DW;

/* Real-time model */
static RT_MODEL_ornek_10_2_T ornek_10_2_M_;
RT_MODEL_ornek_10_2_T *const ornek_10_2_M = &ornek_10_2_M_;

/* Model step function for TID0 */
void ornek_10_2_step0(void)            /* Sample time: [0.01s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void ornek_10_2_step1(void)            /* Sample time: [1.0s, 0.0s] */
{
  uint16_T rtb_DataTypeConversion1;
  uint8_T rtb_Output;

  /* UnitDelay: '<S1>/Output' */
  rtb_Output = ornek_10_2_DW.Output_DSTATE;

  /* Switch: '<S4>/FixPt Switch' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  Sum: '<S3>/FixPt Sum1'
   *  UnitDelay: '<S1>/Output'
   */
  ornek_10_2_DW.Output_DSTATE = (uint8_T)((uint8_T)(ornek_10_2_DW.Output_DSTATE + 1U) & 1);

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
      ornek_10_2_DW.UARTRx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_UART1 - 1);
      UART1LastValue = ornek_10_2_DW.UARTRx;
    } else {                           /* Buffer is empty */
      if (1U == U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* U1 Buffer Overflow cleared */
      ornek_10_2_DW.UARTRx = UART1LastValue;/* Rx buffer empty. fill-in output vector with repeated last value */
    }
  }                                    /* end of Rx reception block */

  /* Switch: '<Root>/Switch' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  UnitDelay: '<S1>/Output'
   */
  if (rtb_Output != 0) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Bias: '<Root>/Bias'
     *
     * Block description for '<Root>/Bias':
     *  aa
     */
    ornek_10_2_DW.Switch = (uint8_T)(ornek_10_2_DW.UARTRx + 1U);
  } else {
    /* Switch: '<Root>/Switch' */
    ornek_10_2_DW.Switch = ornek_10_2_DW.UARTRx;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = ornek_10_2_DW.Switch;

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATB = rtb_DataTypeConversion1;      /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_UART_Tx): '<Root>/UART Tx' */
  /* MCHP_UART_Tx Block: <Root>/UART Tx/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);/* head - tail - 1 */
    Tmp = Tmp & (Tx_BUFF_SIZE_UART1 - 1);
                                   /* Modulo Buffer Size (Buffer Size is 2^n). Tmp is the buffer free space */

    {
      uint_T LocalTail = MCHP_UART1_Tx.tail;
                                   /* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] = ornek_10_2_DW.Switch;
      MCHP_UART1_Tx.tail = (LocalTail + 1) & (Tx_BUFF_SIZE_UART1 - 1);
    }

    {
      uint_T LocalHead;
      int cpu_ipl_switchVar;
      cpu_ipl_switchVar = 5 << 5;      /* new IPL (SR bits 5,6,7) */
      cpu_ipl_switchVar ^= SR;         /* bit to reverse */
      cpu_ipl_switchVar &= 0xE0;       /* mask to not change other SR bits */
      SR ^= cpu_ipl_switchVar;         /* mimic Tx interrupt, disable Tx & thread switching interrupts */
      LocalHead = MCHP_UART1_Tx.head;
                                   /* Head is a volatile variable. Use local variable to speed-up execution */
      _U1TXIF = 0;                     /* Clear Interrupt Flag */
      while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while U1TXREG  buffer is not full */
      {
        U1TXREG = MCHP_UART1_Tx.buffer[LocalHead++];
        LocalHead &= (Tx_BUFF_SIZE_UART1-1);
      }

      MCHP_UART1_Tx.head = LocalHead;  /* Push back volatile variable */
      SR ^= cpu_ipl_switchVar;         /* stop mimic UART TX interrupt IPL level */
    }
  }
}

/* Model initialize function */
void ornek_10_2_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (ornek_10_2_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_10_2_M)->Timing.TaskCounters.cLimit[1] = 100;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_UART_Config): '<Root>/UART Configuration' */

  /* MCHP_UART_Config Block for UART 1: <Root>/UART Configuration/Initialize */
  U1BRG = 0x0411;                      /* Baud rate: 9600 (-0.03%) */
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
void ornek_10_2_terminate(void)
{
  /* Terminate for S-Function (MCHP_UART_Config): '<Root>/UART Configuration' */
  while (0U == U1STAbits.TRMT) ;       /* Wait until all byte are sent */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    struct {
      unsigned int Flags1 : 1;
    } static volatile Overrun __attribute__ ((near)) ;

    struct {
      unsigned int Flags1 : 1;
    } static volatile event __attribute__ ((near)) ;

    struct {
      uint_T Task1;                    /* 1.0s periodic task. Max value is 100 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (100 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 100;/* 1.0s periodic task. Max value is 100 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_10_2_step0();

    /* Get model outputs here */
    if (_T1IF ) {
      return;                          /* Will re-enter into the interrupt */
    }

    /* Re-Enable Interrupt. IPL value is 2 at this point */
    {
      _IPL0 = 1;                       /* Enable Scheduler re-entrant interrupt. Lower IPL from 2 to 1 */
      _IPL1 = 0;
    }

    /* Step the model for any subrate */
    /* ---------- Handle Task 1 ---------- */
    if (Overrun.Flags1) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags1) {             /* Execute task tid 1 */
      Overrun.Flags1 = 1U;
      event.Flags1 = 0U;
      ornek_10_2_step1();

      /* Get model outputs here */
    }

    Overrun.Flags1 = 0U;

    /* Disable Interrupt. IPL value is 1 at this point */
    {
      _IPL1 = 1;                       /* Disable Scheduler Interrupts. Rise IPL from 1 to 2 */
      _IPL0 = 0;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
