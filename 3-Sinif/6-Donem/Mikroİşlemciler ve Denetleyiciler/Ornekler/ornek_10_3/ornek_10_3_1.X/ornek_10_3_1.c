/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_10_3_1.c
 *
 * Code generated for Simulink model 'ornek_10_3_1'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Aug 29 21:42:41 2026
 */

#include "ornek_10_3_1.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ornek_10_3_1_private.h"

/* Block signals and states (default storage) */
DW_ornek_10_3_1_T ornek_10_3_1_DW;

/* Real-time model */
static RT_MODEL_ornek_10_3_1_T ornek_10_3_1_M_;
RT_MODEL_ornek_10_3_1_T *const ornek_10_3_1_M = &ornek_10_3_1_M_;

/* Model step function for TID0 */
void ornek_10_3_1_step0(void)          /* Sample time: [0.01s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void ornek_10_3_1_step1(void)          /* Sample time: [0.05s, 0.0s] */
{
  real_T tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Vector'
   *  MultiPortSwitch: '<S1>/Output'
   *  UnitDelay: '<S2>/Output'
   */
  tmp = floor(ornek_10_3_1_ConstP.Vector_Value[ornek_10_3_1_DW.Output_DSTATE]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  ornek_10_3_1_DW.DataTypeConversion = (uint8_T)(tmp < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-tmp :
    (int16_T)(uint8_T)tmp);

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
      MCHP_UART1_Tx.buffer[LocalTail] = ornek_10_3_1_DW.DataTypeConversion;
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

  /* Switch: '<S4>/FixPt Switch' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  Constant: '<S4>/Constant'
   *  Sum: '<S3>/FixPt Sum1'
   *  UnitDelay: '<S2>/Output'
   */
  if ((uint8_T)(ornek_10_3_1_DW.Output_DSTATE + 1U) > 13) {
    ornek_10_3_1_DW.Output_DSTATE = 0U;
  } else {
    ornek_10_3_1_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S4>/FixPt Switch' */
}

/* Model initialize function */
void ornek_10_3_1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (ornek_10_3_1_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_10_3_1_M)->Timing.TaskCounters.cLimit[1] = 5;

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
void ornek_10_3_1_terminate(void)
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
      uint_T Task1;                    /* 0.05s periodic task. Max value is 5 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (5 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 5;/* 0.05s periodic task. Max value is 5 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_10_3_1_step0();

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
      ornek_10_3_1_step1();

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
