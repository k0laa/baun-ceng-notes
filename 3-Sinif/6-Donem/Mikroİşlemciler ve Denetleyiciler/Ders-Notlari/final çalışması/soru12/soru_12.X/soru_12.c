/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_12.c
 *
 * Code generated for Simulink model 'soru_12'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 13:04:14 2026
 */

#include "soru_12.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Block signals and states (default storage) */
DW_soru_12_T soru_12_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_soru_12_T soru_12_PrevZCX;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void soru_12_step(void)
{
  int16_T rowIdx;
  boolean_T rtb_OR;
  boolean_T rtb_TmpLatchAtJKFlipFlopInport1;
  boolean_T rtb_TmpLatchAtJKFlipFlopInport2;

  /* Memory generated from: '<S2>/J-K Flip-Flop' */
  rtb_TmpLatchAtJKFlipFlopInport1 = soru_12_DW.bitsForTID0.TmpLatchAtJKFlipFlopInport1_PreviousInput;

  /* Memory generated from: '<S2>/J-K Flip-Flop' */
  rtb_TmpLatchAtJKFlipFlopInport2 = soru_12_DW.bitsForTID0.TmpLatchAtJKFlipFlopInport2_PreviousInput;

  /* Logic: '<Root>/OR' incorporates:
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rtb_OR = (PORTCbits.RC0 || PORTCbits.RC1 || PORTCbits.RC2 || PORTCbits.RC3);

  /* Outputs for Triggered SubSystem: '<S2>/J-K Flip-Flop' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  if ((!rtb_OR) && (soru_12_PrevZCX.JKFlipFlop_Trig_ZCE != ZERO_ZCSIG)) {
    /* CombinatorialLogic: '<S3>/Logic' incorporates:
     *  Memory: '<S3>/Memory'
     */
    rowIdx = (int16_T)(((((uint16_T)soru_12_DW.bitsForTID0.Memory_PreviousInput << 1) +
                         rtb_TmpLatchAtJKFlipFlopInport1) << 1) + rtb_TmpLatchAtJKFlipFlopInport2);
    soru_12_DW.Logic[0U] = soru_12_ConstP.Logic_table[(uint16_T)rowIdx];
    soru_12_DW.Logic[1U] = soru_12_ConstP.Logic_table[(uint16_T)rowIdx + 8U];

    /* Update for Memory: '<S3>/Memory' */
    soru_12_DW.bitsForTID0.Memory_PreviousInput = soru_12_DW.Logic[0];
  }

  soru_12_PrevZCX.JKFlipFlop_Trig_ZCE = rtb_OR;

  /* End of Outputs for SubSystem: '<S2>/J-K Flip-Flop' */

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = soru_12_DW.Logic[0];

  /* Update for Memory generated from: '<S2>/J-K Flip-Flop' */
  soru_12_DW.bitsForTID0.TmpLatchAtJKFlipFlopInport1_PreviousInput = rtb_OR;

  /* Update for Memory generated from: '<S2>/J-K Flip-Flop' */
  soru_12_DW.bitsForTID0.TmpLatchAtJKFlipFlopInport2_PreviousInput = rtb_OR;
}

/* Model initialize function */
void soru_12_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void soru_12_terminate(void)
{
  /* (no terminate code required) */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) ) ;/* Atomic bit-set: ContinueTimeStep |= 1U */
    _T1IF = 0;                         /* Re-enable interrupt */
  }
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  for (;;) {                           /* Infinite loop, no return */
    while (!ContinueTimeStep) ;

    /* Disable Scheduler Interrupt */
    _IPL0 = 1;                         /* Disable Scheduler Interrupts. Rise IPL from 0 to 1 */
    __asm__ volatile ("BCLR.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) );/* Atomic bit-clear of ContinueTimeStep bit 1U */

    /* Call model Scheduler */
    /* Step the model for base rate */
    soru_12_step();

    /* Get model outputs here */

    /* Re-Enable Scheduler Interrupt */
    _IPL0 = 0;                         /* Enable Scheduler interrupt. Lower IPL from 1 to 0 */
  }                                    /* end infinite loop for(;;) */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
