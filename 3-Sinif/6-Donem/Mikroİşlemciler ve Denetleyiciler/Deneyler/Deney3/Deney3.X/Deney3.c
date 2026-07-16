/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Deney3.c
 *
 * Code generated for Simulink model 'Deney3'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Mar  4 20:11:42 2026
 */

#include "Deney3.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Deney3_private.h"

/* Block signals and states (default storage) */
DW_Deney3_T Deney3_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Deney3_T Deney3_PrevZCX;

/* Real-time model */
static RT_MODEL_Deney3_T Deney3_M_;
RT_MODEL_Deney3_T *const Deney3_M = &Deney3_M_;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void Deney3_step(void)
{
  real_T rtb_Memory;
  int16_T rowIdx;
  boolean_T Memory;
  boolean_T rtb_DigitalInput;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = Deney3_DW.Memory_PreviousInput;

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  Deney3_DW.LogicalOperator = ((rtb_Memory > 0.0) && (rtb_Memory <= 3.0));

  /* DataTypeConversion: '<S4>/Data Type Conversion2' */
  Deney3_DW.bitsForTID0.DataTypeConversion2 = Deney3_DW.LogicalOperator;

  /* Memory: '<S4>/Memory' */
  Memory = Deney3_DW.bitsForTID1.Memory_PreviousInput_j;

  /* Outputs for Enabled SubSystem: '<S4>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (Deney3_ConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S7>/Relational Operator1' */
    Deney3_DW.bitsForTID0.RelationalOperator1 = ((int16_T)Memory < (int16_T)
      Deney3_DW.bitsForTID0.DataTypeConversion2);
  }

  /* End of Outputs for SubSystem: '<S4>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S4>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (Deney3_ConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S6>/Relational Operator1' */
    Deney3_DW.bitsForTID0.RelationalOperator1_d = ((int16_T)Memory > (int16_T)
      Deney3_DW.bitsForTID0.DataTypeConversion2);
  }

  /* End of Outputs for SubSystem: '<S4>/NEGATIVE Edge' */
  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = Deney3_DW.LogicalOperator;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTCbits.RC0;    /* Read pin C0 */

  /* Logic: '<S4>/Logical Operator1' */
  Memory = (Deney3_DW.bitsForTID0.RelationalOperator1 || Deney3_DW.bitsForTID0.RelationalOperator1_d);

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Memory: '<S3>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_DigitalInput << 1) + Memory) << 1) +
                     Deney3_DW.bitsForTID1.Memory_PreviousInput_b);
  Deney3_DW.Logic[0U] = Deney3_ConstP.Logic_table[(uint16_T)rowIdx];
  Deney3_DW.Logic[1U] = Deney3_ConstP.Logic_table[(uint16_T)rowIdx + 8U];

  /* Switch: '<Root>/Switch3' */
  if (Deney3_DW.Logic[0]) {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    Deney3_DW.Switch3 = rtb_Memory + 0.1;
  } else {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Deney3_DW.Switch3 = 0.0;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Outputs for Triggered SubSystem: '<S5>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S8>/Trigger'
   */
  Deney3_PrevZCX.TriggeredSubsystem_Trig_ZCE = Memory;

  /* End of Outputs for SubSystem: '<S5>/Triggered Subsystem' */

  /* Update for Memory: '<Root>/Memory' */
  Deney3_DW.Memory_PreviousInput = Deney3_DW.Switch3;

  /* Update for Memory: '<S4>/Memory' */
  Deney3_DW.bitsForTID1.Memory_PreviousInput_j = Deney3_DW.bitsForTID0.DataTypeConversion2;

  /* Update for Memory: '<S3>/Memory' */
  Deney3_DW.bitsForTID1.Memory_PreviousInput_b = Deney3_DW.Logic[0];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Deney3_M->Timing.t[0] =
    ((time_T)(++Deney3_M->Timing.clockTick0)) * Deney3_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Deney3_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Deney3_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Deney3_M->solverInfo, &Deney3_M->Timing.simTimeStep);
    rtsiSetTPtr(&Deney3_M->solverInfo, &rtmGetTPtr(Deney3_M));
    rtsiSetStepSizePtr(&Deney3_M->solverInfo, &Deney3_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Deney3_M->solverInfo, (&rtmGetErrorStatus(Deney3_M)));
    rtsiSetRTModelPtr(&Deney3_M->solverInfo, Deney3_M);
  }

  rtsiSetSimTimeStep(&Deney3_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Deney3_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Deney3_M, &Deney3_M->Timing.tArray[0]);
  Deney3_M->Timing.stepSize0 = 0.1;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
  Deney3_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;
}

/* Model terminate function */
void Deney3_terminate(void)
{
  /* (no terminate code required) */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) ) ;/* Atomic bit-set: ContinueTimeStep |= 1U */
    _T1IF = 0;                         /* Re-enable interrupt */
  }
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  for (;;) {                           /* Infinite loop, no return */
    while (!ContinueTimeStep) ;

    /* Disable Scheduler Interrupt */
    _IPL0 = 1;                         /* Disable Scheduler Interrupts. Rise IPL from 0 to 1 */
    __asm__ volatile ("BCLR.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) );/* Atomic bit-clear of ContinueTimeStep bit 1U */

    /* Call model Scheduler */
    /* Step the model for base rate */
    Deney3_step();

    /* Get model outputs here */

    /* Re-Enable Scheduler Interrupt */
    _IPL0 = 0;                         /* Enable Scheduler interrupt. Lower IPL from 1 to 0 */
  }                                    /* end infinite loop for(;;) */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
