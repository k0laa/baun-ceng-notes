/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_16.c
 *
 * Code generated for Simulink model 'soru_16'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 15:17:51 2026
 */

#include "soru_16.h"
#include "soru_16_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_soru_16_T soru_16_DW;

/* Real-time model */
static RT_MODEL_soru_16_T soru_16_M_;
RT_MODEL_soru_16_T *const soru_16_M = &soru_16_M_;

/* ADC - Interrupt: <Root>/ADC */
volatile uint16_T ADC1BuffChannelA[1];
void __attribute__((__interrupt__,__auto_psv__)) _ADC1Interrupt(void)
{
  ADC1BuffChannelA[0] = ADC1BUF0;      /* Copy value from ADC buffer  */

  {
    struct {
      unsigned int Flags1 : 1;
    } static volatile Overrun __attribute__ ((near)) ;

    struct {
      unsigned int Flags1 : 1;
    } static volatile event __attribute__ ((near)) ;

    struct {
      uint_T Task1;                    /* 0.1s periodic task. Max value is 10 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (10 + 1 - 0 including pre-decrement */
    };

    _AD1IF = 0;                        /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 10;/* 0.1s periodic task. Max value is 10 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    soru_16_step0();

    /* Get model outputs here */
    if (_AD1IF ) {
      return;                          /* Will re-enter into the interrupt */
    }

    /* Re-Enable Interrupt. IPL value is 2 at this point */
    {
      _IPL0 = 1;                       /* Enable Scheduler re-entrant interrupt. Lower IPL from 2 to 1 */
      _IPL1 = 0;
    }

    /* Step the model for any subrate */
    /* ---------- Handle Task 1 ---------- */
    if (Overrun.Flags1) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags1) {             /* Execute task tid 1 */
      Overrun.Flags1 = 1U;
      event.Flags1 = 0U;
      soru_16_step1();

      /* Get model outputs here */
    }

    Overrun.Flags1 = 0U;

    /* Disable Interrupt. IPL value is 1 at this point */
    {
      _IPL1 = 1;                       /* Disable Scheduler Interrupts. Rise IPL from 1 to 2 */
      _IPL0 = 0;
    }
  }
}

