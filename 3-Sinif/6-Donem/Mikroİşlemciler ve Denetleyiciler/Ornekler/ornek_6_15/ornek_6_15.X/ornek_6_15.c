/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_15.c
 *
 * Code generated for Simulink model 'ornek_6_15'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Aug 26 22:11:21 2026
 */

#include "ornek_6_15.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_15_T ornek_6_15_DW;

/* Real-time model */
static RT_MODEL_ornek_6_15_T ornek_6_15_M_;
RT_MODEL_ornek_6_15_T *const ornek_6_15_M = &ornek_6_15_M_;

/* Model step function for TID0 */
void ornek_6_15_step0(void)            /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_Memory;
  real_T tmp;
  uint16_T rtb_DataTypeConversion1;
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_Switch2;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.01s, 0.0s] to Sample time: [0.1s, 0.0s]  */
  (ornek_6_15_M->Timing.RateInteraction.TID0_1)++;
  if ((ornek_6_15_M->Timing.RateInteraction.TID0_1) > 9) {
    ornek_6_15_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition generated from: '<Root>/Switch2' */
  if (ornek_6_15_M->Timing.RateInteraction.TID0_1 == 1) {
    /* RateTransition generated from: '<Root>/Switch2' */
    ornek_6_15_DW.TmpRTBAtSwitch2Inport1 = ornek_6_15_DW.TmpRTBAtSwitch2Inport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Switch2' */

  /* Memory: '<Root>/Memory' */
  rtb_Memory = ornek_6_15_DW.Memory_PreviousInput;

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Memory: '<Root>/Memory'
   */
  rtb_LogicalOperator = (ornek_6_15_DW.Memory_PreviousInput <= 0.0);

  /* Switch: '<Root>/Switch2' */
  rtb_Switch2 = (rtb_LogicalOperator && ornek_6_15_DW.TmpRTBAtSwitch2Inport1);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  Rounding: '<Root>/Fix'
   */
  tmp = floor(ornek_6_15_ConstP.Constant3_Value[(int16_T)floor(ornek_6_15_DW.Memory_PreviousInput)]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1 = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */
  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATB = rtb_DataTypeConversion1;      /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Output_Write): '<S3>/Digital Output Write' */
  LATCbits.LATC0 = rtb_Switch2;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC1; /* Read pin C1 */
  rtb_DigitalInput_o2 = PORTCbits.RC2; /* Read pin C2 */

  /* CombinatorialLogic: '<S4>/Logic' incorporates:
   *  Logic: '<Root>/Logical Operator'
   *  Memory: '<S4>/Memory'
   */
  rtb_LogicalOperator = ornek_6_15_ConstP.Logic_table[((((uint16_T)rtb_DigitalInput_o1 << 1) + (uint16_T)
    (rtb_DigitalInput_o2 || rtb_LogicalOperator)) << 1) + ornek_6_15_DW.bitsForTID0.Memory_PreviousInput_k];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Switch: '<Root>/Switch'
   */
  if (rtb_DigitalInput_o2) {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    ornek_6_15_DW.Memory_PreviousInput = 5.0;
  } else if (rtb_LogicalOperator) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Memory: '<Root>/Memory'
     *  Sum: '<Root>/Sum'
     */
    ornek_6_15_DW.Memory_PreviousInput = rtb_Memory - 0.01;
  } else {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Switch: '<Root>/Switch'
     */
    ornek_6_15_DW.Memory_PreviousInput = rtb_Memory;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Update for Memory: '<S4>/Memory' */
  ornek_6_15_DW.bitsForTID0.Memory_PreviousInput_k = rtb_LogicalOperator;
}

/* Model step function for TID1 */
void ornek_6_15_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  boolean_T rtb_DataTypeConversion;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  ornek_6_15_DW.UnitDelay_DSTATE = 1.0 - ornek_6_15_DW.UnitDelay_DSTATE;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_DataTypeConversion = (ornek_6_15_DW.UnitDelay_DSTATE != 0.0);

  /* RateTransition generated from: '<Root>/Switch2' */
  ornek_6_15_DW.TmpRTBAtSwitch2Inport1_Buffer0 = rtb_DataTypeConversion;
}

/* Model initialize function */
void ornek_6_15_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (ornek_6_15_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_6_15_M)->Timing.TaskCounters.cLimit[1] = 10;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for Memory: '<Root>/Memory' */
  ornek_6_15_DW.Memory_PreviousInput = 5.0;
}

/* Model terminate function */
void ornek_6_15_terminate(void)
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
      uint_T Task1;                    /* 0.1s periodic task. Max value is 10 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (10 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 10;/* 0.1s periodic task. Max value is 10 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_6_15_step0();

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
      ornek_6_15_step1();

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
