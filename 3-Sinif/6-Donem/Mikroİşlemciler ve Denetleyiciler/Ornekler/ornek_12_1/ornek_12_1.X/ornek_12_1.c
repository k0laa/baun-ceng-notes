/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_12_1.c
 *
 * Code generated for Simulink model 'ornek_12_1'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 13:17:10 2026
 */

#include "ornek_12_1.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_12_1_T ornek_12_1_DW;

/* Model step function */
void ornek_12_1_step(void)
{
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_Logic_j[2];
  boolean_T rtb_DigitalInput_o2;
  boolean_T rtb_DigitalInput_o3;
  boolean_T rtb_OR;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_OR = PORTCbits.RC0;              /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */
  rtb_DigitalInput_o3 = PORTCbits.RC2; /* Read pin C2 */

  /* CombinatorialLogic: '<S2>/Logic' incorporates:
   *  Logic: '<Root>/OR1'
   *  Memory: '<S2>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_OR << 1) + (uint16_T)(rtb_DigitalInput_o3 || rtb_DigitalInput_o2)) << 1)
                     + ornek_12_1_DW.bitsForTID0.Memory_PreviousInput);
  rtb_Logic[0U] = ornek_12_1_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic[1U] = ornek_12_1_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Logic: '<Root>/OR'
   *  Memory: '<S3>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_DigitalInput_o2 << 1) + (uint16_T)(rtb_OR || rtb_DigitalInput_o3)) << 1)
                     + ornek_12_1_DW.bitsForTID0.Memory_PreviousInput_a);
  rtb_Logic_j[0U] = ornek_12_1_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic_j[1U] = ornek_12_1_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* Logic: '<Root>/OR2' */
  rtb_OR = (rtb_Logic[0] || rtb_Logic_j[0]);

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Logic[0];
  LATBbits.LATB1 = rtb_Logic_j[0];
  LATBbits.LATB2 = rtb_OR;

  /* Update for Memory: '<S2>/Memory' */
  ornek_12_1_DW.bitsForTID0.Memory_PreviousInput = rtb_Logic[0];

  /* Update for Memory: '<S3>/Memory' */
  ornek_12_1_DW.bitsForTID0.Memory_PreviousInput_a = rtb_Logic_j[0];
}

/* Model initialize function */
void ornek_12_1_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_12_1_terminate(void)
{
  /* (no terminate code required) */
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
  ornek_12_1_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
