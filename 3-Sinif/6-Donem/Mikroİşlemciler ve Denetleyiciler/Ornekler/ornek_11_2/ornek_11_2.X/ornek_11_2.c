/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_11_2.c
 *
 * Code generated for Simulink model 'ornek_11_2'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug 30 00:31:33 2026
 */

#include "ornek_11_2.h"
#include "ornek_11_2_private.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_11_2_T ornek_11_2_DW;

/* Real-time model */
static RT_MODEL_ornek_11_2_T ornek_11_2_M_;
RT_MODEL_ornek_11_2_T *const ornek_11_2_M = &ornek_11_2_M_;

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
      uint_T Task1;                    /* 0.1s periodic task. Max value is 100 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (100 + 1 - 0 including pre-decrement */
    };

    _AD1IF = 0;                        /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 100;/* 0.1s periodic task. Max value is 100 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    ornek_11_2_step0();

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
      ornek_11_2_step1();

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
void ornek_11_2_step0(void)            /* Sample time: [0.001s, 0.0s] */
{
  real_T rtb_RateTransition;

  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  ornek_11_2_DW.ADC = ADC1BuffChannelA[0];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  LATBbits.LATB2 = false;

  /* RateTransition: '<Root>/Rate Transition2' */
  ornek_11_2_DW.RateTransition2_Buffer0 = ornek_11_2_DW.ADC;

  /* RateTransition: '<Root>/Rate Transition' */
  rtb_RateTransition = ornek_11_2_DW.RateTransition_Buffer[ornek_11_2_DW.RateTransition_ActiveBufIdx];

  /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
  ornek_11_2_DW.TmpRTBAtFunctionCallSubsystemInport2_Buffer[ornek_11_2_DW.TmpRTBAtFunctionCallSubsystemInport2_ActiveBufIdx
    == 0] = rtb_RateTransition;
  ornek_11_2_DW.TmpRTBAtFunctionCallSubsystemInport2_ActiveBufIdx = (int8_T)
    (ornek_11_2_DW.TmpRTBAtFunctionCallSubsystemInport2_ActiveBufIdx == 0);
}

/* Model step function for TID1 */
void ornek_11_2_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Gain;
  uint16_T rtb_RateTransition1;

  /* RateTransition: '<Root>/Rate Transition1' */
  rtb_RateTransition1 = ornek_11_2_DW.ADC;

  /* Gain: '<Root>/Gain' */
  rtb_Gain = 0.00322265625 * (real_T)rtb_RateTransition1;

  /* RateTransition: '<Root>/Rate Transition' */
  ornek_11_2_DW.RateTransition_Buffer[ornek_11_2_DW.RateTransition_ActiveBufIdx == 0] = rtb_Gain;
  ornek_11_2_DW.RateTransition_ActiveBufIdx = (int8_T)(ornek_11_2_DW.RateTransition_ActiveBufIdx == 0);
}

/* Model initialize function */
void ornek_11_2_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (ornek_11_2_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_11_2_M)->Timing.TaskCounters.cLimit[1] = 100;

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
void ornek_11_2_terminate(void)
{
  /* (no terminate code required) */
}

void MCHP_IdleTask()
{
  /* Idle Task */
  {
    /* RateTransition: '<Root>/Rate Transition2' */
    ornek_11_2_DW.RateTransition2 = ornek_11_2_DW.RateTransition2_Buffer0;

    /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
    ornek_11_2_DW.TmpRTBAtFunctionCallSubsystemInport2 =
      ornek_11_2_DW.TmpRTBAtFunctionCallSubsystemInport2_Buffer[ornek_11_2_DW.TmpRTBAtFunctionCallSubsystemInport2_ActiveBufIdx];

    /* S-Function (MCHP_IdleTask): '<Root>/Idle Task' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* S-Function (MCHP_C_function_Call): '<S2>/C Function Call1' */
    PrintDigital(
                 ornek_11_2_DW.RateTransition2
                 );

    /* S-Function (MCHP_C_function_Call): '<S2>/C Function Call' */
    PrintVoltage(
                 ornek_11_2_DW.TmpRTBAtFunctionCallSubsystemInport2
                 );

    /* End of Outputs for S-Function (MCHP_IdleTask): '<Root>/Idle Task' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
