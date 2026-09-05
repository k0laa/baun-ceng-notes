/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_4.c
 *
 * Code generated for Simulink model 'ornek_13_4'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 15:11:56 2026
 */

#include "ornek_13_4.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_13_4_T ornek_13_4_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void ornek_13_4_step(void)
{
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_Logic_g[2];
  boolean_T rtb_Logic_j[2];
  boolean_T rtb_Logic_n[2];
  boolean_T rowIdx_tmp;
  boolean_T rowIdx_tmp_0;
  boolean_T rtb_DigitalInput_o3;
  boolean_T rtb_DigitalInput_o5;
  boolean_T rtb_DigitalInput_o7;
  boolean_T rtb_Memory;
  boolean_T rtb_Memory_h_tmp;
  boolean_T rtb_Memory_k;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_Memory = PORTCbits.RC0;          /* Read pin C0 */
  rtb_DigitalInput_o3 = PORTCbits.RC2; /* Read pin C2 */
  rtb_DigitalInput_o5 = PORTCbits.RC4; /* Read pin C4 */
  rtb_DigitalInput_o7 = PORTCbits.RC6; /* Read pin C6 */

  /* Memory: '<Root>/Memory2' */
  rowIdx_tmp = !ornek_13_4_DW.bitsForTID0.Memory2_PreviousInput;

  /* Memory: '<Root>/Memory1' */
  rowIdx_tmp_0 = !ornek_13_4_DW.bitsForTID0.Memory1_PreviousInput;

  /* CombinatorialLogic: '<S2>/Logic' incorporates:
   *  Logic: '<Root>/Logical Operator'
   *  Memory: '<Root>/Memory1'
   *  Memory: '<Root>/Memory2'
   *  Memory: '<S2>/Memory'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rowIdx = (int16_T)(((((uint16_T)((rowIdx_tmp_0 || rowIdx_tmp) && PORTCbits.RC1) << 1) + rtb_Memory) << 1) +
                     ornek_13_4_DW.bitsForTID0.Memory_PreviousInput);
  rtb_Logic[0U] = ornek_13_4_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic[1U] = ornek_13_4_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* Memory: '<Root>/Memory' */
  rtb_Memory_h_tmp = !ornek_13_4_DW.bitsForTID0.Memory_PreviousInput_c;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Logic: '<Root>/Logical Operator1'
   *  Memory: '<Root>/Memory'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rtb_Memory_k = ((rtb_Memory_h_tmp || rowIdx_tmp) && PORTCbits.RC3);

  /* Memory: '<S3>/Memory' */
  rtb_Memory = ornek_13_4_DW.bitsForTID0.Memory_PreviousInput_p;

  /* CombinatorialLogic: '<S3>/Logic' */
  rowIdx = (int16_T)(((((uint16_T)rtb_Memory_k << 1) + rtb_DigitalInput_o3) << 1) + rtb_Memory);
  rtb_Logic_n[0U] = ornek_13_4_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic_n[1U] = ornek_13_4_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* CombinatorialLogic: '<S4>/Logic' incorporates:
   *  Logic: '<Root>/Logical Operator2'
   *  Logic: '<Root>/OR'
   *  Memory: '<Root>/Memory3'
   *  Memory: '<S4>/Memory'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rowIdx = (int16_T)(((((uint16_T)((rtb_Memory_h_tmp || rowIdx_tmp_0) &&
    (!ornek_13_4_DW.bitsForTID0.Memory3_PreviousInput) && PORTCbits.RC5) << 1) + rtb_DigitalInput_o5) << 1) +
                     ornek_13_4_DW.bitsForTID0.Memory_PreviousInput_k);
  rtb_Logic_g[0U] = ornek_13_4_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic_g[1U] = ornek_13_4_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* CombinatorialLogic: '<S5>/Logic' incorporates:
   *  Memory: '<S5>/Memory'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rowIdx = (int16_T)(((((uint16_T)(rowIdx_tmp && PORTCbits.RC7) << 1) + rtb_DigitalInput_o7) << 1) +
                     ornek_13_4_DW.bitsForTID0.Memory_PreviousInput_f);
  rtb_Logic_j[0U] = ornek_13_4_ConstP.pooled2[(uint16_T)rowIdx];
  rtb_Logic_j[1U] = ornek_13_4_ConstP.pooled2[(uint16_T)rowIdx + 8U];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Logic[0];
  LATBbits.LATB1 = rtb_Logic_n[0];
  LATBbits.LATB2 = rtb_Logic_g[0];
  LATBbits.LATB3 = rtb_Logic_j[0];

  /* Update for Memory: '<Root>/Memory1' */
  ornek_13_4_DW.bitsForTID0.Memory1_PreviousInput = rtb_Logic_n[0];

  /* Update for Memory: '<Root>/Memory2' */
  ornek_13_4_DW.bitsForTID0.Memory2_PreviousInput = rtb_Logic_g[0];

  /* Update for Memory: '<S2>/Memory' */
  ornek_13_4_DW.bitsForTID0.Memory_PreviousInput = rtb_Logic[0];

  /* Update for Memory: '<Root>/Memory' */
  ornek_13_4_DW.bitsForTID0.Memory_PreviousInput_c = rtb_Logic[0];

  /* Update for Memory: '<S3>/Memory' */
  ornek_13_4_DW.bitsForTID0.Memory_PreviousInput_p = rtb_Logic_n[0];

  /* Update for Memory: '<Root>/Memory3' */
  ornek_13_4_DW.bitsForTID0.Memory3_PreviousInput = rtb_Logic_j[0];

  /* Update for Memory: '<S4>/Memory' */
  ornek_13_4_DW.bitsForTID0.Memory_PreviousInput_k = rtb_Logic_g[0];

  /* Update for Memory: '<S5>/Memory' */
  ornek_13_4_DW.bitsForTID0.Memory_PreviousInput_f = rtb_Logic_j[0];
}

/* Model initialize function */
void ornek_13_4_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek_13_4_terminate(void)
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
    ornek_13_4_step();

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
