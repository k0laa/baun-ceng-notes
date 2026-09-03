/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_11_4.c
 *
 * Code generated for Simulink model 'ornek_11_4'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 01:02:27 2026
 */

#include "ornek_11_4.h"
#include "ornek_11_4_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_11_4_T ornek_11_4_DW;

/* Real-time model */
static RT_MODEL_ornek_11_4_T ornek_11_4_M_;
RT_MODEL_ornek_11_4_T *const ornek_11_4_M = &ornek_11_4_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ornek_11_4_M->Timing.TaskCounters.TID[1])++;
  if ((ornek_11_4_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [1.0s, 0.0s] */
    ornek_11_4_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void ornek_11_4_step(void)
{
  /* local block i/o variables */
  uint16_T rtb_DigitalInput;
  boolean_T rtb_DigitalInput1;
  real_T rtb_Switch;
  real_T tmp;
  uint16_T rtb_DataTypeConversion;

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  LATBbits.LATB2 = false;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTC;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input1' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input1/Output */
  rtb_DigitalInput1 = PORTAbits.RA10;  /* Read pin A10 */

  /* Outputs for Enabled SubSystem: '<S4>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (ornek_11_4_ConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
     *  UnitDelay: '<S4>/Unit Delay'
     */
    ornek_11_4_DW.bitsForTID0.RelationalOperator1 = ((int16_T)rtb_DigitalInput1 > (int16_T)
      ornek_11_4_DW.bitsForTID0.UnitDelay_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S4>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S4>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (ornek_11_4_ConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
     *  UnitDelay: '<S4>/Unit Delay'
     */
    ornek_11_4_DW.bitsForTID0.RelationalOperator1_m = ((int16_T)ornek_11_4_DW.bitsForTID0.UnitDelay_DSTATE >
      (int16_T)rtb_DigitalInput1);
  }

  /* End of Outputs for SubSystem: '<S4>/NEGATIVE Edge' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Logic: '<S4>/Logical Operator1'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  if (ornek_11_4_DW.bitsForTID0.RelationalOperator1 || ornek_11_4_DW.bitsForTID0.RelationalOperator1_m) {
    rtb_Switch = ornek_11_4_ConstP.Constant1_Value[rtb_DigitalInput];
  } else {
    rtb_Switch = ornek_11_4_DW.Memory_PreviousInput;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Memory: '<Root>/Memory'
   */
  tmp = floor(ornek_11_4_DW.Memory_PreviousInput);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* RateTransition: '<Root>/Rate Transition1' */
  ornek_11_4_DW.RateTransition1_Buffer0 = rtb_DataTypeConversion;
  if (ornek_11_4_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
    LCD_StartUp(
                );
  }

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  ornek_11_4_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput1;

  /* Update for Memory: '<Root>/Memory' */
  ornek_11_4_DW.Memory_PreviousInput = rtb_Switch;
  rate_scheduler();
}

/* Model initialize function */
void ornek_11_4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_11_4_terminate(void)
{
  /* (no terminate code required) */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    /* Re-enable timer or interrupt */
    _T1IF = 0;                         /*  */
    MCHP_Scheduler();
  }
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  /* Call model Scheduler */

  /* Step the model for base rate */
  ornek_11_4_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

void MCHP_IdleTask(void)
{
  /* Idle Task */
  {
    /* RateTransition: '<Root>/Rate Transition1' */
    ornek_11_4_DW.RateTransition1 = ornek_11_4_DW.RateTransition1_Buffer0;

    /* S-Function (MCHP_IdleTask): '<Root>/Idle Task' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* S-Function (MCHP_C_function_Call): '<S3>/C Function Call' */
    PrintKarakter(
                  ornek_11_4_DW.RateTransition1
                  );

    /* End of Outputs for S-Function (MCHP_IdleTask): '<Root>/Idle Task' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
