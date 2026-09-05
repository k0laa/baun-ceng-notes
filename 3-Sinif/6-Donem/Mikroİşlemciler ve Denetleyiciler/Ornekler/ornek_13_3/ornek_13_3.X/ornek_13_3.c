/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_3.c
 *
 * Code generated for Simulink model 'ornek_13_3'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 14:54:07 2026
 */

#include "ornek_13_3.h"
#include "rtwtypes.h"

volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_13_3_step(void)
{
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  boolean_T rtb_DigitalInput_o3;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator12;
  boolean_T rtb_LogicalOperator12_tmp;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator6;
  boolean_T rtb_LogicalOperator7;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */
  rtb_DigitalInput_o3 = PORTCbits.RC2; /* Read pin C2 */

  /* Logic: '<Root>/Logical Operator12' incorporates:
   *  Logic: '<Root>/Logical Operator8'
   */
  rtb_LogicalOperator12_tmp = (rtb_DigitalInput_o1 && rtb_DigitalInput_o2);
  rtb_LogicalOperator12 = (rtb_LogicalOperator12_tmp && rtb_DigitalInput_o3);

  /* Logic: '<Root>/Logical Operator6' */
  rtb_LogicalOperator6 = !rtb_DigitalInput_o1;

  /* Logic: '<Root>/Logical Operator1' */
  rtb_LogicalOperator1 = !rtb_DigitalInput_o2;

  /* Logic: '<Root>/Logical Operator2' */
  rtb_LogicalOperator2 = !rtb_DigitalInput_o3;

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Logic: '<Root>/Logical Operator5'
   */
  rtb_LogicalOperator7 = (rtb_LogicalOperator6 && rtb_LogicalOperator1);
  rtb_LogicalOperator = (rtb_LogicalOperator7 && rtb_LogicalOperator2);

  /* Logic: '<Root>/Logical Operator3' incorporates:
   *  Logic: '<Root>/Logical Operator9'
   */
  rtb_DigitalInput_o1 = (rtb_DigitalInput_o1 && rtb_LogicalOperator1);

  /* Logic: '<Root>/Logical Operator4' incorporates:
   *  Logic: '<Root>/Logical Operator10'
   */
  rtb_DigitalInput_o2 = (rtb_LogicalOperator6 && rtb_DigitalInput_o2);

  /* Logic: '<Root>/Logical Operator7' incorporates:
   *  Logic: '<Root>/Logical Operator3'
   *  Logic: '<Root>/Logical Operator4'
   *  Logic: '<Root>/Logical Operator5'
   */
  rtb_LogicalOperator7 = ((rtb_DigitalInput_o1 && rtb_LogicalOperator2) || (rtb_DigitalInput_o2 &&
    rtb_LogicalOperator2) || (rtb_LogicalOperator7 && rtb_DigitalInput_o3));

  /* Logic: '<Root>/Logical Operator11' incorporates:
   *  Logic: '<Root>/Logical Operator10'
   *  Logic: '<Root>/Logical Operator8'
   *  Logic: '<Root>/Logical Operator9'
   */
  rtb_DigitalInput_o3 = ((rtb_LogicalOperator12_tmp && rtb_LogicalOperator2) || (rtb_DigitalInput_o1 &&
    rtb_DigitalInput_o3) || (rtb_DigitalInput_o2 && rtb_DigitalInput_o3));

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_LogicalOperator;
  LATBbits.LATB1 = rtb_LogicalOperator7;
  LATBbits.LATB2 = rtb_DigitalInput_o3;
  LATBbits.LATB3 = rtb_LogicalOperator12;
}

/* Model initialize function */
void ornek_13_3_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_13_3_terminate(void)
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
    ornek_13_3_step();

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
