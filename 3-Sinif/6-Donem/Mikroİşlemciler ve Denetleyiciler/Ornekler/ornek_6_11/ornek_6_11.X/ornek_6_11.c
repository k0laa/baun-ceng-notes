/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_11.c
 *
 * Code generated for Simulink model 'ornek_6_11'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Aug 26 20:06:05 2026
 */

#include "ornek_6_11.h"
#include "rtwtypes.h"
#include "ornek_6_11_private.h"

/* Block signals and states (default storage) */
DW_ornek_6_11_T ornek_6_11_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/*
 * Output and update for enable system:
 *    '<S5>/NEGATIVE Edge'
 *    '<S8>/NEGATIVE Edge'
 */
void ornek_6_11_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S5>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S6>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S5>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S5>/POSITIVE Edge'
 *    '<S8>/POSITIVE Edge'
 */
void ornek_6_11_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S5>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S7>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S5>/POSITIVE Edge' */
}

/* Model step function */
void ornek_6_11_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  real_T rtb_Memory;
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_RelationalOperator1;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = ornek_6_11_DW.Memory_PreviousInput;

  /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   */
  rtb_RelationalOperator1 = (ornek_6_11_DW.Memory_PreviousInput > 0.0);

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   */
  rtb_RelationalOperator = (ornek_6_11_DW.Memory_PreviousInput < 10.0);

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */

  /* CombinatorialLogic: '<S4>/Logic' incorporates:
   *  Logic: '<Root>/Logical Operator'
   *  Memory: '<S4>/Memory'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rowIdx = (int16_T)(((((uint16_T)(rtb_RelationalOperator1 && rtb_RelationalOperator && PORTCbits.RC2) << 1) +
                       false) << 1) + ornek_6_11_DW.bitsForTID0.Memory_PreviousInput_j);
  rtb_Logic[0U] = ornek_6_11_ConstP.Logic_table[(uint16_T)rowIdx];
  rtb_Logic[1U] = ornek_6_11_ConstP.Logic_table[(uint16_T)rowIdx + 8U];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Logic[0];

  /* Outputs for Enabled SubSystem: '<S5>/POSITIVE Edge' */
  /* UnitDelay: '<S5>/Unit Delay' */
  ornek_6_11_POSITIVEEdge(ornek_6_11_ConstB.MultiportSwitch[0], rtb_DigitalInput_o1,
    ornek_6_11_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_6_11_DW.RelationalOperator1_g);

  /* End of Outputs for SubSystem: '<S5>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S5>/NEGATIVE Edge' */
  ornek_6_11_NEGATIVEEdge(ornek_6_11_ConstB.MultiportSwitch[1], rtb_DigitalInput_o1,
    ornek_6_11_DW.bitsForTID0.UnitDelay_DSTATE, &ornek_6_11_DW.RelationalOperator1_i);

  /* End of Outputs for SubSystem: '<S5>/NEGATIVE Edge' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Logic: '<S5>/Logical Operator1'
   *  Sum: '<Root>/Sum1'
   */
  if (ornek_6_11_DW.RelationalOperator1_g || ornek_6_11_DW.RelationalOperator1_i) {
    rtb_Memory++;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S8>/POSITIVE Edge' */
  /* UnitDelay: '<S8>/Unit Delay' */
  ornek_6_11_POSITIVEEdge(ornek_6_11_ConstB.MultiportSwitch_d[0], rtb_DigitalInput_o2,
    ornek_6_11_DW.bitsForTID0.UnitDelay_DSTATE_d, &ornek_6_11_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S8>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S8>/NEGATIVE Edge' */
  ornek_6_11_NEGATIVEEdge(ornek_6_11_ConstB.MultiportSwitch_d[1], rtb_DigitalInput_o2,
    ornek_6_11_DW.bitsForTID0.UnitDelay_DSTATE_d, &ornek_6_11_DW.RelationalOperator1_o);

  /* End of Outputs for SubSystem: '<S8>/NEGATIVE Edge' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Logic: '<S8>/Logical Operator1'
   *  Sum: '<Root>/Sum'
   */
  if (ornek_6_11_DW.RelationalOperator1 || ornek_6_11_DW.RelationalOperator1_o) {
    rtb_Memory--;
  }

  /* End of Switch: '<Root>/Switch' */
  /* Update for Memory: '<Root>/Memory' */
  ornek_6_11_DW.Memory_PreviousInput = rtb_Memory;

  /* Update for Memory: '<S4>/Memory' */
  ornek_6_11_DW.bitsForTID0.Memory_PreviousInput_j = rtb_Logic[0];

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  ornek_6_11_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o1;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  ornek_6_11_DW.bitsForTID0.UnitDelay_DSTATE_d = rtb_DigitalInput_o2;
}

/* Model initialize function */
void ornek_6_11_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_6_11_terminate(void)
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
    ornek_6_11_step();

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
