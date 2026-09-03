/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_8.c
 *
 * Code generated for Simulink model 'soru_8'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 11:20:11 2026
 */

#include "soru_8.h"
#include "soru_8_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <float.h>

/* Block signals and states (default storage) */
DW_soru_8_T soru_8_DW;

/* Real-time model */
static RT_MODEL_soru_8_T soru_8_M_;
RT_MODEL_soru_8_T *const soru_8_M = &soru_8_M_;
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

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function for TID0 */
void soru_8_step0(void)                /* Sample time: [1.0E-5s, 0.0s] */
{
  real_T rtb_Mod;
  real_T rtb_Mod2;
  real_T rtb_Mod3;
  real_T rtb_Switch;

  /* Math: '<Root>/Mod' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Memory: '<Root>/Memory'
   */
  rtb_Mod = rt_modd_snf(soru_8_DW.Memory_PreviousInput, 1024.0);

  /* Math: '<Root>/Mod3' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  rtb_Mod3 = rt_modd_snf(rtb_Mod, 64.0);

  /* Math: '<Root>/Mod2' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Gain: '<Root>/Gain'
   *  Rounding: '<Root>/Fix'
   */
  rtb_Mod2 = rt_modd_snf(floor(0.015625 * rtb_Mod), 2.0);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant7'
   *  Math: '<Root>/Mod1'
   *  Sum: '<Root>/Sum1'
   */
  if (rtb_Mod2 > 0.0) {
    rtb_Switch = rt_modd_snf(rtb_Mod, 8.0);
  } else {
    rtb_Switch = 7.0 - rt_modd_snf(rtb_Mod, 8.0);
  }

  /* End of Switch: '<Root>/Switch' */

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant9'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Gain: '<Root>/Gain2'
   *  Logic: '<Root>/Logical Operator'
   *  Math: '<Root>/Power'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   *  Rounding: '<Root>/Fix2'
   *  Switch: '<Root>/Switch1'
   */
  if ((rtb_Mod3 == 0.0) || (rtb_Mod3 == 63.0)) {
    rtb_Switch = 0.0;
  } else {
    if (floor(0.001953125 * rtb_Mod) > 0.0) {
      /* Switch: '<Root>/Switch1' incorporates:
       *  Constant: '<Root>/Constant8'
       *  Sum: '<Root>/Sum2'
       */
      rtb_Switch = 7.0 - rtb_Switch;
    }

    rtb_Switch = rt_powd_snf(2.0, rtb_Switch);
  }

  /* End of Switch: '<Root>/Switch2' */

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  rtb_Switch = floor(rtb_Switch);
  if (rtIsNaN(rtb_Switch)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    soru_8_DW.DataTypeConversion3 = 0U;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    soru_8_DW.DataTypeConversion3 = (uint8_T)fmod(rtb_Switch, 256.0);
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Memory: '<Root>/Memory1'
   */
  rtb_Switch = floor(soru_8_DW.Memory1_PreviousInput);
  if (rtIsNaN(rtb_Switch) || rtIsInf(rtb_Switch)) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = fmod(rtb_Switch, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  soru_8_DW.DataTypeConversion = rtb_Switch < 0.0 ? -(int16_T)(uint16_T)-rtb_Switch : (int16_T)(uint16_T)
    rtb_Switch;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_Switch = floor(rtb_Mod3);
  if (rtIsNaN(rtb_Switch)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    soru_8_DW.DataTypeConversion1 = 0;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    soru_8_DW.DataTypeConversion1 = (int16_T)rtb_Switch;
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Gain: '<Root>/Gain1'
   *  Math: '<Root>/Mod4'
   *  Rounding: '<Root>/Fix1'
   */
  rtb_Switch = rt_modd_snf(floor(0.0078125 * rtb_Mod), 8.0);
  if (rtIsNaN(rtb_Switch)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    soru_8_DW.DataTypeConversion2 = 0;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    soru_8_DW.DataTypeConversion2 = (int16_T)rtb_Switch;
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */
  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call1' */
  ekrana_yaz(
             soru_8_DW.DataTypeConversion
             , soru_8_DW.DataTypeConversion1
             , soru_8_DW.DataTypeConversion2
             , soru_8_DW.DataTypeConversion3
             );

  /* Update for Memory: '<Root>/Memory' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   */
  soru_8_DW.Memory_PreviousInput = rtb_Mod + 1.0;

  /* Update for Memory: '<Root>/Memory1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  Sum: '<S3>/FixPt Sum1'
   */
  soru_8_DW.Memory1_PreviousInput = rtb_Mod2 + 1.0;
}

/* Model step function for TID1 */
void soru_8_step1(void)                /* Sample time: [1.0s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void soru_8_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (soru_8_M)->Timing.TaskCounters.cLimit[0] = 1;
  (soru_8_M)->Timing.TaskCounters.cLimit[1] = 100000;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  glcd_hazirla(
               );

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  soru_8_DW.Memory1_PreviousInput = 1.0;
}

/* Model terminate function */
void soru_8_terminate(void)
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
    soru_8_step0();

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
      soru_8_step1();

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
