/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru5.c
 *
 * Code generated for Simulink model 'soru5'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Apr  9 12:44:43 2026
 */

#include "soru5.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_soru5_T soru5_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void soru5_step(void)
{
  real_T rtb_Memory;
  real_T rtb_Switch3;
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_Memory3;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = soru5_DW.Memory_PreviousInput;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_Memory3 = PORTCbits.RC1;         /* Read pin C1 */

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant3'
   *  Logic: '<Root>/Logical Operator3'
   *  Sum: '<Root>/Sum'
   */
  if ((boolean_T)(rtb_DigitalInput_o1 ^ rtb_Memory3)) {
    rtb_Switch3 = rtb_Memory + 0.1;
  } else {
    rtb_Switch3 = 0.0;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Logic: '<Root>/Logical Operator1' */
  rtb_DigitalInput_o1 = (rtb_DigitalInput_o1 && rtb_Memory3);

  /* Memory: '<Root>/Memory3' */
  rtb_Memory3 = soru5_DW.bitsForTID0.Memory3_PreviousInput;

  /* Logic: '<Root>/Logical Operator4' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Logic: '<Root>/Logical Operator5'
   *  Logic: '<Root>/Logical Operator6'
   *  Memory: '<Root>/Memory1'
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  rtb_Memory3 = (soru5_DW.bitsForTID0.Memory1_PreviousInput || (rtb_Memory >= 3.0) || ((!rtb_DigitalInput_o1) &&
    rtb_Memory3));

  /* Logic: '<Root>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Logic: '<Root>/Logical Operator7'
   *  Memory: '<Root>/Memory2'
   *  RelationalOperator: '<Root>/Relational Operator2'
   */
  rtb_LogicalOperator2 = ((soru5_DW.Memory2_PreviousInput >= 8.0) && (!rtb_Memory3));

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_LogicalOperator2;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  Memory: '<Root>/Memory2'
   *  Sum: '<Root>/Sum2'
   */
  if (rtb_DigitalInput_o1) {
    rtb_Memory = soru5_DW.Memory2_PreviousInput + 0.1;
  } else {
    rtb_Memory = 0.0;
  }

  /* End of Switch: '<Root>/Switch2' */
  /* Update for Memory: '<Root>/Memory' */
  soru5_DW.Memory_PreviousInput = rtb_Switch3;

  /* Update for Memory: '<Root>/Memory2' */
  soru5_DW.Memory2_PreviousInput = rtb_Memory;

  /* Update for Memory: '<Root>/Memory1' */
  soru5_DW.bitsForTID0.Memory1_PreviousInput = rtb_Memory3;

  /* Update for Memory: '<Root>/Memory3' */
  soru5_DW.bitsForTID0.Memory3_PreviousInput = rtb_DigitalInput_o1;
}

/* Model initialize function */
void soru5_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void soru5_terminate(void)
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
    soru5_step();

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
