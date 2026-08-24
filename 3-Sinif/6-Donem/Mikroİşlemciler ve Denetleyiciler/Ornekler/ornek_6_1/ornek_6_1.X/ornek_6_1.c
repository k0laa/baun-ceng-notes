/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_1.c
 *
 * Code generated for Simulink model 'ornek_6_1'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug 23 22:31:04 2026
 */

#include "ornek_6_1.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_1_T ornek_6_1_DW;

/* Real-time model */
static RT_MODEL_ornek_6_1_T ornek_6_1_M_;
RT_MODEL_ornek_6_1_T *const ornek_6_1_M = &ornek_6_1_M_;

/* Model step function for TID0 */
void ornek_6_1_step0(void)             /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void ornek_6_1_step1(void)             /* Sample time: [0.5s, 0.0s] */
{
  boolean_T rtb_DataTypeConversion;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  ornek_6_1_DW.UnitDelay_DSTATE = 1.0 - ornek_6_1_DW.UnitDelay_DSTATE;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_DataTypeConversion = (ornek_6_1_DW.UnitDelay_DSTATE != 0.0);

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATAbits.LATA9 = rtb_DataTypeConversion;
}

/* Model initialize function */
void ornek_6_1_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (ornek_6_1_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_6_1_M)->Timing.TaskCounters.cLimit[1] = 500;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_1_terminate(void)
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
      uint_T Task1;                    /* 0.5s periodic task. Max value is 500 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (500 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 500;/* 0.5s periodic task. Max value is 500 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_6_1_step0();

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
      ornek_6_1_step1();

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
