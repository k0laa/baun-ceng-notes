/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_4.c
 *
 * Code generated for Simulink model 'ornek_6_4'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug 23 23:10:53 2026
 */

#include "ornek_6_4.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_4_T ornek_6_4_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_6_4_step(void)
{
  real_T rtb_Memory;
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator2;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = ornek_6_4_DW.Memory_PreviousInput;

  /* RelationalOperator: '<Root>/ ' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   */
  rtb_DigitalInput_o1 = (ornek_6_4_DW.Memory_PreviousInput > 0.0);

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  rtb_LogicalOperator = (rtb_DigitalInput_o1 && (ornek_6_4_DW.Memory_PreviousInput < 6.0));

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator3'
   */
  rtb_LogicalOperator1 = (rtb_DigitalInput_o1 && (ornek_6_4_DW.Memory_PreviousInput < 14.0));

  /* Logic: '<Root>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator4'
   *  RelationalOperator: '<Root>/Relational Operator5'
   */
  rtb_LogicalOperator2 = ((ornek_6_4_DW.Memory_PreviousInput >= 14.0) && (ornek_6_4_DW.Memory_PreviousInput <
    17.0));

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_LogicalOperator;
  LATBbits.LATB1 = rtb_LogicalOperator1;
  LATBbits.LATB2 = rtb_LogicalOperator2;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */

  /* CombinatorialLogic: '<S2>/Logic' incorporates:
   *  Memory: '<S2>/Memory'
   */
  rtb_DigitalInput_o1 = ornek_6_4_ConstP.Logic_table[((((uint16_T)rtb_DigitalInput_o1 << 1) +
    rtb_DigitalInput_o2) << 1) + ornek_6_4_DW.bitsForTID0.Memory_PreviousInput_j];

  /* Switch: '<Root>/Switch' */
  if (rtb_DigitalInput_o1) {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    ornek_6_4_DW.Memory_PreviousInput = rtb_Memory + 0.1;
  } else {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    ornek_6_4_DW.Memory_PreviousInput = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Update for Memory: '<S2>/Memory' */
  ornek_6_4_DW.bitsForTID0.Memory_PreviousInput_j = rtb_DigitalInput_o1;
}

/* Model initialize function */
void ornek_6_4_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_4_terminate(void)
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
    ornek_6_4_step();

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
