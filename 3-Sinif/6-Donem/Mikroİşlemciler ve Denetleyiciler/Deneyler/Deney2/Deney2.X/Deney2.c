/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Deney2.c
 *
 * Code generated for Simulink model 'Deney2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Mar  4 17:06:03 2026
 */

#include "Deney2.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_Deney2_T Deney2_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void Deney2_step(void)
{
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_Logic_a[2];
  boolean_T rtb_Logic_l[2];
  boolean_T rtb_DigitalInput_o4;
  boolean_T rtb_Memory_a;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o4 = PORTCbits.RC3; /* Read pin C3 */

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory1'
   *  Memory: '<Root>/Memory2'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  if (Deney2_DW.bitsForTID0.Memory2_PreviousInput) {
    rtb_Memory_a = false;
  } else {
    rtb_Memory_a = ((!Deney2_DW.bitsForTID0.Memory1_PreviousInput) && PORTCbits.RC0);
  }

  /* End of Switch: '<Root>/Switch3' */

  /* CombinatorialLogic: '<S2>/Logic' incorporates:
   *  Memory: '<S2>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_Memory_a << 1) + rtb_DigitalInput_o4) << 1) +
                     Deney2_DW.bitsForTID0.Memory_PreviousInput);
  rtb_Logic[0U] = Deney2_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic[1U] = Deney2_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Memory: '<Root>/Memory'
   *  Memory: '<Root>/Memory2'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  if (Deney2_DW.bitsForTID0.Memory2_PreviousInput) {
    rtb_Memory_a = false;
  } else {
    rtb_Memory_a = ((!Deney2_DW.bitsForTID0.Memory_PreviousInput_a) && PORTCbits.RC1);
  }

  /* End of Switch: '<Root>/Switch4' */

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Memory: '<S3>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_Memory_a << 1) + rtb_DigitalInput_o4) << 1) +
                     Deney2_DW.bitsForTID0.Memory_PreviousInput_d);
  rtb_Logic_l[0U] = Deney2_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic_l[1U] = Deney2_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* Switch: '<Root>/Switch5' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Memory: '<Root>/Memory'
   *  Memory: '<Root>/Memory1'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  if (Deney2_DW.bitsForTID0.Memory1_PreviousInput) {
    rtb_Memory_a = false;
  } else {
    rtb_Memory_a = ((!Deney2_DW.bitsForTID0.Memory_PreviousInput_a) && PORTCbits.RC2);
  }

  /* End of Switch: '<Root>/Switch5' */

  /* CombinatorialLogic: '<S4>/Logic' incorporates:
   *  Memory: '<S4>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_Memory_a << 1) + rtb_DigitalInput_o4) << 1) +
                     Deney2_DW.bitsForTID0.Memory_PreviousInput_i);
  rtb_Logic_a[0U] = Deney2_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic_a[1U] = Deney2_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Logic[0];
  LATBbits.LATB1 = rtb_Logic_l[0];
  LATBbits.LATB2 = rtb_Logic_a[0];

  /* Update for Memory: '<Root>/Memory2' */
  Deney2_DW.bitsForTID0.Memory2_PreviousInput = rtb_Logic_a[0];

  /* Update for Memory: '<Root>/Memory1' */
  Deney2_DW.bitsForTID0.Memory1_PreviousInput = rtb_Logic_l[0];

  /* Update for Memory: '<S2>/Memory' */
  Deney2_DW.bitsForTID0.Memory_PreviousInput = rtb_Logic[0];

  /* Update for Memory: '<Root>/Memory' */
  Deney2_DW.bitsForTID0.Memory_PreviousInput_a = rtb_Logic[0];

  /* Update for Memory: '<S3>/Memory' */
  Deney2_DW.bitsForTID0.Memory_PreviousInput_d = rtb_Logic_l[0];

  /* Update for Memory: '<S4>/Memory' */
  Deney2_DW.bitsForTID0.Memory_PreviousInput_i = rtb_Logic_a[0];
}

/* Model initialize function */
void Deney2_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void Deney2_terminate(void)
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
    Deney2_step();

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
