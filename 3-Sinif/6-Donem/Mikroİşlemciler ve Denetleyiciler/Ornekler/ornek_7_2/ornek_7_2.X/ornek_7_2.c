/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_7_2.c
 *
 * Code generated for Simulink model 'ornek_7_2'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 10:31:11 2026
 */

#include "ornek_7_2.h"
#include <math.h>
#include "ornek_7_2_private.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <float.h>

/* Block signals and states (default storage) */
DW_ornek_7_2_T ornek_7_2_DW;

/* Real-time model */
static RT_MODEL_ornek_7_2_T ornek_7_2_M_;
RT_MODEL_ornek_7_2_T *const ornek_7_2_M = &ornek_7_2_M_;
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
void ornek_7_2_step0(void)             /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_Memory;
  real_T tmp;
  uint16_T rtb_DataTypeConversion;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.01s, 0.0s] to Sample time: [0.05s, 0.0s]  */
  (ornek_7_2_M->Timing.RateInteraction.TID0_1)++;
  if ((ornek_7_2_M->Timing.RateInteraction.TID0_1) > 4) {
    ornek_7_2_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition generated from: '<Root>/Switch2' */
  if (ornek_7_2_M->Timing.RateInteraction.TID0_1 == 1) {
    /* RateTransition generated from: '<Root>/Switch2' */
    ornek_7_2_DW.TmpRTBAtSwitch2Inport2 = ornek_7_2_DW.TmpRTBAtSwitch2Inport2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Switch2' */

  /* Memory: '<Root>/Memory' */
  rtb_Memory = ornek_7_2_DW.Memory_PreviousInput;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Gain: '<Root>/Gain'
   *  Math: '<Root>/Mod'
   *  Memory: '<Root>/Memory'
   *  Rounding: '<Root>/Fix'
   */
  if (ornek_7_2_DW.TmpRTBAtSwitch2Inport2) {
    tmp = rt_modd_snf(ornek_7_2_DW.Memory_PreviousInput, 10.0);
  } else {
    tmp = floor(0.1 * ornek_7_2_DW.Memory_PreviousInput);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Switch: '<Root>/Switch2'
   */
  tmp = floor(tmp);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function (MCHP_Digital_Output_Write): '<S3>/Digital Output Write' */
  {
    uint16_T WritePortB = LATB;
    LATB = WritePortB ^ (255 & (WritePortB ^ rtb_DataTypeConversion));/* Update only required pins */
  }

  /* S-Function (MCHP_IC): '<Root>/Input Capture' */
  /* S-Function "dsPIC_PWM_IC" Block: <Root>/Input Capture */
  ornek_7_2_DW.InputCapture_o1 = MCHP_ic1ChangeDetectedFlag;
  MCHP_ic1ChangeDetectedFlag = 0;
  ornek_7_2_DW.InputCapture_o2 = MCHP_ic2ChangeDetectedFlag;
  MCHP_ic2ChangeDetectedFlag = 0;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Logic: '<Root>/OR'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  Switch: '<Root>/Switch'
   */
  if ((rtb_Memory == 100.0) || (ornek_7_2_DW.InputCapture_o2 != 0U)) {
    rtb_Memory = 0.0;
  } else if (ornek_7_2_DW.InputCapture_o1 > 0U) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<S4>/FixPt Constant'
     *  Sum: '<S4>/FixPt Sum1'
     */
    rtb_Memory++;
  }

  /* End of Switch: '<Root>/Switch1' */
  /* Update for Memory: '<Root>/Memory' */
  ornek_7_2_DW.Memory_PreviousInput = rtb_Memory;
}

/* Model step function for TID1 */
void ornek_7_2_step1(void)             /* Sample time: [0.05s, 0.0s] */
{
  boolean_T rtb_DataTypeConversion1;
  boolean_T rtb_NOT;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  ornek_7_2_DW.UnitDelay_DSTATE = 1.0 - ornek_7_2_DW.UnitDelay_DSTATE;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_DataTypeConversion1 = (ornek_7_2_DW.UnitDelay_DSTATE != 0.0);

  /* Logic: '<Root>/NOT' */
  rtb_NOT = !rtb_DataTypeConversion1;

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATBbits.LATB11 = rtb_DataTypeConversion1;
  LATBbits.LATB12 = rtb_NOT;

  /* RateTransition generated from: '<Root>/Switch2' */
  ornek_7_2_DW.TmpRTBAtSwitch2Inport2_Buffer0 = rtb_DataTypeConversion1;
}

/* Model initialize function */
void ornek_7_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (ornek_7_2_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_7_2_M)->Timing.TaskCounters.cLimit[1] = 5;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_IC): '<Root>/Input Capture' */
  IC1CON = 0x81;
  IC2CON = 0x83;

  /* Set-up Input Capture Interruption */
  _IC1IF = 0;                          /* Clear interrupt Flag */
  _IC1IP = 4;                          /* Set interrupt Priority */
  _IC1IE = 1;                          /* Enable Interrupt */
  _IC2IF = 0;                          /* Clear interrupt Flag */
  _IC2IP = 4;                          /* Set interrupt Priority */
  _IC2IE = 1;                          /* Enable Interrupt */
}

/* Model terminate function */
void ornek_7_2_terminate(void)
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
      uint_T Task1;                    /* 0.05s periodic task. Max value is 5 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (5 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 5;/* 0.05s periodic task. Max value is 5 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_7_2_step0();

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
      ornek_7_2_step1();

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
