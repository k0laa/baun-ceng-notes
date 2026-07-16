/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney6.c
 *
 * Code generated for Simulink model 'deney6'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Jun  9 22:10:10 2026
 */

#include "deney6.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_deney6_T deney6_DW;

/* Real-time model */
static RT_MODEL_deney6_T deney6_M_;
RT_MODEL_deney6_T *const deney6_M = &deney6_M_;

/* Model step function for TID0 */
void deney6_step0(void)                /* Sample time: [0.1s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void deney6_step1(void)                /* Sample time: [1.0s, 0.0s] */
{
  real_T tmp;
  uint16_T rtb_DataTypeConversion;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S2>/Vector'
   *  MultiPortSwitch: '<S2>/Output'
   *  UnitDelay: '<S3>/Output'
   */
  tmp = floor(deney6_ConstP.Vector_Value[deney6_DW.Output_DSTATE]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* Switch: '<S5>/FixPt Switch' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  Constant: '<S5>/Constant'
   *  Sum: '<S4>/FixPt Sum1'
   *  UnitDelay: '<S3>/Output'
   */
  if ((uint8_T)(deney6_DW.Output_DSTATE + 1U) > 13) {
    deney6_DW.Output_DSTATE = 0U;
  } else {
    deney6_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S5>/FixPt Switch' */
}

/* Model initialize function */
void deney6_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (deney6_M)->Timing.TaskCounters.cLimit[0] = 1;
  (deney6_M)->Timing.TaskCounters.cLimit[1] = 10;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void deney6_terminate(void)
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
      uint_T Task1;                    /* 1.0s periodic task. Max value is 10 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (10 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 10;/* 1.0s periodic task. Max value is 10 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    deney6_step0();

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
      deney6_step1();

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
