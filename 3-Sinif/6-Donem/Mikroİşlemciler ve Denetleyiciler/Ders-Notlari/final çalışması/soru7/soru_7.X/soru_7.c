/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_7.c
 *
 * Code generated for Simulink model 'soru_7'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 01:35:47 2026
 */

#include "soru_7.h"
#include "soru_7_private.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_soru_7_T soru_7_DW;

/* Real-time model */
static RT_MODEL_soru_7_T soru_7_M_;
RT_MODEL_soru_7_T *const soru_7_M = &soru_7_M_;

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
    soru_7_step0();

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
      soru_7_step1();

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
void soru_7_step0(void)                /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  soru_7_DW.ADC = ADC1BuffChannelA[0];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  LATBbits.LATB2 = false;
}

/* Model step function for TID1 */
void soru_7_step1(void)                /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Gain;
  uint16_T rtb_RateTransition1;

  /* RateTransition: '<Root>/Rate Transition1' */
  rtb_RateTransition1 = soru_7_DW.ADC;

  /* Gain: '<Root>/Gain' */
  rtb_Gain = 0.0032226443290710449 * (real_T)rtb_RateTransition1;

  /* RateTransition: '<Root>/Rate Transition' */
  soru_7_DW.RateTransition_Buffer[soru_7_DW.RateTransition_ActiveBufIdx == 0] = rtb_Gain;
  soru_7_DW.RateTransition_ActiveBufIdx = (int8_T)(soru_7_DW.RateTransition_ActiveBufIdx == 0);
}

/* Model initialize function */
void soru_7_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (soru_7_M)->Timing.TaskCounters.cLimit[0] = 1;
  (soru_7_M)->Timing.TaskCounters.cLimit[1] = 10;

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
void soru_7_terminate(void)
{
  /* (no terminate code required) */
}

void MCHP_IdleTask()
{
  /* Idle Task */
  {
    /* RateTransition: '<Root>/Rate Transition' */
    soru_7_DW.RateTransition = soru_7_DW.RateTransition_Buffer[soru_7_DW.RateTransition_ActiveBufIdx];

    /* S-Function (MCHP_IdleTask): '<Root>/Idle Task' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* S-Function (MCHP_C_function_Call): '<S2>/C Function Call' */
    PrintVoltage(
                 soru_7_DW.RateTransition
                 );

    /* End of Outputs for S-Function (MCHP_IdleTask): '<Root>/Idle Task' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
