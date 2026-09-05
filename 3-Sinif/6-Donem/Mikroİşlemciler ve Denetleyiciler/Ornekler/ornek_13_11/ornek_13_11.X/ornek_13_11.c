/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_11.c
 *
 * Code generated for Simulink model 'ornek_13_11'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 17:32:34 2026
 */

#include "ornek_13_11.h"
#include "ornek_13_11_private.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_13_11_T ornek_13_11_DW;

/* Real-time model */
static RT_MODEL_ornek_13_11_T ornek_13_11_M_;
RT_MODEL_ornek_13_11_T *const ornek_13_11_M = &ornek_13_11_M_;

/* ADC - Interrupt: <Root>/ADC */
volatile uint16_T ADC1BuffChannelA[4];
void __attribute__((__interrupt__,__auto_psv__)) _ADC1Interrupt(void)
{
  ADC1BuffChannelA[0] = ADC1BUF0;      /* Copy value from ADC buffer  */
  ADC1BuffChannelA[1] = ADC1BUF1;      /* Copy value from ADC buffer  */
  ADC1BuffChannelA[2] = ADC1BUF2;      /* Copy value from ADC buffer  */
  ADC1BuffChannelA[3] = ADC1BUF3;      /* Copy value from ADC buffer  */

  {
    struct {
      unsigned int Flags1 : 1;
      unsigned int Flags2 : 1;
    } static volatile Overrun __attribute__ ((near)) ;

    struct {
      unsigned int Flags1 : 1;
      unsigned int Flags2 : 1;
    } static volatile event __attribute__ ((near)) ;

    struct {
      uint_T Task1;                    /* 0.1s periodic task. Max value is 100 */
      uint_T Task2;                    /* 1.0s periodic task. Max value is 1000 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (100 + 1 - 0 including pre-decrement */
      , .Task2 = 1                     /* Offset is 0 (1000 + 1 - 0 including pre-decrement */
    };

    _AD1IF = 0;                        /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 100;/* 0.1s periodic task. Max value is 100 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    taskCounter.Task2--;               /* Decrement task internal counter */
    if (taskCounter.Task2 == 0) {      /* task dropped on overload */
      taskCounter.Task2 = (uint16_T) 1000;/* 1.0s periodic task. Max value is 1000 */
      event.Flags2 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_13_11_step0();

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
      ornek_13_11_step1();

      /* Get model outputs here */
    }

    Overrun.Flags1 = 0U;

    /* ---------- Handle Task 2 ---------- */
    if (Overrun.Flags2) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags2) {             /* Execute task tid 2 */
      Overrun.Flags2 = 1U;
      event.Flags2 = 0U;
      ornek_13_11_step2();

      /* Get model outputs here */
    }

    Overrun.Flags2 = 0U;

    /* Disable Interrupt. IPL value is 1 at this point */
    {
      _IPL1 = 1;                       /* Disable Scheduler Interrupts. Rise IPL from 1 to 2 */
      _IPL0 = 0;
    }
  }
}

/* Model step function for TID0 */
void ornek_13_11_step0(void)           /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  ornek_13_11_DW.ADC_o1 = ADC1BuffChannelA[0];
  ornek_13_11_DW.ADC_o2 = ADC1BuffChannelA[1];
  ornek_13_11_DW.ADC_o3 = ADC1BuffChannelA[2];
  ornek_13_11_DW.ADC_o4 = ADC1BuffChannelA[3];

  /* RateTransition: '<Root>/Rate Transition' */
  if (ornek_13_11_DW.RateTransition_semaphoreTaken == 0) {
    ornek_13_11_DW.RateTransition_Buffer0[0] = ornek_13_11_DW.ADC_o1;
    ornek_13_11_DW.RateTransition_Buffer0[1] = ornek_13_11_DW.ADC_o2;
    ornek_13_11_DW.RateTransition_Buffer0[2] = ornek_13_11_DW.ADC_o3;
    ornek_13_11_DW.RateTransition_Buffer0[3] = ornek_13_11_DW.ADC_o4;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  LATBbits.LATB2 = false;
}

