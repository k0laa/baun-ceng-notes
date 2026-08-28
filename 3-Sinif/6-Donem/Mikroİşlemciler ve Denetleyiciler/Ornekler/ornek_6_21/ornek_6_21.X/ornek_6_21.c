/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_21.c
 *
 * Code generated for Simulink model 'ornek_6_21'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 09:45:40 2026
 */

#include "ornek_6_21.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_21_T ornek_6_21_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_6_21_step(void)
{
  /* local block i/o variables */
  uint16_T rtb_DigitalInput;
  real_T rtb_MultiportSwitch[5];
  real_T rtb_Output_tmp;
  real_T tmp;
  real32_T rtb_Memory;
  int16_T i;
  uint16_T rtb_DataTypeConversion;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = ornek_6_21_DW.Memory_PreviousInput;

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   */
  switch ((int16_T)ornek_6_21_DW.Memory_PreviousInput) {
   case 0:
    for (i = 0; i < 5; i++) {
      rtb_MultiportSwitch[i] = 255.0;
    }
    break;

   case 1:
    for (i = 0; i < 5; i++) {
      rtb_MultiportSwitch[i] = ornek_6_21_ConstP.Constant_Value[i];
    }
    break;

   case 2:
    for (i = 0; i < 5; i++) {
      rtb_MultiportSwitch[i] = ornek_6_21_ConstP.Constant1_Value[i];
    }
    break;

   default:
    for (i = 0; i < 5; i++) {
      rtb_MultiportSwitch[i] = ornek_6_21_ConstP.Constant2_Value[i];
    }
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* MultiPortSwitch: '<S6>/Output' incorporates:
   *  Constant: '<S6>/Vector'
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  UnitDelay: '<S7>/Output'
   */
  rtb_Output_tmp = ornek_6_21_ConstP.Vector_Value[ornek_6_21_DW.Output_DSTATE];

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  tmp = floor(ornek_6_21_ConstP.Constant3_Value[(int16_T)rtb_Output_tmp - 1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   */
  tmp = floor(rtb_MultiportSwitch[(int16_T)rtb_Output_tmp - 1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* S-Function (MCHP_Digital_Output_Write): '<S5>/Digital Output Write' */
  LATC = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTA;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant9'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   *  Switch: '<Root>/Switch'
   *  Switch: '<Root>/Switch1'
   */
  if (rtb_DigitalInput == 1024U) {
    rtb_Memory = 3.0F;
  } else if (rtb_DigitalInput == 512U) {
    /* Switch: '<Root>/Switch1' */
    rtb_Memory = 2.0F;
  } else if (rtb_DigitalInput == 256U) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Switch: '<Root>/Switch1'
     */
    rtb_Memory = 1.0F;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Switch: '<S9>/FixPt Switch' incorporates:
   *  Constant: '<S8>/FixPt Constant'
   *  Constant: '<S9>/Constant'
   *  Sum: '<S8>/FixPt Sum1'
   *  UnitDelay: '<S7>/Output'
   */
  if ((uint8_T)(ornek_6_21_DW.Output_DSTATE + 1U) > 4) {
    ornek_6_21_DW.Output_DSTATE = 0U;
  } else {
    ornek_6_21_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S9>/FixPt Switch' */
  /* Update for Memory: '<Root>/Memory' */
  ornek_6_21_DW.Memory_PreviousInput = rtb_Memory;
}

/* Model initialize function */
void ornek_6_21_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_21_terminate(void)
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
    ornek_6_21_step();

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
