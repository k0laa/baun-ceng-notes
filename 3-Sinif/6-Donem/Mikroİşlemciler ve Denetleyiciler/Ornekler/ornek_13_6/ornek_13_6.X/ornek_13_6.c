/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_6.c
 *
 * Code generated for Simulink model 'ornek_13_6'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 16:18:06 2026
 */

#include "ornek_13_6.h"
#include "ornek_13_6_private.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_ornek_13_6_T ornek_13_6_DW;

/* Real-time model */
static RT_MODEL_ornek_13_6_T ornek_13_6_M_;
RT_MODEL_ornek_13_6_T *const ornek_13_6_M = &ornek_13_6_M_;

/* Model step function for TID0 */
void ornek_13_6_step0(void)            /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void ornek_13_6_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  int16_T rtb_DataTypeConversion;
  int16_T rtb_DataTypeConversion1;

  /* S-Function (MCHP_BUS_I2C_MASTER): '<Root>/BUS I2C MASTER' */
  /* number of I2C blocks : 1 ; Current: 1 ; MCHP_I2C_StartImplemented =  1*/
  if (MCHP_I2C1_State == 0)            /* Free for next sequence ?*/
  {
    ornek_13_6_DW.BUSI2CMASTER_o1 = I2C1_Buff8[0];
    ornek_13_6_DW.BUSI2CMASTER_o2 = I2C1_Buff8[1];
    MCHP_I2C1_Request ++;
    MCHP_I2C1_State = 4;
    _MI2C1IF = 1;                      /* Force I2C1 Master Interrupt */
  } else if (MCHP_I2C1_Request > 3) {
    I2C1CONbits.I2CEN = 0;             /* Disable I2C peripheral */
    TRISBbits.TRISB9 = 0;              /* Set I2C PIN as Port Output */
    TRISBbits.TRISB8 = 0;
    MCHP_I2C1_Request = 0;
    MCHP_I2C1_State = 1;               /* try to Reset I2C BUS */
    _MI2C1IF = 1;                      /* Force I2C1 Master Interrupt */
  } else
    MCHP_I2C1_Request++;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_DataTypeConversion = ornek_13_6_DW.BUSI2CMASTER_o1;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = ornek_13_6_DW.BUSI2CMASTER_o2;

  /* RateTransition: '<Root>/Rate Transition' */
  ornek_13_6_DW.RateTransition_Buffer0 = (uint16_T)rtb_DataTypeConversion;

  /* RateTransition: '<Root>/Rate Transition1' */
  ornek_13_6_DW.RateTransition1_Buffer0 = (uint16_T)rtb_DataTypeConversion1;

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  LATBbits.LATB2 = false;
}

/* Model step function for TID2 */
void ornek_13_6_step2(void)            /* Sample time: [1.0s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void ornek_13_6_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (ornek_13_6_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_13_6_M)->Timing.TaskCounters.cLimit[1] = 100;
  (ornek_13_6_M)->Timing.TaskCounters.cLimit[2] = 1000;

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_BUS_I2C_MASTER): '<Root>/BUS I2C MASTER' */

  /* Set-up I2C 1 peripheral with Fsck = 99950   (100000 with  0.050025012506253574% error) */
  I2C1BRG = 0x018A;                    /* I2C clock = 99950  (100000 with  0.050025012506253574% error) */
  I2C1CON = 0x8300;
  LATBbits.LATB9 = 0;
      /* pin RB9 = 0 Might help to reset I2C bus when stuck (Disabling I2C peripheral force SDA & SCL to 0) */
  LATBbits.LATB8 = 0;                  /* pin RB8 = 0  */

  /* Configure I2C1 interrupt */
  _MI2C1IP = 5;                        /* Set I2C1 Master Interrupt Priority */
  _MI2C1IF = 0;                        /* Clear I2C1 Master Interrupt */
  _MI2C1IE = 1;                        /* Enable I2C1 Master Interrupt */

  /* Start for S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  LCD_StartUp(
              );
}

/* Model terminate function */
void ornek_13_6_terminate(void)
{
  /* (no terminate code required) */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
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

    _T1IF = 0;                         /* Re-enable interrupt */

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
    ornek_13_6_step0();

    /* Get model outputs here */
    if (_T1IF ) {
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
      ornek_13_6_step1();

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
      ornek_13_6_step2();

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

void MCHP_IdleTask()
{
  /* Idle Task */
  {
    /* RateTransition: '<Root>/Rate Transition' */
    ornek_13_6_DW.RateTransition = ornek_13_6_DW.RateTransition_Buffer0;

    /* RateTransition: '<Root>/Rate Transition1' */
    ornek_13_6_DW.RateTransition1 = ornek_13_6_DW.RateTransition1_Buffer0;

    /* S-Function (MCHP_IdleTask): '<Root>/Idle Task' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* S-Function (MCHP_C_function_Call): '<S2>/C Function Call' */
    PrintT1(
            ornek_13_6_DW.RateTransition
            );

    /* S-Function (MCHP_C_function_Call): '<S2>/C Function Call1' */
    PrintT2(
            ornek_13_6_DW.RateTransition1
            );

    /* End of Outputs for S-Function (MCHP_IdleTask): '<Root>/Idle Task' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