/* Model step function for TID1 */
void ornek_13_11_step1(void)           /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Gain[4];
  uint16_T rtb_RateTransition[4];

  /* RateTransition: '<Root>/Rate Transition' */
  ornek_13_11_DW.RateTransition_semaphoreTaken = 1;
  rtb_RateTransition[0] = ornek_13_11_DW.RateTransition_Buffer0[0];
  rtb_RateTransition[1] = ornek_13_11_DW.RateTransition_Buffer0[1];
  rtb_RateTransition[2] = ornek_13_11_DW.RateTransition_Buffer0[2];
  rtb_RateTransition[3] = ornek_13_11_DW.RateTransition_Buffer0[3];
  ornek_13_11_DW.RateTransition_semaphoreTaken = 0;

  /* Gain: '<Root>/Gain' */
  rtb_Gain[0] = 0.0009765625 * (real_T)rtb_RateTransition[0];
  rtb_Gain[1] = 0.0009765625 * (real_T)rtb_RateTransition[1];
  rtb_Gain[2] = 0.0009765625 * (real_T)rtb_RateTransition[2];
  rtb_Gain[3] = 0.0009765625 * (real_T)rtb_RateTransition[3];

  /* RateTransition: '<Root>/Rate Transition1' */
  ornek_13_11_DW.RateTransition1_Buffer[(ornek_13_11_DW.RateTransition1_ActiveBufIdx == 0) << 2] = rtb_Gain[0];
  ornek_13_11_DW.RateTransition1_Buffer[1 + ((ornek_13_11_DW.RateTransition1_ActiveBufIdx == 0) << 2)] =
    rtb_Gain[1];
  ornek_13_11_DW.RateTransition1_Buffer[2 + ((ornek_13_11_DW.RateTransition1_ActiveBufIdx == 0) << 2)] =
    rtb_Gain[2];
  ornek_13_11_DW.RateTransition1_Buffer[3 + ((ornek_13_11_DW.RateTransition1_ActiveBufIdx == 0) << 2)] =
    rtb_Gain[3];
  ornek_13_11_DW.RateTransition1_ActiveBufIdx = (int8_T)(ornek_13_11_DW.RateTransition1_ActiveBufIdx == 0);
}

/* Model step function for TID2 */
void ornek_13_11_step2(void)           /* Sample time: [1.0s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void ornek_13_11_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (ornek_13_11_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_13_11_M)->Timing.TaskCounters.cLimit[1] = 100;
  (ornek_13_11_M)->Timing.TaskCounters.cLimit[2] = 1000;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_ADC): '<Root>/ADC' */

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Initialize */
  AD1CSSL = 0xC3;                      /* Scan mode */
  AD1CHS0 = 0x00;
  AD1CHS123 = 0x00;
  AD1CON3 = 0x1CF9;
  AD1CON2 = 0x040C;

  /* ADC is used to trig the model Time-step. AD1CON1 will be set after the setup-code */
  _AD1IP = 2;                          /*Interrupt Priority : 2*/
  _AD1IF = 0;
  _AD1IE = 1;                          /* Enable ADC Interrupt */

  /* Start for S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  LCD_StartUp(
              );
}

/* Model terminate function */
void ornek_13_11_terminate(void)
{
  /* (no terminate code required) */
}

void MCHP_IdleTask()
{
  /* Idle Task */
  {
    int16_T tmp;

    /* RateTransition: '<Root>/Rate Transition1' */
    tmp = ornek_13_11_DW.RateTransition1_ActiveBufIdx << 2;
    ornek_13_11_DW.RateTransition1[0] = ornek_13_11_DW.RateTransition1_Buffer[tmp];
    ornek_13_11_DW.RateTransition1[1] = ornek_13_11_DW.RateTransition1_Buffer[tmp + 1];
    ornek_13_11_DW.RateTransition1[2] = ornek_13_11_DW.RateTransition1_Buffer[tmp + 2];
    ornek_13_11_DW.RateTransition1[3] = ornek_13_11_DW.RateTransition1_Buffer[tmp + 3];

    /* S-Function (MCHP_IdleTask): '<Root>/Idle Task' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* S-Function (MCHP_C_function_Call): '<S2>/C Function Call' */
    PrintV1(
            ornek_13_11_DW.RateTransition1[0]
            );

    /* S-Function (MCHP_C_function_Call): '<S2>/C Function Call1' */
    PrintV2(
            ornek_13_11_DW.RateTransition1[1]
            );

    /* S-Function (MCHP_C_function_Call): '<S2>/C Function Call2' */
    PrintV3(
            ornek_13_11_DW.RateTransition1[2]
            );

    /* S-Function (MCHP_C_function_Call): '<S2>/C Function Call3' */
    PrintV4(
            ornek_13_11_DW.RateTransition1[3]
            );

    /* End of Outputs for S-Function (MCHP_IdleTask): '<Root>/Idle Task' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
