/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_9.c
 *
 * Code generated for Simulink model 'ornek_6_9'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Aug 24 21:06:49 2026
 */

#include "ornek_6_9.h"
#include "ornek_6_9_private.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_6_9_T ornek_6_9_DW;
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
void ornek_6_9_step(void)
{
  uint16_T rtb_DataTypeConversion1;
  boolean_T rtb_DigitalInput_o1;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTBbits.RB0; /* Read pin B0 */
  ornek_6_9_DW.DigitalInput_o2 = PORTBbits.RB1;/* Read pin B1 */

  /* S-Function (sdspcount2): '<Root>/Counter' */
  if (MWDSP_EPH_R_B(ornek_6_9_DW.DigitalInput_o2, &ornek_6_9_DW.Counter_RstEphState) != 0UL) {
    ornek_6_9_DW.Counter_Count = 0U;
  }

  if (MWDSP_EPH_R_B(rtb_DigitalInput_o1, &ornek_6_9_DW.Counter_ClkEphState) != 0UL) {
    if (ornek_6_9_DW.Counter_Count < 255) {
      ornek_6_9_DW.Counter_Count++;
    } else {
      ornek_6_9_DW.Counter_Count = 0U;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  S-Function (sdspcount2): '<Root>/Counter'
   */
  rtb_DataTypeConversion1 = ornek_6_9_DW.Counter_Count;

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATC = rtb_DataTypeConversion1;      /* No mask required : all pins defined as digital output are updated */
}

/* Model initialize function */
void ornek_6_9_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter' */
  ornek_6_9_DW.Counter_ClkEphState = 5UL;
  ornek_6_9_DW.Counter_RstEphState = 5UL;
}

/* Model terminate function */
void ornek_6_9_terminate(void)
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
    ornek_6_9_step();

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
