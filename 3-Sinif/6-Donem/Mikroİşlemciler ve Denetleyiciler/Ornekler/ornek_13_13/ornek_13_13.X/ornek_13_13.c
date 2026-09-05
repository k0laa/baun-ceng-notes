/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_13.c
 *
 * Code generated for Simulink model 'ornek_13_13'.
 *
 * Model version                  : 1.41
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 19:27:35 2026
 */

#include "ornek_13_13.h"
#include "ornek_13_13_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <float.h>

/* Block signals and states (default storage) */
DW_ornek_13_13_T ornek_13_13_DW;

/* Real-time model */
static RT_MODEL_ornek_13_13_T ornek_13_13_M_;
RT_MODEL_ornek_13_13_T *const ornek_13_13_M = &ornek_13_13_M_;
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
void ornek_13_13_step0(void)           /* Sample time: [1.0E-5s, 0.0s] */
{
  real_T rtb_Mod;
  real_T tmp;

  /* Math: '<Root>/Mod' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Memory: '<Root>/Memory'
   */
  rtb_Mod = rt_modd_snf(ornek_13_13_DW.Memory_PreviousInput, 1024.0);

  /* MultiPortSwitch: '<Root>/Index Vector' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  ornek_13_13_DW.IndexVector = ornek_13_13_ConstP.Constant2_Value[(int16_T)rtb_Mod];

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S1>/FixPt Constant'
   *  Gain: '<Root>/Gain'
   *  Math: '<Root>/Mod1'
   *  Rounding: '<Root>/Floor'
   *  Sum: '<S1>/FixPt Sum1'
   */
  tmp = rt_modd_snf(floor(0.015625 * rtb_Mod), 2.0) + 1.0;
  if (rtIsNaN(tmp)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    ornek_13_13_DW.DataTypeConversion = 0;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    ornek_13_13_DW.DataTypeConversion = (int16_T)tmp;
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Math: '<Root>/Mod2'
   */
  tmp = floor(rt_modd_snf(rtb_Mod, 64.0));
  if (rtIsNaN(tmp)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    ornek_13_13_DW.DataTypeConversion1 = 0;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    ornek_13_13_DW.DataTypeConversion1 = (int16_T)tmp;
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Gain: '<Root>/Gain1'
   *  Math: '<Root>/Mod3'
   *  Rounding: '<Root>/Floor1'
   */
  tmp = rt_modd_snf(floor(0.0078125 * rtb_Mod), 8.0);
  if (rtIsNaN(tmp)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    ornek_13_13_DW.DataTypeConversion2 = 0;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    ornek_13_13_DW.DataTypeConversion2 = (int16_T)tmp;
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */
  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  ekrana_yaz(
             ornek_13_13_DW.DataTypeConversion
             , ornek_13_13_DW.DataTypeConversion1
             , ornek_13_13_DW.DataTypeConversion2
             , ornek_13_13_DW.IndexVector
             );

  /* Update for Memory: '<Root>/Memory' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   */
  ornek_13_13_DW.Memory_PreviousInput = rtb_Mod + 1.0;
}

/* Model step function for TID1 */
void ornek_13_13_step1(void)           /* Sample time: [1.0s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void ornek_13_13_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (ornek_13_13_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_13_13_M)->Timing.TaskCounters.cLimit[1] = 100000;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_C_function_Call): '<Root>/C Function Call1' */
  glcd_hazirla(
               );
}

/* Model terminate function */
void ornek_13_13_terminate(void)
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
      uint32_T Task1;                  /* 1.0s periodic task. Max value is 100000 (ensure 32 bit) */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (100000 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint32_T) 100000;/* 1.0s periodic task. Max value is 100000 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_13_13_step0();

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
      ornek_13_13_step1();

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
