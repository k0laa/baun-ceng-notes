/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_20.c
 *
 * Code generated for Simulink model 'ornek_6_20'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Aug 27 18:34:14 2026
 */

#include "ornek_6_20.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "ornek_6_20_private.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_20_T ornek_6_20_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */
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

/* Model step function */
void ornek_6_20_step(void)
{
  real_T rtb_IndexVector1;
  real_T tmp;
  uint16_T rtb_DataTypeConversion;
  boolean_T rtb_DigitalInput;

  /* MultiPortSwitch: '<S3>/Output' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<Root>/Index Vector'
   *  UnitDelay: '<S4>/Output'
   */
  rtb_IndexVector1 = ornek_6_20_ConstP.Vector_Value[ornek_6_20_DW.Output_DSTATE];

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  tmp = floor(ornek_6_20_ConstP.Constant3_Value[(int16_T)rtb_IndexVector1 - 1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTAbits.RA10;   /* Read pin A10 */

  /* Memory: '<Root>/Memory' */
  ornek_6_20_DW.bitsForTID0.Memory = ornek_6_20_DW.bitsForTID0.Memory_PreviousInput;

  /* S-Function (sdspcount2): '<Root>/Counter' */
  if (MWDSP_EPH_R_B(ornek_6_20_DW.bitsForTID0.Memory, &ornek_6_20_DW.Counter_RstEphState) != 0UL) {
    ornek_6_20_DW.Counter_Count = 0U;
  }

  if (MWDSP_EPH_R_B(rtb_DigitalInput, &ornek_6_20_DW.Counter_ClkEphState) != 0UL) {
    if (ornek_6_20_DW.Counter_Count < 255) {
      ornek_6_20_DW.Counter_Count++;
    } else {
      ornek_6_20_DW.Counter_Count = 0U;
    }
  }

  rtb_DigitalInput = (ornek_6_20_DW.Counter_Count == 3);

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  S-Function (sdspcount2): '<Root>/Counter'
   */
  switch (ornek_6_20_DW.Counter_Count) {
   case 0:
    /* MultiPortSwitch: '<Root>/Index Vector1' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<S3>/Vector'
     *  MultiPortSwitch: '<S3>/Output'
     */
    rtb_IndexVector1 = ornek_6_20_ConstP.Constant_Value[(int16_T)rtb_IndexVector1 - 1];
    break;

   case 1:
    /* MultiPortSwitch: '<Root>/Index Vector1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S3>/Vector'
     *  MultiPortSwitch: '<S3>/Output'
     */
    rtb_IndexVector1 = ornek_6_20_ConstP.Constant1_Value[(int16_T)rtb_IndexVector1 - 1];
    break;

   default:
    /* MultiPortSwitch: '<Root>/Index Vector1' incorporates:
     *  Constant: '<Root>/Constant2'
     *  MultiPortSwitch: '<Root>/Index Vector'
     */
    rtb_IndexVector1 = ornek_6_20_ConstP.Constant2_Value[(int16_T)rtb_IndexVector1 - 1];
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  tmp = floor(rtb_IndexVector1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATC = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* Switch: '<S6>/FixPt Switch' incorporates:
   *  Constant: '<S5>/FixPt Constant'
   *  Constant: '<S6>/Constant'
   *  Sum: '<S5>/FixPt Sum1'
   *  UnitDelay: '<S4>/Output'
   */
  if ((uint8_T)(ornek_6_20_DW.Output_DSTATE + 1U) > 4) {
    ornek_6_20_DW.Output_DSTATE = 0U;
  } else {
    ornek_6_20_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S6>/FixPt Switch' */
  /* Update for Memory: '<Root>/Memory' */
  ornek_6_20_DW.bitsForTID0.Memory_PreviousInput = rtb_DigitalInput;
}

/* Model initialize function */
void ornek_6_20_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter' */
  ornek_6_20_DW.Counter_ClkEphState = 5UL;
  ornek_6_20_DW.Counter_RstEphState = 5UL;
}

/* Model terminate function */
void ornek_6_20_terminate(void)
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
    ornek_6_20_step();

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
