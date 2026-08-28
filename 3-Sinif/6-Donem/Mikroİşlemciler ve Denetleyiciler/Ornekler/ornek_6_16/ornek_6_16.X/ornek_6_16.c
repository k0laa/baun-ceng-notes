/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_16.c
 *
 * Code generated for Simulink model 'ornek_6_16'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Aug 26 22:35:41 2026
 */

#include "ornek_6_16.h"
#include "ornek_6_16_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <float.h>

/* Block signals and states (default storage) */
DW_ornek_6_16_T ornek_6_16_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void ornek_6_16_step(void)
{
  real_T rtb_Memory;
  real_T tmp;
  uint16_T rtb_DataTypeConversion1;
  uint16_T rtb_DataTypeConversion2;
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = ornek_6_16_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant5'
   *  Math: '<Root>/Mod'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   */
  tmp = floor(ornek_6_16_ConstP.Constant3_Value[(int16_T)rt_modd_snf(ornek_6_16_DW.Memory_PreviousInput, 10.0)]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion2 = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Gain: '<Root>/Gain'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  Rounding: '<Root>/Fix'
   */
  tmp = floor(ornek_6_16_ConstP.Constant3_Value[(int16_T)floor(0.1 * ornek_6_16_DW.Memory_PreviousInput)]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1 = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */
  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_DataTypeConversion1;      /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATC = rtb_DataTypeConversion2;      /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTAbits.RA9; /* Read pin A9 */
  rtb_DigitalInput_o2 = PORTAbits.RA10;/* Read pin A10 */

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Logic: '<Root>/Logical Operator'
   *  Memory: '<S3>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  rtb_DigitalInput_o1 = ornek_6_16_ConstP.Logic_table[(((uint16_T)(rtb_DigitalInput_o2 || (rtb_Memory >= 100.0))
    + ((uint16_T)rtb_DigitalInput_o1 << 1)) << 1) + ornek_6_16_DW.bitsForTID0.Memory_PreviousInput_k];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Switch: '<Root>/Switch'
   */
  if (rtb_DigitalInput_o2) {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    ornek_6_16_DW.Memory_PreviousInput = 0.0;
  } else if (rtb_DigitalInput_o1) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Memory: '<Root>/Memory'
     *  Sum: '<Root>/Sum'
     */
    ornek_6_16_DW.Memory_PreviousInput = rtb_Memory + 0.01;
  } else {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Switch: '<Root>/Switch'
     */
    ornek_6_16_DW.Memory_PreviousInput = rtb_Memory;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Update for Memory: '<S3>/Memory' */
  ornek_6_16_DW.bitsForTID0.Memory_PreviousInput_k = rtb_DigitalInput_o1;
}

/* Model initialize function */
void ornek_6_16_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_16_terminate(void)
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
    ornek_6_16_step();

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
