/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_18.c
 *
 * Code generated for Simulink model 'ornek_6_18'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Aug 27 18:22:04 2026
 */

#include "ornek_6_18.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "ornek_6_18_private.h"
#include "rtwtypes.h"
#include <float.h>

/* Block signals and states (default storage) */
DW_ornek_6_18_T ornek_6_18_DW;

/* Real-time model */
static RT_MODEL_ornek_6_18_T ornek_6_18_M_;
RT_MODEL_ornek_6_18_T *const ornek_6_18_M = &ornek_6_18_M_;
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

/* Model step function for TID0 */
void ornek_6_18_step0(void)            /* Sample time: [0.01s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void ornek_6_18_step1(void)            /* Sample time: [0.02s, 0.0s] */
{
  real_T rtb_Output_tmp;
  real_T tmp;
  int16_T rtb_IndexVector;
  uint16_T rtb_DataTypeConversion3;
  uint16_T rtb_DigitalInput;

  /* MultiPortSwitch: '<S3>/Output' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   *  UnitDelay: '<S4>/Output'
   */
  rtb_Output_tmp = ornek_6_18_ConstP.Vector_Value[ornek_6_18_DW.Output_DSTATE];

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant4'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   */
  tmp = floor(ornek_6_18_ConstP.Constant4_Value[(int16_T)rtb_Output_tmp - 1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion3 = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion3' */
  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTC;

  /* MultiPortSwitch: '<Root>/Index Vector' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S3>/Vector'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   *  Math: '<Root>/Mod'
   *  Math: '<Root>/Mod1'
   *  Math: '<Root>/Mod2'
   *  Math: '<Root>/Mod3'
   *  MultiPortSwitch: '<S3>/Output'
   *  Rounding: '<Root>/Fix1'
   *  Rounding: '<Root>/Fix2'
   *  Rounding: '<Root>/Fix3'
   */
  switch ((int16_T)rtb_Output_tmp) {
   case 1:
    rtb_IndexVector = (int16_T)rt_modd_snf((real_T)rtb_DigitalInput, 10.0);
    break;

   case 2:
    rtb_IndexVector = (int16_T)rt_modd_snf(floor(0.1 * (real_T)rtb_DigitalInput), 10.0);
    break;

   case 3:
    rtb_IndexVector = (int16_T)rt_modd_snf(floor(0.01 * (real_T)rtb_DigitalInput), 10.0);
    break;

   default:
    rtb_IndexVector = (int16_T)rt_modd_snf(floor(0.001 * (real_T)rtb_DigitalInput), 10.0);
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Index Vector' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_DigitalInput = (uint16_T)rtb_IndexVector;

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_DigitalInput;             /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATA = rtb_DataTypeConversion3;      /* No mask required : all pins defined as digital output are updated */

  /* Switch: '<S6>/FixPt Switch' incorporates:
   *  Constant: '<S5>/FixPt Constant'
   *  Constant: '<S6>/Constant'
   *  Sum: '<S5>/FixPt Sum1'
   *  UnitDelay: '<S4>/Output'
   */
  if ((uint8_T)(ornek_6_18_DW.Output_DSTATE + 1U) > 3) {
    ornek_6_18_DW.Output_DSTATE = 0U;
  } else {
    ornek_6_18_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S6>/FixPt Switch' */
}

/* Model initialize function */
void ornek_6_18_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (ornek_6_18_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_6_18_M)->Timing.TaskCounters.cLimit[1] = 2;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_18_terminate(void)
{
  /* (no terminate code required) */
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
      uint_T Task1;                    /* 0.02s periodic task. Max value is 2 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (2 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 2;/* 0.02s periodic task. Max value is 2 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_6_18_step0();

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
      ornek_6_18_step1();

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
