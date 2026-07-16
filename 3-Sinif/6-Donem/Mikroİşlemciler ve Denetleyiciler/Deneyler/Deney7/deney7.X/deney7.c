/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney7.c
 *
 * Code generated for Simulink model 'deney7'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May  6 13:54:10 2026
 */

#include "deney7.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_deney7_T deney7_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void deney7_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput;
  real_T rtb_Memory;
  real_T tmp;
  uint16_T rtb_DataTypeConversion;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = deney7_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  tmp = floor(deney7_ConstP.Constant3_Value[(int16_T)deney7_DW.Memory_PreviousInput]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTDbits.RD0;    /* Read pin D0 */

  /* Outputs for Enabled SubSystem: '<S3>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (deney7_ConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
     *  UnitDelay: '<S3>/Unit Delay'
     */
    deney7_DW.bitsForTID0.RelationalOperator1 = ((int16_T)rtb_DigitalInput > (int16_T)
      deney7_DW.bitsForTID0.UnitDelay_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S3>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S3>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (deney7_ConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S4>/Relational Operator1' incorporates:
     *  UnitDelay: '<S3>/Unit Delay'
     */
    deney7_DW.bitsForTID0.RelationalOperator1_l = ((int16_T)deney7_DW.bitsForTID0.UnitDelay_DSTATE > (int16_T)
      rtb_DigitalInput);
  }

  /* End of Outputs for SubSystem: '<S3>/NEGATIVE Edge' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Logic: '<S3>/Logical Operator1'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  Switch: '<Root>/Switch'
   */
  if (rtb_Memory == 4.0) {
    rtb_Memory = 0.0;
  } else if (deney7_DW.bitsForTID0.RelationalOperator1 || deney7_DW.bitsForTID0.RelationalOperator1_l) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    rtb_Memory++;
  }

  /* End of Switch: '<Root>/Switch1' */
  /* Update for Memory: '<Root>/Memory' */
  deney7_DW.Memory_PreviousInput = rtb_Memory;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  deney7_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput;
}

/* Model initialize function */
void deney7_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void deney7_terminate(void)
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
    deney7_step();

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