/* Model step function for TID0 */
void soru_16_step0(void)               /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_Memory;
  real_T rtb_RateTransition;
  int16_T rowIdx;
  uint16_T rtb_DataTypeConversion;
  boolean_T rtb_Logic[2];
  boolean_T rtb_Compare_a;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.01s, 0.0s] to Sample time: [0.1s, 0.0s]  */
  (soru_16_M->Timing.RateInteraction.TID0_1)++;
  if ((soru_16_M->Timing.RateInteraction.TID0_1) > 9) {
    soru_16_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition generated from: '<S1>/Compare' */
  if (soru_16_M->Timing.RateInteraction.TID0_1 == 1) {
    /* RateTransition generated from: '<S1>/Compare' */
    soru_16_DW.TmpRTBAtCompareOutport1 = soru_16_DW.TmpRTBAtCompareOutport1_Buffer0;
  }

  /* End of RateTransition generated from: '<S1>/Compare' */

  /* Memory: '<Root>/Memory' */
  rtb_Memory = soru_16_DW.Memory_PreviousInput;

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Memory: '<Root>/Memory'
   */
  rtb_Compare_a = (soru_16_DW.Memory_PreviousInput > 60.0);

  /* CombinatorialLogic: '<S7>/Logic' incorporates:
   *  Memory: '<S7>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)soru_16_DW.TmpRTBAtCompareOutport1 << 1) + rtb_Compare_a) << 1) +
                     soru_16_DW.bitsForTID0.Memory_PreviousInput_m);
  rtb_Logic[0U] = soru_16_ConstP.pooled5[(uint16_T)rowIdx];
  rtb_Logic[1U] = soru_16_ConstP.pooled5[(uint16_T)rowIdx + 8U];

  /* S-Function (MCHP_Digital_Output_Write): '<S5>/Digital Output Write' */
  LATCbits.LATC0 = soru_16_DW.TmpRTBAtCompareOutport1;
  LATCbits.LATC1 = rtb_Logic[0];

  /* RateTransition generated from: '<Root>/AND' */
  if (soru_16_M->Timing.RateInteraction.TID0_1 == 1) {
    /* RateTransition generated from: '<Root>/AND' */
    soru_16_DW.TmpRTBAtANDInport2 = soru_16_DW.TmpRTBAtANDInport2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/AND' */

  /* CombinatorialLogic: '<S8>/Logic' incorporates:
   *  Logic: '<Root>/AND'
   *  Memory: '<S8>/Memory'
   */
  rtb_Compare_a = soru_16_ConstP.pooled5[((((uint16_T)(rtb_Logic[0] && soru_16_DW.TmpRTBAtANDInport2) << 1) +
    rtb_Compare_a) << 1) + soru_16_DW.bitsForTID0.Memory_PreviousInput_md];

  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  soru_16_DW.ADC = ADC1BuffChannelA[0];

  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  LATBbits.LATB2 = false;

  /* RateTransition: '<Root>/Rate Transition' */
  rtb_RateTransition = soru_16_DW.RateTransition_Buffer[soru_16_DW.RateTransition_ActiveBufIdx];

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_RateTransition = floor(rtb_RateTransition);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  rtb_DataTypeConversion = rtb_RateTransition < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition :
    (uint16_T)rtb_RateTransition;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
  soru_16_DW.TmpRTBAtFunctionCallSubsystemInport1_Buffer0 = rtb_DataTypeConversion;

  /* Switch: '<Root>/Switch' */
  if (rtb_Compare_a) {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Sum: '<Root>/Sum1'
     */
    soru_16_DW.Memory_PreviousInput = rtb_Memory + 0.01;
  } else {
    /* Update for Memory: '<Root>/Memory' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    soru_16_DW.Memory_PreviousInput = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Update for Memory: '<S7>/Memory' */
  soru_16_DW.bitsForTID0.Memory_PreviousInput_m = rtb_Logic[0];

  /* Update for Memory: '<S8>/Memory' */
  soru_16_DW.bitsForTID0.Memory_PreviousInput_md = rtb_Compare_a;
}

/* Model step function for TID1 */
void soru_16_step1(void)               /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Sum;
  uint16_T rtb_RateTransition1;
  boolean_T rtb_Compare;

  /* RateTransition: '<Root>/Rate Transition1' */
  rtb_RateTransition1 = soru_16_DW.ADC;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   */
  rtb_Sum = 0.673828125 * (real_T)rtb_RateTransition1 + 10.0;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Compare = (rtb_Sum >= 50.0);

  /* RateTransition generated from: '<S1>/Compare' */
  soru_16_DW.TmpRTBAtCompareOutport1_Buffer0 = rtb_Compare;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Compare = (rtb_Sum < 50.0);

  /* RateTransition generated from: '<Root>/AND' */
  soru_16_DW.TmpRTBAtANDInport2_Buffer0 = rtb_Compare;

  /* RateTransition: '<Root>/Rate Transition' */
  soru_16_DW.RateTransition_Buffer[soru_16_DW.RateTransition_ActiveBufIdx == 0] = rtb_Sum;
  soru_16_DW.RateTransition_ActiveBufIdx = (int8_T)(soru_16_DW.RateTransition_ActiveBufIdx == 0);
}

/* Model initialize function */
void soru_16_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (soru_16_M)->Timing.TaskCounters.cLimit[0] = 1;
  (soru_16_M)->Timing.TaskCounters.cLimit[1] = 10;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_ADC): '<Root>/ADC' */

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Initialize */
  AD1CHS0 = 0x00;
  AD1CHS123 = 0x00;
  AD1CON3 = 0x1FFF;
  AD1CON2 = 0x00;

  /* ADC is used to trig the model Time-step. AD1CON1 will be set after the setup-code */
  _AD1IP = 2;                          /*Interrupt Priority : 2*/
  _AD1IF = 0;
  _AD1IE = 1;                          /* Enable ADC Interrupt */

  /* ConstCode for S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  LCD_StartUp(
              );
}

/* Model terminate function */
void soru_16_terminate(void)
{
  /* (no terminate code required) */
}

void MCHP_IdleTask()
{
  /* Idle Task */
  {
    /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
    soru_16_DW.TmpRTBAtFunctionCallSubsystemInport1 = soru_16_DW.TmpRTBAtFunctionCallSubsystemInport1_Buffer0;

    /* S-Function (MCHP_IdleTask): '<Root>/Idle Task' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* S-Function (MCHP_C_function_Call): '<S6>/C Function Call' */
    PrintCO(
            soru_16_DW.TmpRTBAtFunctionCallSubsystemInport1
            );

    /* End of Outputs for S-Function (MCHP_IdleTask): '<Root>/Idle Task' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
