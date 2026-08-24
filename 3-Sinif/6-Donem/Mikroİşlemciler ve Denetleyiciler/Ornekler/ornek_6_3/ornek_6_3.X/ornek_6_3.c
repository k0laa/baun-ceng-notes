/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_3.c
 *
 * Code generated for Simulink model 'ornek_6_3'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug 23 22:49:09 2026
 */

#include "ornek_6_3.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_3_T ornek_6_3_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_6_3_step(void)
{
  real_T rtb_Memory;
  boolean_T rtb_DigitalInput;
  boolean_T rtb_LogicalOperator;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = ornek_6_3_DW.Memory_PreviousInput;

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  rtb_LogicalOperator = ((ornek_6_3_DW.Memory_PreviousInput > 0.0) && (ornek_6_3_DW.Memory_PreviousInput <=
    3.0));

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_LogicalOperator;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTCbits.RC0;    /* Read pin C0 */

  /* Outputs for Enabled SubSystem: '<S4>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (ornek_6_3_ConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
     *  UnitDelay: '<S4>/Unit Delay'
     */
    ornek_6_3_DW.bitsForTID0.RelationalOperator1 = ((int16_T)rtb_LogicalOperator > (int16_T)
      ornek_6_3_DW.bitsForTID0.UnitDelay_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S4>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S4>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (ornek_6_3_ConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
     *  UnitDelay: '<S4>/Unit Delay'
     */
    ornek_6_3_DW.bitsForTID0.RelationalOperator1_a = ((int16_T)ornek_6_3_DW.bitsForTID0.UnitDelay_DSTATE >
      (int16_T)rtb_LogicalOperator);
  }

  /* End of Outputs for SubSystem: '<S4>/NEGATIVE Edge' */

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Logic: '<S4>/Logical Operator1'
   *  Memory: '<S3>/Memory'
   */
  rtb_DigitalInput = ornek_6_3_ConstP.Logic_table[((((uint16_T)rtb_DigitalInput << 1) + (uint16_T)
    (ornek_6_3_DW.bitsForTID0.RelationalOperator1 || ornek_6_3_DW.bitsForTID0.RelationalOperator1_a)) << 1) +
    ornek_6_3_DW.bitsForTID0.Memory_PreviousInput_j];

  /* Switch: '<Root>/Switch' */
  if (rtb_DigitalInput) {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    ornek_6_3_DW.Memory_PreviousInput = rtb_Memory + 0.1;
  } else {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    ornek_6_3_DW.Memory_PreviousInput = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  ornek_6_3_DW.bitsForTID0.UnitDelay_DSTATE = rtb_LogicalOperator;

  /* Update for Memory: '<S3>/Memory' */
  ornek_6_3_DW.bitsForTID0.Memory_PreviousInput_j = rtb_DigitalInput;
}

/* Model initialize function */
void ornek_6_3_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_3_terminate(void)
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
    ornek_6_3_step();

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
