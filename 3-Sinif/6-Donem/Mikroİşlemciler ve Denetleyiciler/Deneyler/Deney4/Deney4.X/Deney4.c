/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Deney4.c
 *
 * Code generated for Simulink model 'Deney4'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Mar 24 22:06:11 2026
 */

#include "Deney4.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Deney4_private.h"
#include "rtwtypes.h"
#include <float.h>

/* Block signals and states (default storage) */
DW_Deney4_T Deney4_DW;
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
void Deney4_step(void)
{
  real_T rtb_Memory;
  real_T tmp;
  uint16_T rtb_DataTypeConversion;
  uint16_T rtb_DataTypeConversion1;
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_LogicalOperator1;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = Deney4_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Gain: '<Root>/Gain'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   *  Rounding: '<Root>/Fix'
   */
  tmp = floor(Deney4_ConstP.Constant3_Value[(int16_T)floor(0.1 * Deney4_DW.Memory_PreviousInput)]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1 = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Math: '<Root>/Mod'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  tmp = floor(Deney4_ConstP.Constant3_Value[(int16_T)rt_modd_snf(Deney4_DW.Memory_PreviousInput, 10.0)]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATC = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATB = rtb_DataTypeConversion1;      /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTAbits.RA9; /* Read pin A9 */

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  RelationalOperator: '<Root>/Relational Operator1'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rtb_LogicalOperator1 = (PORTAbits.RA10 || (rtb_Memory >= 100.0));

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Memory: '<S3>/Memory'
   */
  rtb_DigitalInput_o1 = Deney4_ConstP.Logic_table[((((uint16_T)rtb_DigitalInput_o1 << 1) +
    rtb_LogicalOperator1) << 1) + Deney4_DW.bitsForTID0.Memory_PreviousInput_p];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_LogicalOperator1) {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant'
     */
    Deney4_DW.Memory_PreviousInput = 0.0;
  } else if (rtb_DigitalInput_o1) {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Memory: '<Root>/Memory'
     *  Sum: '<Root>/Sum'
     */
    Deney4_DW.Memory_PreviousInput = rtb_Memory + 0.01;
  } else {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Switch: '<Root>/Switch3'
     */
    Deney4_DW.Memory_PreviousInput = rtb_Memory;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Update for Memory: '<S3>/Memory' */
  Deney4_DW.bitsForTID0.Memory_PreviousInput_p = rtb_DigitalInput_o1;
}

/* Model initialize function */
void Deney4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void Deney4_terminate(void)
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
    Deney4_step();

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
