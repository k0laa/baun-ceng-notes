/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru4.c
 *
 * Code generated for Simulink model 'soru4'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Apr  5 00:51:19 2026
 */

#include "soru4.h"
#include "rtwtypes.h"
#include "soru4_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals and states (default storage) */
DW_soru4_T soru4_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/*
 * Output and update for enable system:
 *    '<S5>/NEGATIVE Edge'
 *    '<S8>/NEGATIVE Edge'
 *    '<S11>/NEGATIVE Edge'
 */
void soru4_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
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
 *    '<S11>/POSITIVE Edge'
 */
void soru4_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
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
void soru4_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_DigitalInput_o2;
  boolean_T rtb_DigitalInput_o3;
  real_T rtb_Memory;
  real_T tmp;
  uint16_T rtb_DataTypeConversion1;

  /* Memory: '<Root>/Memory' */
  rtb_Memory = soru4_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   */
  tmp = floor(soru4_ConstP.Constant3_Value[(int16_T)soru4_DW.Memory_PreviousInput]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1 = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */
  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' */
  LATB = rtb_DataTypeConversion1;      /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTCbits.RC0; /* Read pin C0 */
  rtb_DigitalInput_o2 = PORTCbits.RC1; /* Read pin C1 */
  rtb_DigitalInput_o3 = PORTCbits.RC2; /* Read pin C2 */

  /* Outputs for Enabled SubSystem: '<S11>/POSITIVE Edge' */
  /* UnitDelay: '<S11>/Unit Delay' */
  soru4_POSITIVEEdge(soru4_ConstB.MultiportSwitch_n[0], rtb_DigitalInput_o3,
                     soru4_DW.bitsForTID0.UnitDelay_DSTATE, &soru4_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S11>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S11>/NEGATIVE Edge' */
  soru4_NEGATIVEEdge(soru4_ConstB.MultiportSwitch_n[1], rtb_DigitalInput_o3,
                     soru4_DW.bitsForTID0.UnitDelay_DSTATE, &soru4_DW.RelationalOperator1_j);

  /* End of Outputs for SubSystem: '<S11>/NEGATIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S5>/POSITIVE Edge' */
  /* UnitDelay: '<S5>/Unit Delay' */
  soru4_POSITIVEEdge(soru4_ConstB.MultiportSwitch[0], rtb_DigitalInput_o1,
                     soru4_DW.bitsForTID0.UnitDelay_DSTATE_o, &soru4_DW.RelationalOperator1_n);

  /* End of Outputs for SubSystem: '<S5>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S5>/NEGATIVE Edge' */
  soru4_NEGATIVEEdge(soru4_ConstB.MultiportSwitch[1], rtb_DigitalInput_o1,
                     soru4_DW.bitsForTID0.UnitDelay_DSTATE_o, &soru4_DW.RelationalOperator1_o);

  /* End of Outputs for SubSystem: '<S5>/NEGATIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S8>/POSITIVE Edge' */
  /* UnitDelay: '<S8>/Unit Delay' */
  soru4_POSITIVEEdge(soru4_ConstB.MultiportSwitch_c[0], rtb_DigitalInput_o2,
                     soru4_DW.bitsForTID0.UnitDelay_DSTATE_c, &soru4_DW.RelationalOperator1_f);

  /* End of Outputs for SubSystem: '<S8>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S8>/NEGATIVE Edge' */
  soru4_NEGATIVEEdge(soru4_ConstB.MultiportSwitch_c[1], rtb_DigitalInput_o2,
                     soru4_DW.bitsForTID0.UnitDelay_DSTATE_c, &soru4_DW.RelationalOperator1_jo);

  /* End of Outputs for SubSystem: '<S8>/NEGATIVE Edge' */

  /* Switch: '<Root>/Switch5' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant7'
   *  Logic: '<S11>/Logical Operator1'
   *  Logic: '<S5>/Logical Operator1'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<Root>/Relational Operator1'
   *  RelationalOperator: '<Root>/Relational Operator2'
   *  Switch: '<Root>/Switch'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch2'
   *  Switch: '<Root>/Switch3'
   *  Switch: '<Root>/Switch4'
   */
  if (soru4_DW.RelationalOperator1 || soru4_DW.RelationalOperator1_j) {
    rtb_Memory = 0.0;
  } else if (rtb_Memory == -1.0) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    rtb_Memory = 6.0;
  } else if (rtb_Memory == 7.0) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant'
     *  Switch: '<Root>/Switch2'
     */
    rtb_Memory = 0.0;
  } else if (soru4_DW.RelationalOperator1_n || soru4_DW.RelationalOperator1_o) {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Sum: '<Root>/Sum'
     *  Switch: '<Root>/Switch'
     *  Switch: '<Root>/Switch1'
     *  Switch: '<Root>/Switch2'
     */
    rtb_Memory++;
  } else if (soru4_DW.RelationalOperator1_f || soru4_DW.RelationalOperator1_jo) {
    /* Switch: '<Root>/Switch4' incorporates:
     *  Constant: '<Root>/Constant6'
     *  Sum: '<Root>/Sum1'
     *  Switch: '<Root>/Switch'
     *  Switch: '<Root>/Switch1'
     *  Switch: '<Root>/Switch2'
     */
    rtb_Memory--;
  }

  /* End of Switch: '<Root>/Switch5' */
  /* Update for Memory: '<Root>/Memory' */
  soru4_DW.Memory_PreviousInput = rtb_Memory;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  soru4_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput_o3;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  soru4_DW.bitsForTID0.UnitDelay_DSTATE_o = rtb_DigitalInput_o1;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  soru4_DW.bitsForTID0.UnitDelay_DSTATE_c = rtb_DigitalInput_o2;
}

/* Model initialize function */
void soru4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void soru4_terminate(void)
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
    soru4_step();

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
