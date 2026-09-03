/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_7.c
 *
 * Code generated for Simulink model 'soru_7'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Sep  3 22:15:37 2026
 */

#include "soru_7.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_soru_7_T soru_7_DW;

/* Real-time model */
static RT_MODEL_soru_7_T soru_7_M_;
RT_MODEL_soru_7_T *const soru_7_M = &soru_7_M_;

/* Model step function for TID0 */
void soru_7_step0(void)                /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_Output_tmp;
  real_T tmp;
  int16_T i;
  uint16_T rtb_DataTypeConversion;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.01s, 0.0s] to Sample time: [1.0s, 0.0s]  */
  (soru_7_M->Timing.RateInteraction.TID0_1)++;
  if ((soru_7_M->Timing.RateInteraction.TID0_1) > 99) {
    soru_7_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* MultiPortSwitch: '<S3>/Output' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  UnitDelay: '<S5>/Output'
   */
  rtb_Output_tmp = soru_7_ConstP.Vector_Value[soru_7_DW.Output_DSTATE];

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  tmp = floor(soru_7_ConstP.Constant3_Value[(int16_T)rtb_Output_tmp - 1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* RateTransition generated from: '<Root>/Index Vector1' */
  if (soru_7_M->Timing.RateInteraction.TID0_1 == 1) {
    /* RateTransition generated from: '<Root>/Index Vector1' */
    for (i = 0; i < 5; i++) {
      soru_7_DW.TmpRTBAtIndexVector1Inport2[i] = soru_7_DW.TmpRTBAtIndexVector1Inport2_Buffer0[i];
    }

    /* End of RateTransition generated from: '<Root>/Index Vector1' */
  }

  /* End of RateTransition generated from: '<Root>/Index Vector1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   */
  tmp = floor(soru_7_DW.TmpRTBAtIndexVector1Inport2[(int16_T)rtb_Output_tmp - 1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATC = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* Switch: '<S7>/FixPt Switch' incorporates:
   *  Constant: '<S6>/FixPt Constant'
   *  Constant: '<S7>/Constant'
   *  Sum: '<S6>/FixPt Sum1'
   *  UnitDelay: '<S5>/Output'
   */
  if ((uint8_T)(soru_7_DW.Output_DSTATE + 1U) > 4) {
    soru_7_DW.Output_DSTATE = 0U;
  } else {
    soru_7_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S7>/FixPt Switch' */
}

/* Model step function for TID1 */
void soru_7_step1(void)                /* Sample time: [1.0s, 0.0s] */
{
  real_T rtb_MultiportSwitch[5];
  int16_T i;

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S4>/Vector'
   *  MultiPortSwitch: '<S4>/Output'
   *  UnitDelay: '<S8>/Output'
   */
  switch ((int16_T)soru_7_ConstP.Vector_Value_d[soru_7_DW.Output_DSTATE_j]) {
   case 1:
    for (i = 0; i < 5; i++) {
      rtb_MultiportSwitch[i] = soru_7_ConstP.Constant4_Value[i];
    }
    break;

   case 2:
    for (i = 0; i < 5; i++) {
      rtb_MultiportSwitch[i] = soru_7_ConstP.Constant5_Value[i];
    }
    break;

   case 3:
    for (i = 0; i < 5; i++) {
      rtb_MultiportSwitch[i] = soru_7_ConstP.Constant6_Value[i];
    }
    break;

   default:
    for (i = 0; i < 5; i++) {
      rtb_MultiportSwitch[i] = 0.0;
    }
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* RateTransition generated from: '<Root>/Index Vector1' */
  for (i = 0; i < 5; i++) {
    soru_7_DW.TmpRTBAtIndexVector1Inport2_Buffer0[i] = rtb_MultiportSwitch[i];
  }

  /* End of RateTransition generated from: '<Root>/Index Vector1' */

  /* Switch: '<S10>/FixPt Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S9>/FixPt Constant'
   *  Sum: '<S9>/FixPt Sum1'
   *  UnitDelay: '<S8>/Output'
   */
  if ((uint8_T)(soru_7_DW.Output_DSTATE_j + 1U) > 49) {
    soru_7_DW.Output_DSTATE_j = 0U;
  } else {
    soru_7_DW.Output_DSTATE_j++;
  }

  /* End of Switch: '<S10>/FixPt Switch' */
}

/* Model initialize function */
void soru_7_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (soru_7_M)->Timing.TaskCounters.cLimit[0] = 1;
  (soru_7_M)->Timing.TaskCounters.cLimit[1] = 100;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void soru_7_terminate(void)
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
      uint_T Task1;                    /* 1.0s periodic task. Max value is 100 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (100 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 100;/* 1.0s periodic task. Max value is 100 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    soru_7_step0();

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
      soru_7_step1();

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
