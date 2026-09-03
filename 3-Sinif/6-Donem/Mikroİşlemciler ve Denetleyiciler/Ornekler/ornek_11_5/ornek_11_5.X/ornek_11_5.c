/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_11_5.c
 *
 * Code generated for Simulink model 'ornek_11_5'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 01:22:14 2026
 */

#include "ornek_11_5.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ornek_11_5_private.h"

/* Block signals and states (default storage) */
DW_ornek_11_5_T ornek_11_5_DW;

/* Real-time model */
static RT_MODEL_ornek_11_5_T ornek_11_5_M_;
RT_MODEL_ornek_11_5_T *const ornek_11_5_M = &ornek_11_5_M_;

/* Model step function for TID0 */
void ornek_11_5_step0(void)            /* Sample time: [0.001s, 0.0s] */
{
  real_T tmp;
  real_T tmp_0;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.001s, 0.0s] to Sample time: [0.008s, 0.0s]  */
  (ornek_11_5_M->Timing.RateInteraction.TID0_1)++;
  if ((ornek_11_5_M->Timing.RateInteraction.TID0_1) > 7) {
    ornek_11_5_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.001s, 0.0s] to Sample time: [0.016s, 0.0s]  */
  (ornek_11_5_M->Timing.RateInteraction.TID0_2)++;
  if ((ornek_11_5_M->Timing.RateInteraction.TID0_2) > 15) {
    ornek_11_5_M->Timing.RateInteraction.TID0_2 = 0;
  }

  /* MultiPortSwitch: '<S3>/Output' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  UnitDelay: '<S10>/Output'
   */
  tmp_0 = ornek_11_5_ConstP.Vector_Value_g[ornek_11_5_DW.Output_DSTATE];

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<S3>/Output'
   */
  tmp = floor(tmp_0);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ornek_11_5_DW.DataTypeConversion2 = tmp < 0.0 ? -(int16_T)(uint16_T)-tmp : (int16_T)(uint16_T)tmp;

  /* MultiPortSwitch: '<Root>/Index Vector' incorporates:
   *  Constant: '<Root>/Constant'
   */
  ornek_11_5_DW.IndexVector = ornek_11_5_ConstP.Constant_Value[(int16_T)tmp_0];

  /* RateTransition generated from: '<Root>/C Function Call1' */
  if (ornek_11_5_M->Timing.RateInteraction.TID0_1 == 1) {
    /* RateTransition generated from: '<Root>/C Function Call1' */
    ornek_11_5_DW.TmpRTBAtCFunctionCall1Inport1 = ornek_11_5_DW.TmpRTBAtCFunctionCall1Inport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/C Function Call1' */

  /* RateTransition generated from: '<Root>/C Function Call1' */
  if (ornek_11_5_M->Timing.RateInteraction.TID0_2 == 1) {
    /* RateTransition generated from: '<Root>/C Function Call1' */
    ornek_11_5_DW.TmpRTBAtCFunctionCall1Inport2 = ornek_11_5_DW.TmpRTBAtCFunctionCall1Inport2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/C Function Call1' */

  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call1' */
  ekrana_yaz(
             ornek_11_5_DW.TmpRTBAtCFunctionCall1Inport1
             , ornek_11_5_DW.TmpRTBAtCFunctionCall1Inport2
             , ornek_11_5_DW.DataTypeConversion2
             , ornek_11_5_DW.IndexVector
             );

  /* Switch: '<S12>/FixPt Switch' incorporates:
   *  Constant: '<S11>/FixPt Constant'
   *  Constant: '<S12>/Constant'
   *  Sum: '<S11>/FixPt Sum1'
   *  UnitDelay: '<S10>/Output'
   */
  if ((uint8_T)(ornek_11_5_DW.Output_DSTATE + 1U) > 6) {
    ornek_11_5_DW.Output_DSTATE = 0U;
  } else {
    ornek_11_5_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S12>/FixPt Switch' */
}

/* Model step function for TID1 */
void ornek_11_5_step1(void)            /* Sample time: [0.008s, 0.0s] */
{
  real_T tmp;
  int16_T rtb_DataTypeConversion;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Vector'
   *  MultiPortSwitch: '<S1>/Output'
   *  UnitDelay: '<S4>/Output'
   */
  tmp = floor(ornek_11_5_ConstP.Vector_Value[ornek_11_5_DW.Output_DSTATE_e]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? -(int16_T)(uint16_T)-tmp : (int16_T)(uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* RateTransition generated from: '<Root>/C Function Call1' */
  ornek_11_5_DW.TmpRTBAtCFunctionCall1Inport1_Buffer0 = rtb_DataTypeConversion;

  /* Switch: '<S6>/FixPt Switch' incorporates:
   *  Constant: '<S5>/FixPt Constant'
   *  Constant: '<S6>/Constant'
   *  Sum: '<S5>/FixPt Sum1'
   *  UnitDelay: '<S4>/Output'
   */
  if ((uint8_T)(ornek_11_5_DW.Output_DSTATE_e + 1U) > 1) {
    ornek_11_5_DW.Output_DSTATE_e = 0U;
  } else {
    ornek_11_5_DW.Output_DSTATE_e++;
  }

  /* End of Switch: '<S6>/FixPt Switch' */
}

/* Model step function for TID2 */
void ornek_11_5_step2(void)            /* Sample time: [0.016s, 0.0s] */
{
  real_T tmp;
  int16_T rtb_DataTypeConversion1;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Vector'
   *  MultiPortSwitch: '<S2>/Output'
   *  UnitDelay: '<S7>/Output'
   */
  tmp = floor(ornek_11_5_ConstP.Vector_Value_f[ornek_11_5_DW.Output_DSTATE_a]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1 = tmp < 0.0 ? -(int16_T)(uint16_T)-tmp : (int16_T)(uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* RateTransition generated from: '<Root>/C Function Call1' */
  ornek_11_5_DW.TmpRTBAtCFunctionCall1Inport2_Buffer0 = rtb_DataTypeConversion1;

  /* Switch: '<S9>/FixPt Switch' incorporates:
   *  Constant: '<S8>/FixPt Constant'
   *  Constant: '<S9>/Constant'
   *  Sum: '<S8>/FixPt Sum1'
   *  UnitDelay: '<S7>/Output'
   */
  if ((uint8_T)(ornek_11_5_DW.Output_DSTATE_a + 1U) > 63) {
    ornek_11_5_DW.Output_DSTATE_a = 0U;
  } else {
    ornek_11_5_DW.Output_DSTATE_a++;
  }

  /* End of Switch: '<S9>/FixPt Switch' */
}

/* Model step function for TID3 */
void ornek_11_5_step3(void)            /* Sample time: [1.0s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void ornek_11_5_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (ornek_11_5_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_11_5_M)->Timing.TaskCounters.cLimit[1] = 8;
  (ornek_11_5_M)->Timing.TaskCounters.cLimit[2] = 16;
  (ornek_11_5_M)->Timing.TaskCounters.cLimit[3] = 1000;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  glcd_hazirla(
               );
}

/* Model terminate function */
void ornek_11_5_terminate(void)
{
  /* (no terminate code required) */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    struct {
      unsigned int Flags1 : 1;
      unsigned int Flags2 : 1;
      unsigned int Flags3 : 1;
    } static volatile Overrun __attribute__ ((near)) ;

    struct {
      unsigned int Flags1 : 1;
      unsigned int Flags2 : 1;
      unsigned int Flags3 : 1;
    } static volatile event __attribute__ ((near)) ;

    struct {
      uint_T Task1;                    /* 0.008s periodic task. Max value is 8 */
      uint_T Task2;                    /* 0.016s periodic task. Max value is 16 */
      uint_T Task3;                    /* 1.0s periodic task. Max value is 1000 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (8 + 1 - 0 including pre-decrement */
      , .Task2 = 1                     /* Offset is 0 (16 + 1 - 0 including pre-decrement */
      , .Task3 = 1                     /* Offset is 0 (1000 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 8;/* 0.008s periodic task. Max value is 8 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    taskCounter.Task2--;               /* Decrement task internal counter */
    if (taskCounter.Task2 == 0) {      /* task dropped on overload */
      taskCounter.Task2 = (uint16_T) 16;/* 0.016s periodic task. Max value is 16 */
      event.Flags2 = 1U;               /* Flag tag to be executed */
    }

    taskCounter.Task3--;               /* Decrement task internal counter */
    if (taskCounter.Task3 == 0) {      /* task dropped on overload */
      taskCounter.Task3 = (uint16_T) 1000;/* 1.0s periodic task. Max value is 1000 */
      event.Flags3 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_11_5_step0();

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
      ornek_11_5_step1();

      /* Get model outputs here */
    }

    Overrun.Flags1 = 0U;

    /* ---------- Handle Task 2 ---------- */
    if (Overrun.Flags2) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags2) {             /* Execute task tid 2 */
      Overrun.Flags2 = 1U;
      event.Flags2 = 0U;
      ornek_11_5_step2();

      /* Get model outputs here */
    }

    Overrun.Flags2 = 0U;

    /* ---------- Handle Task 3 ---------- */
    if (Overrun.Flags3) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags3) {             /* Execute task tid 3 */
      Overrun.Flags3 = 1U;
      event.Flags3 = 0U;
      ornek_11_5_step3();

      /* Get model outputs here */
    }

    Overrun.Flags3 = 0U;

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
