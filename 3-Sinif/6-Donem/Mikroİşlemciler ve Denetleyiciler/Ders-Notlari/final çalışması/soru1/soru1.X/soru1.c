/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru1.c
 *
 * Code generated for Simulink model 'soru1'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Jun 14 23:35:26 2026
 */

#include "soru1.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Block signals and states (default storage) */
DW_soru1_T soru1_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_soru1_T soru1_PrevZCX;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void soru1_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o3;
  real_T rtb_Switch2;
  int16_T rowIdx;
  boolean_T rtb_DigitalInput_o2;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator1;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */
  rtb_DigitalInput_o3 = PORTCbits.RC2; /* Read pin C2 */

  /* CombinatorialLogic: '<S5>/Logic' incorporates:
   *  Memory: '<S5>/Memory'
   */
  rtb_DigitalInput_o2 = soru1_ConstP.Logic_table_n[((((uint16_T)rtb_DigitalInput_o1 << 1) +
    rtb_DigitalInput_o2) << 1) + soru1_DW.bitsForTID0.Memory_PreviousInput_k];

  /* Outputs for Triggered SubSystem: '<S4>/J-K Flip-Flop' incorporates:
   *  TriggerPort: '<S9>/Trigger'
   */
  if ((!rtb_DigitalInput_o1) && (soru1_PrevZCX.JKFlipFlop_Trig_ZCE != ZERO_ZCSIG)) {
    /* CombinatorialLogic: '<S9>/Logic' incorporates:
     *  Memory generated from: '<S4>/J-K Flip-Flop'
     *  Memory: '<S9>/Memory'
     */
    rowIdx = (int16_T)(((((uint16_T)soru1_DW.bitsForTID0.Memory_PreviousInput_j << 1) +
                         soru1_DW.bitsForTID0.TmpLatchAtJKFlipFlopInport1_PreviousInput) << 1) +
                       soru1_DW.bitsForTID0.TmpLatchAtJKFlipFlopInport2_PreviousInput);
    soru1_DW.Logic[0U] = soru1_ConstP.Logic_table[(uint16_T)rowIdx];
    soru1_DW.Logic[1U] = soru1_ConstP.Logic_table[(uint16_T)rowIdx + 8U];

    /* SignalConversion generated from: '<S9>/!Q' */
    soru1_DW.bitsForTID0.OutportBufferForQ = soru1_DW.Logic[1];

    /* Update for Memory: '<S9>/Memory' */
    soru1_DW.bitsForTID0.Memory_PreviousInput_j = soru1_DW.Logic[0];
  }

  soru1_PrevZCX.JKFlipFlop_Trig_ZCE = rtb_DigitalInput_o1;

  /* End of Outputs for SubSystem: '<S4>/J-K Flip-Flop' */

  /* Logic: '<Root>/Logical Operator' */
  rtb_LogicalOperator = (soru1_DW.Logic[0] && rtb_DigitalInput_o2);

  /* Logic: '<Root>/Logical Operator1' */
  rtb_LogicalOperator1 = (soru1_DW.bitsForTID0.OutportBufferForQ && rtb_DigitalInput_o2);

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATBbits.LATB1 = rtb_LogicalOperator;
  LATBbits.LATB2 = rtb_LogicalOperator1;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  if (rtb_DigitalInput_o2) {
    rtb_Switch2 = soru1_ConstP.Constant_Value_p[(int16_T)soru1_DW.Memory_PreviousInput];
  } else {
    rtb_Switch2 = 0.0;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Gain: '<Root>/Gain' */
  rtb_Switch2 = floor(39999.0 * rtb_Switch2);
  if (rtIsNaN(rtb_Switch2) || rtIsInf(rtb_Switch2)) {
    rtb_Switch2 = 0.0;
  } else {
    rtb_Switch2 = fmod(rtb_Switch2, 65536.0);
  }

  /* Gain: '<Root>/Gain' */
  soru1_DW.Gain = rtb_Switch2 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_Switch2 : (uint16_T)rtb_Switch2;

  /* S-Function (MCHP_PWM): '<Root>/PWM' */
  /* PWM Output Function !! */

  /* Outputs for Enabled SubSystem: '<S6>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (soru1_ConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
     *  UnitDelay: '<S6>/Unit Delay'
     */
    soru1_DW.bitsForTID0.RelationalOperator1 = ((int16_T)rtb_DigitalInput_o3 > (int16_T)
      soru1_DW.bitsForTID0.UnitDelay_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S6>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S6>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (soru1_ConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
     *  UnitDelay: '<S6>/Unit Delay'
     */
    soru1_DW.bitsForTID0.RelationalOperator1_d = ((int16_T)soru1_DW.bitsForTID0.UnitDelay_DSTATE > (int16_T)
      rtb_DigitalInput_o3);
  }

  /* End of Outputs for SubSystem: '<S6>/NEGATIVE Edge' */

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S1>/Constant'
   *  Logic: '<S6>/Logical Operator1'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<S1>/Compare'
   *  Switch: '<Root>/Switch1'
   */
  if (soru1_DW.Memory_PreviousInput == 5.0) {
    rtb_Switch2 = 0.0;
  } else if (soru1_DW.bitsForTID0.RelationalOperator1 || soru1_DW.bitsForTID0.RelationalOperator1_d) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Sum: '<Root>/Sum1'
     */
    rtb_Switch2 = soru1_DW.Memory_PreviousInput + 1.0;
  } else {
    /* Switch: '<Root>/Switch1' */
    rtb_Switch2 = soru1_DW.Memory_PreviousInput;
  }

  /* End of Switch: '<Root>/Switch3' */
  /* Update for Memory: '<S5>/Memory' */
  soru1_DW.bitsForTID0.Memory_PreviousInput_k = rtb_DigitalInput_o2;

  /* Update for Memory generated from: '<S4>/J-K Flip-Flop' */
  soru1_DW.bitsForTID0.TmpLatchAtJKFlipFlopInport1_PreviousInput = rtb_DigitalInput_o1;

  /* Update for Memory generated from: '<S4>/J-K Flip-Flop' */
  soru1_DW.bitsForTID0.TmpLatchAtJKFlipFlopInport2_PreviousInput = rtb_DigitalInput_o1;

  /* Update for Memory: '<Root>/Memory' */
  soru1_DW.Memory_PreviousInput = rtb_Switch2;

  /* Update for S-Function (MCHP_PWM): '<Root>/PWM' */
  P1DC1 = soru1_DW.Gain;               /* Period for Channel 1 */

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  soru1_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o3;
}

/* Model initialize function */
void soru1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_PWM): '<Root>/PWM' */
  PWM1CON1 = 0x11;
  PWM1CON2 = 0x06;
  P1DTCON1 = 0xF2B2;
  P1DTCON2 = 0x01;
  P1FLTACON = 0x87;
  P1TPER = 0x4E20;
  P1SECMP = 0x4E20;
  P1TCON = 0x8003;                     /* Enable PWM */

  /* SystemInitialize for Triggered SubSystem: '<S4>/J-K Flip-Flop' */
  /* SystemInitialize for SignalConversion generated from: '<S9>/!Q' incorporates:
   *  Outport: '<S9>/!Q'
   */
  soru1_DW.bitsForTID0.OutportBufferForQ = true;

  /* End of SystemInitialize for SubSystem: '<S4>/J-K Flip-Flop' */
}

/* Model terminate function */
void soru1_terminate(void)
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
    soru1_step();

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
