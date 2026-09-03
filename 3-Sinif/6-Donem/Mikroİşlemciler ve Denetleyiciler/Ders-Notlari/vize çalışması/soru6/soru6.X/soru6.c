/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru6.c
 *
 * Code generated for Simulink model 'soru6'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Sep  3 21:52:54 2026
 */

#include "soru6.h"
#include "rtwtypes.h"
#include "soru6_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>

/* Block signals and states (default storage) */
DW_soru6_T soru6_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/*
 * Output and update for enable system:
 *    '<S12>/NEGATIVE Edge'
 *    '<S15>/NEGATIVE Edge'
 *    '<S18>/NEGATIVE Edge'
 *    '<S21>/NEGATIVE Edge'
 */
void soru6_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S12>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S13>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S12>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S12>/POSITIVE Edge'
 *    '<S15>/POSITIVE Edge'
 *    '<S18>/POSITIVE Edge'
 *    '<S21>/POSITIVE Edge'
 */
void soru6_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T *rty_OUT)
{
  /* Outputs for Enabled SubSystem: '<S12>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S14>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S12>/POSITIVE Edge' */
}

uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  uint32_T previousState;
  uint32_T retVal;
  int16_T curState;
  int16_T lastzcevent;
  int16_T newState;
  int16_T newStateR;

  /* S-Function (sdspcount2): '<Root>/Counter' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0UL;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (*sta == 5UL) {
    newStateR = curState;
  } else if ((uint32_T)curState != *sta) {
    if (*sta == 3UL) {
      if ((uint16_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 2;
        previousState = 1UL;
      }
    }

    if (previousState == 4UL) {
      if ((uint16_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 3;
        previousState = 1UL;
      }
    }

    if ((previousState == 1UL) && ((uint16_T)curState == 2U)) {
      retVal = 2UL;
    }

    if (previousState == 0UL) {
      retVal = 2UL;
    }

    if ((uint16_T)retVal == (uint16_T)lastzcevent) {
      retVal = 0UL;
    }

    if (((uint16_T)curState == 1U) && ((uint16_T)retVal == 2U)) {
      newState = 3;
    } else {
      newState = curState;
    }
  }

  if ((uint16_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0UL;
  }

  if ((uint16_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<Root>/Counter' */
  return retVal;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void soru6_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput1_o1;
  boolean_T rtb_DigitalInput1_o2;
  boolean_T rtb_DigitalInput1_o3;
  real_T rtb_Memory1;
  boolean_T rtb_Logic_g_idx_0;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_Memory;

  /* Memory: '<Root>/Memory1' */
  rtb_Memory1 = soru6_DW.Memory1_PreviousInput;

  /* Logic: '<Root>/Logical Operator2' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Memory: '<Root>/Memory1'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   */
  rtb_LogicalOperator2 = ((soru6_DW.Memory1_PreviousInput <= 2.0) && (soru6_DW.Memory1_PreviousInput > 0.0));

  /* Memory: '<Root>/Memory' */
  rtb_Memory = soru6_DW.bitsForTID0.Memory_PreviousInput;

  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' */
  LATBbits.LATB1 = rtb_Memory;

  /* S-Function (MCHP_Digital_Output_Write): '<S5>/Digital Output Write' */
  LATBbits.LATB0 = rtb_LogicalOperator2;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input1' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input1/Output */
  rtb_DigitalInput1_o1 = PORTCbits.RC0;/* Read pin C0 */
  rtb_DigitalInput1_o2 = PORTCbits.RC1;/* Read pin C1 */
  rtb_DigitalInput1_o3 = PORTCbits.RC2;/* Read pin C2 */

  /* Outputs for Enabled SubSystem: '<S15>/POSITIVE Edge' */
  /* UnitDelay: '<S15>/Unit Delay' */
  soru6_POSITIVEEdge(soru6_ConstB.MultiportSwitch_b[0], rtb_DigitalInput1_o2,
                     soru6_DW.bitsForTID0.UnitDelay_DSTATE, &soru6_DW.RelationalOperator1_j);

  /* End of Outputs for SubSystem: '<S15>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S15>/NEGATIVE Edge' */
  soru6_NEGATIVEEdge(soru6_ConstB.MultiportSwitch_b[1], rtb_DigitalInput1_o2,
                     soru6_DW.bitsForTID0.UnitDelay_DSTATE, &soru6_DW.RelationalOperator1_d);

  /* End of Outputs for SubSystem: '<S15>/NEGATIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S12>/POSITIVE Edge' */
  /* UnitDelay: '<S12>/Unit Delay' */
  soru6_POSITIVEEdge(soru6_ConstB.MultiportSwitch[0], rtb_DigitalInput1_o1,
                     soru6_DW.bitsForTID0.UnitDelay_DSTATE_h, &soru6_DW.RelationalOperator1_m);

  /* End of Outputs for SubSystem: '<S12>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S12>/NEGATIVE Edge' */
  soru6_NEGATIVEEdge(soru6_ConstB.MultiportSwitch[1], rtb_DigitalInput1_o1,
                     soru6_DW.bitsForTID0.UnitDelay_DSTATE_h, &soru6_DW.RelationalOperator1_c);

  /* End of Outputs for SubSystem: '<S12>/NEGATIVE Edge' */

  /* S-Function (sdspcount2): '<Root>/Counter' incorporates:
   *  Logic: '<Root>/Logical Operator'
   *  Logic: '<S12>/Logical Operator1'
   */
  if (MWDSP_EPH_R_B(((soru6_DW.RelationalOperator1_m || soru6_DW.RelationalOperator1_c) && rtb_Memory),
                    &soru6_DW.Counter_ClkEphState) != 0UL) {
    if (soru6_DW.Counter_Count < 9999U) {
      soru6_DW.Counter_Count++;
    } else {
      soru6_DW.Counter_Count = 0U;
    }
  }

  /* Outputs for Enabled SubSystem: '<S18>/POSITIVE Edge' */
  /* UnitDelay: '<S18>/Unit Delay' */
  soru6_POSITIVEEdge(soru6_ConstB.MultiportSwitch_k[0], rtb_DigitalInput1_o3,
                     soru6_DW.bitsForTID0.UnitDelay_DSTATE_f, &soru6_DW.RelationalOperator1_e);

  /* End of Outputs for SubSystem: '<S18>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S18>/NEGATIVE Edge' */
  soru6_NEGATIVEEdge(soru6_ConstB.MultiportSwitch_k[1], rtb_DigitalInput1_o3,
                     soru6_DW.bitsForTID0.UnitDelay_DSTATE_f, &soru6_DW.RelationalOperator1_n);

  /* End of Outputs for SubSystem: '<S18>/NEGATIVE Edge' */

  /* CombinatorialLogic: '<S10>/Logic' incorporates:
   *  Logic: '<Root>/Logical Operator1'
   *  Logic: '<S15>/Logical Operator1'
   *  Logic: '<S18>/Logical Operator1'
   *  Memory: '<S10>/Memory'
   *  S-Function (sdspcount2): '<Root>/Counter'
   */
  rtb_LogicalOperator2 = soru6_ConstP.pooled8[((((uint16_T)(soru6_DW.RelationalOperator1_j ||
    soru6_DW.RelationalOperator1_d) << 1) + (uint16_T)(soru6_DW.RelationalOperator1_e ||
    soru6_DW.RelationalOperator1_n || (soru6_DW.Counter_Count == 1000U))) << 1) +
    soru6_DW.bitsForTID0.Memory_PreviousInput_j];

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S3>/Constant'
   *  Math: '<Root>/Mod'
   *  S-Function (sdspcount2): '<Root>/Counter'
   */
  rtb_Memory = (rt_modd_snf((real_T)soru6_DW.Counter_Count, 5.0) == 0.0);

  /* Outputs for Enabled SubSystem: '<S21>/POSITIVE Edge' */
  /* UnitDelay: '<S21>/Unit Delay' */
  soru6_POSITIVEEdge(soru6_ConstB.MultiportSwitch_n[0], rtb_Memory, soru6_DW.bitsForTID0.UnitDelay_DSTATE_d,
                     &soru6_DW.RelationalOperator1);

  /* End of Outputs for SubSystem: '<S21>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S21>/NEGATIVE Edge' */
  soru6_NEGATIVEEdge(soru6_ConstB.MultiportSwitch_n[1], rtb_Memory, soru6_DW.bitsForTID0.UnitDelay_DSTATE_d,
                     &soru6_DW.RelationalOperator1_g);

  /* End of Outputs for SubSystem: '<S21>/NEGATIVE Edge' */

  /* CombinatorialLogic: '<S11>/Logic' incorporates:
   *  Constant: '<Root>/Constant9'
   *  Logic: '<S21>/Logical Operator1'
   *  Memory: '<S11>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  rtb_Logic_g_idx_0 = soru6_ConstP.pooled8[((((uint16_T)(soru6_DW.RelationalOperator1 ||
    soru6_DW.RelationalOperator1_g) << 1) + (uint16_T)(rtb_Memory1 >= 2.0)) << 1) +
    soru6_DW.bitsForTID0.Memory_PreviousInput_p];

  /* Switch: '<Root>/Switch1' */
  if (rtb_Logic_g_idx_0) {
    /* Update for Memory: '<Root>/Memory1' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum2'
     */
    soru6_DW.Memory1_PreviousInput = rtb_Memory1 + 0.1;
  } else {
    /* Update for Memory: '<Root>/Memory1' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    soru6_DW.Memory1_PreviousInput = 0.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Update for Memory: '<Root>/Memory' */
  soru6_DW.bitsForTID0.Memory_PreviousInput = rtb_LogicalOperator2;

  /* Update for UnitDelay: '<S15>/Unit Delay' */
  soru6_DW.bitsForTID0.UnitDelay_DSTATE = rtb_DigitalInput1_o2;

  /* Update for UnitDelay: '<S12>/Unit Delay' */
  soru6_DW.bitsForTID0.UnitDelay_DSTATE_h = rtb_DigitalInput1_o1;

  /* Update for UnitDelay: '<S18>/Unit Delay' */
  soru6_DW.bitsForTID0.UnitDelay_DSTATE_f = rtb_DigitalInput1_o3;

  /* Update for Memory: '<S10>/Memory' */
  soru6_DW.bitsForTID0.Memory_PreviousInput_j = rtb_LogicalOperator2;

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  soru6_DW.bitsForTID0.UnitDelay_DSTATE_d = rtb_Memory;

  /* Update for Memory: '<S11>/Memory' */
  soru6_DW.bitsForTID0.Memory_PreviousInput_p = rtb_Logic_g_idx_0;
}

/* Model initialize function */
void soru6_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter' */
  soru6_DW.Counter_ClkEphState = 5UL;
}

/* Model terminate function */
void soru6_terminate(void)
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
    soru6_step();

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
