/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_19.c
 *
 * Code generated for Simulink model 'soru_19'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 22:48:52 2026
 */

#include "soru_19.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "soru_19_private.h"

/* Block signals and states (default storage) */
DW_soru_19_T soru_19_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* ADC - Interrupt: <Root>/ADC */
volatile uint16_T ADC1BuffChannelA[1];
void __attribute__((__interrupt__,__auto_psv__)) _T3Interrupt(void)
{
  AD1CON1 = 0x80E4;                    /* Force bits 4-7 for automatic sampling */
  _T3IF = 0;                           /* Disable Interrupt */
}

void __attribute__((__interrupt__,__auto_psv__)) _ADC1Interrupt(void)
{
  ADC1BuffChannelA[0] = ADC1BUF0;      /* Copy value from ADC buffer  */
  AD1CON1 &= 0x7FFF;                   /* Must cancel current sampling */

  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) ) ;/* Atomic bit-set: ContinueTimeStep |= 1U */
    _AD1IF = 0;                        /* Re-enable interrupt */
  }
}

/* Model step function */
void soru_19_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput;
  real_T rtb_Memory;
  real_T rtb_Switch2;
  uint32_T rtb_Gain;
  uint16_T rtb_DataTypeConversion;
  boolean_T rtb_Compare_f;
  boolean_T rtb_Logic_o_idx_0;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_Memory_b;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = soru_19_DW.Memory_PreviousInput;

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Memory: '<Root>/Memory'
   */
  rtb_Compare_f = (soru_19_DW.Memory_PreviousInput > 15.0);

  /* Memory: '<Root>/Memory2' */
  rtb_Memory_b = soru_19_DW.bitsForTID0.Memory2_PreviousInput;

  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  soru_19_DW.ADC = ADC1BuffChannelA[0];

  /* Gain: '<Root>/Gain' */
  rtb_Gain = 64000UL * soru_19_DW.ADC;

  /* CombinatorialLogic: '<S15>/Logic' incorporates:
   *  Gain: '<Root>/Gain'
   *  Logic: '<Root>/Logical Operator2'
   *  Memory: '<S15>/Memory'
   *  RelationalOperator: '<S6>/Compare'
   */
  rtb_Memory_b = soru_19_ConstP.pooled7[(((uint16_T)(rtb_Memory_b && (rtb_Gain < 3276800UL)) + ((uint16_T)
    rtb_Compare_f << 1)) << 1) + soru_19_DW.bitsForTID0.Memory_PreviousInput_b];

  /* CombinatorialLogic: '<S14>/Logic' incorporates:
   *  Gain: '<Root>/Gain'
   *  Logic: '<Root>/Logical Operator4'
   *  Logic: '<Root>/Logical Operator5'
   *  Memory: '<S14>/Memory'
   *  RelationalOperator: '<S2>/Compare'
   */
  rtb_Logic_o_idx_0 = soru_19_ConstP.pooled7[((((uint16_T)((rtb_Gain >= 52428800UL) && (!rtb_Memory_b)) << 1)
    + rtb_Compare_f) << 1) + soru_19_DW.bitsForTID0.Memory_PreviousInput_o];

  /* Logic: '<Root>/Logical Operator3' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  rtb_LogicalOperator3 = (rtb_Logic_o_idx_0 && (rtb_Memory <= 15.0));

  /* MultiPortSwitch: '<Root>/Index Vector' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Memory: '<Root>/Memory1'
   *  Switch: '<Root>/Switch4'
   */
  if (rtb_LogicalOperator3) {
    rtb_Switch2 = soru_19_DW.Memory1_PreviousInput;
  } else {
    rtb_Switch2 = 1.0;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant5'
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  Switch: '<Root>/Switch4'
   */
  rtb_Switch2 = floor(soru_19_ConstP.Constant5_Value[(int16_T)rtb_Switch2 - 1]);
  if (rtIsNaN(rtb_Switch2) || rtIsInf(rtb_Switch2)) {
    rtb_Switch2 = 0.0;
  } else {
    rtb_Switch2 = fmod(rtb_Switch2, 65536.0);
  }

  rtb_DataTypeConversion = rtb_Switch2 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_Switch2 : (uint16_T)
    rtb_Switch2;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* S-Function (MCHP_Digital_Output_Write): '<S8>/Digital Output Write' */
  {
    uint16_T WritePortB = LATB;
    LATB = WritePortB ^ (7 & (WritePortB ^ rtb_DataTypeConversion));/* Update only required pins */
  }

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTCbits.RC0;    /* Read pin C0 */

  /* Outputs for Enabled SubSystem: '<S16>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (soru_19_ConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S18>/Relational Operator1' incorporates:
     *  UnitDelay: '<S16>/Unit Delay'
     */
    soru_19_DW.bitsForTID0.RelationalOperator1 = ((int16_T)rtb_DigitalInput > (int16_T)
      soru_19_DW.bitsForTID0.UnitDelay_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S16>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S16>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (soru_19_ConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S17>/Relational Operator1' incorporates:
     *  UnitDelay: '<S16>/Unit Delay'
     */
    soru_19_DW.bitsForTID0.RelationalOperator1_f = ((int16_T)soru_19_DW.bitsForTID0.UnitDelay_DSTATE >
      (int16_T)rtb_DigitalInput);
  }

  /* End of Outputs for SubSystem: '<S16>/NEGATIVE Edge' */

  /* CombinatorialLogic: '<S13>/Logic' incorporates:
   *  Logic: '<S16>/Logical Operator1'
   *  Memory: '<S13>/Memory'
   */
  rtb_Compare_f = soru_19_ConstP.pooled7[((((uint16_T)(soru_19_DW.bitsForTID0.RelationalOperator1 ||
    soru_19_DW.bitsForTID0.RelationalOperator1_f) << 1) + rtb_Compare_f) << 1) +
    soru_19_DW.bitsForTID0.Memory_PreviousInput_p];

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Gain: '<Root>/Gain'
   *  RelationalOperator: '<S1>/Compare'
   */
  rtb_LogicalOperator = ((rtb_Gain < 52428800UL) && rtb_Compare_f);

  /* S-Function (MCHP_Digital_Output_Write): '<S9>/Digital Output Write' */
  LATBbits.LATB3 = rtb_LogicalOperator;

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Gain: '<Root>/Gain'
   *  RelationalOperator: '<S5>/Compare'
   */
  rtb_LogicalOperator = (rtb_Memory_b && (rtb_Gain >= 3276800UL));

  /* S-Function (MCHP_Digital_Output_Write): '<S10>/Digital Output Write' */
  LATBbits.LATB4 = rtb_LogicalOperator;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S7>/Constant'
   *  Memory: '<Root>/Memory1'
   *  RelationalOperator: '<S7>/Compare'
   *  Switch: '<Root>/Switch1'
   */
  if (soru_19_DW.Memory1_PreviousInput == 9.0) {
    rtb_Switch2 = 2.0;
  } else if (rtb_LogicalOperator3) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<S12>/FixPt Constant'
     *  Sum: '<S12>/FixPt Sum1'
     */
    rtb_Switch2 = soru_19_DW.Memory1_PreviousInput + 1.0;
  } else {
    /* Switch: '<Root>/Switch1' */
    rtb_Switch2 = soru_19_DW.Memory1_PreviousInput;
  }

  /* End of Switch: '<Root>/Switch2' */
  /* Switch: '<Root>/Switch' */
  if (rtb_Logic_o_idx_0) {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    soru_19_DW.Memory_PreviousInput = rtb_Memory + 0.01;
  } else {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    soru_19_DW.Memory_PreviousInput = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Update for Memory: '<Root>/Memory2' */
  soru_19_DW.bitsForTID0.Memory2_PreviousInput = rtb_Memory_b;

  /* Update for Memory: '<S15>/Memory' */
  soru_19_DW.bitsForTID0.Memory_PreviousInput_b = rtb_Memory_b;

  /* Update for Memory: '<S14>/Memory' */
  soru_19_DW.bitsForTID0.Memory_PreviousInput_o = rtb_Logic_o_idx_0;

  /* Update for Memory: '<Root>/Memory1' */
  soru_19_DW.Memory1_PreviousInput = rtb_Switch2;

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  soru_19_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput;

  /* Update for Memory: '<S13>/Memory' */
  soru_19_DW.bitsForTID0.Memory_PreviousInput_p = rtb_Compare_f;
}

/* Model initialize function */
void soru_19_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_ADC): '<Root>/ADC' */

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Initialize */
  AD1CHS0 = 0x00;
  AD1CHS123 = 0x00;
  AD1CON3 = 0x06;
  AD1CON2 = 0x00;
  AD1CON1 = 0x8044;
  _AD1IP = 2;                          /*Interrupt Priority : 2*/
  _AD1IF = 0;
  _AD1IE = 1;                          /* Enable ADC Interrupt */

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  soru_19_DW.Memory1_PreviousInput = 1.0;
}

/* Model terminate function */
void soru_19_terminate(void)
{
  /* (no terminate code required) */
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
    soru_19_step();

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
