/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_9.c
 *
 * Code generated for Simulink model 'ornek_13_9'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 17:04:42 2026
 */

#include "ornek_13_9.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ornek_13_9_private.h"

/* Block signals and states (default storage) */
DW_ornek_13_9_T ornek_13_9_DW;

/* Real-time model */
static RT_MODEL_ornek_13_9_T ornek_13_9_M_;
RT_MODEL_ornek_13_9_T *const ornek_13_9_M = &ornek_13_9_M_;

/* Model step function for TID0 */
void ornek_13_9_step0(void)            /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void ornek_13_9_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.1s, 0.0s] to Sample time: [1.0s, 0.0s]  */
  (ornek_13_9_M->Timing.RateInteraction.TID1_2)++;
  if ((ornek_13_9_M->Timing.RateInteraction.TID1_2) > 9) {
    ornek_13_9_M->Timing.RateInteraction.TID1_2 = 0;
  }

  /* RateTransition generated from: '<Root>/BUS I2C MASTER' */
  if (ornek_13_9_M->Timing.RateInteraction.TID1_2 == 1) {
    /* RateTransition generated from: '<Root>/BUS I2C MASTER' */
    ornek_13_9_DW.TmpRTBAtBUSI2CMASTERInport1 = ornek_13_9_DW.TmpRTBAtBUSI2CMASTERInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/BUS I2C MASTER' */

  /* S-Function (MCHP_BUS_I2C_MASTER): '<Root>/BUS I2C MASTER' */
  /* number of I2C blocks : 1 ; Current: 1 ; MCHP_I2C_StartImplemented =  1*/
  if (MCHP_I2C1_State == 0)            /* Free for next sequence ?*/
  {
    I2C1_Buff8[0]= ornek_13_9_DW.TmpRTBAtBUSI2CMASTERInport1;
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
}

/* Model step function for TID2 */
void ornek_13_9_step2(void)            /* Sample time: [1.0s, 0.0s] */
{
  real_T tmp;
  uint8_T rtb_DataTypeConversion;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Vector'
   *  MultiPortSwitch: '<S1>/Output'
   *  UnitDelay: '<S2>/Output'
   */
  tmp = floor(ornek_13_9_ConstP.Vector_Value[ornek_13_9_DW.Output_DSTATE]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion = (uint8_T)(tmp < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-tmp : (int16_T)(uint8_T)
    tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* RateTransition generated from: '<Root>/BUS I2C MASTER' */
  ornek_13_9_DW.TmpRTBAtBUSI2CMASTERInport1_Buffer0 = rtb_DataTypeConversion;

  /* Switch: '<S4>/FixPt Switch' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  Constant: '<S4>/Constant'
   *  Sum: '<S3>/FixPt Sum1'
   *  UnitDelay: '<S2>/Output'
   */
  if ((uint8_T)(ornek_13_9_DW.Output_DSTATE + 1U) > 9) {
    ornek_13_9_DW.Output_DSTATE = 0U;
  } else {
    ornek_13_9_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S4>/FixPt Switch' */
}

/* Model initialize function */
void ornek_13_9_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (ornek_13_9_M)->Timing.TaskCounters.cLimit[0] = 1;
  (ornek_13_9_M)->Timing.TaskCounters.cLimit[1] = 100;
  (ornek_13_9_M)->Timing.TaskCounters.cLimit[2] = 1000;

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
}

/* Model terminate function */
void ornek_13_9_terminate(void)
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
    ornek_13_9_step0();

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
      ornek_13_9_step1();

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
      ornek_13_9_step2();

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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
