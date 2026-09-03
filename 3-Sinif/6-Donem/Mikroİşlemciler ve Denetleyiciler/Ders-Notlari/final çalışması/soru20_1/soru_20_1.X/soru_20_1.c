/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_20_1.c
 *
 * Code generated for Simulink model 'soru_20_1'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Jun 23 22:12:54 2026
 */

#include "soru_20_1.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "soru_20_1_private.h"
#include <float.h>

/* Block signals and states (default storage) */
DW_soru_20_1_T soru_20_1_DW;

/* Real-time model */
static RT_MODEL_soru_20_1_T soru_20_1_M_;
RT_MODEL_soru_20_1_T *const soru_20_1_M = &soru_20_1_M_;
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

/* Model step function for TID0 */
void soru_20_1_step0(void)             /* Sample time: [1.0E-5s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void soru_20_1_step1(void)             /* Sample time: [0.001s, 0.0s] */
{
  real_T tmp_0;
  uint16_T tmp;
  uint8_T tmp_1;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.001s, 0.0s] to Sample time: [0.008s, 0.0s]  */
  (soru_20_1_M->Timing.RateInteraction.TID1_2)++;
  if ((soru_20_1_M->Timing.RateInteraction.TID1_2) > 7) {
    soru_20_1_M->Timing.RateInteraction.TID1_2 = 0;
  }

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.001s, 0.0s] to Sample time: [0.512s, 0.0s]  */
  (soru_20_1_M->Timing.RateInteraction.TID1_3)++;
  if ((soru_20_1_M->Timing.RateInteraction.TID1_3) > 511) {
    soru_20_1_M->Timing.RateInteraction.TID1_3 = 0;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<S4>/Vector'
   *  MultiPortSwitch: '<S4>/Output'
   *  UnitDelay: '<S11>/Output'
   */
  tmp_0 = floor(soru_20_1_ConstP.Vector_Value_h[soru_20_1_DW.Output_DSTATE]);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  soru_20_1_DW.DataTypeConversion2 = tmp_0 < 0.0 ? -(int16_T)(uint16_T)-tmp_0 : (int16_T)(uint16_T)tmp_0;

  /* S-Function (MCHP_BUS_I2C_MASTER): '<Root>/BUS I2C MASTER' */
  /* number of I2C blocks : 1 ; Current: 1 ; MCHP_I2C_StartImplemented =  1*/
  if (MCHP_I2C1_State == 0)            /* Free for next sequence ?*/
  {
    soru_20_1_DW.BUSI2CMASTER = I2C1_Buff8[0];
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

  /* RateTransition generated from: '<Root>/Relational Operator' */
  if (soru_20_1_M->Timing.RateInteraction.TID1_2 == 1) {
    /* RateTransition generated from: '<Root>/Relational Operator' */
    soru_20_1_DW.TmpRTBAtRelationalOperatorInport2 = soru_20_1_DW.TmpRTBAtRelationalOperatorInport2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Relational Operator' */

  /* Saturate: '<Root>/Saturation' */
  if (soru_20_1_DW.BUSI2CMASTER <= 100) {
    tmp_1 = soru_20_1_DW.BUSI2CMASTER;
  } else {
    tmp_1 = 100U;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Saturate: '<Root>/Saturation'
   */
  tmp = 163U * tmp_1;

  /* Switch: '<Root>/Switch' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  if (((tmp & 64U) != 0U) + (int16_T)(tmp >> 7) == soru_20_1_DW.TmpRTBAtRelationalOperatorInport2) {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    soru_20_1_DW.DataTypeConversion3 = MAX_uint8_T;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    soru_20_1_DW.DataTypeConversion3 = 0U;
  }

  /* End of Switch: '<Root>/Switch' */

  /* RateTransition generated from: '<Root>/C Function Call1' */
  if (soru_20_1_M->Timing.RateInteraction.TID1_3 == 1) {
    /* RateTransition generated from: '<Root>/C Function Call1' */
    soru_20_1_DW.TmpRTBAtCFunctionCall1Inport1 = soru_20_1_DW.TmpRTBAtCFunctionCall1Inport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/C Function Call1' */

  /* RateTransition generated from: '<Root>/C Function Call1' */
  if (soru_20_1_M->Timing.RateInteraction.TID1_2 == 1) {
    /* RateTransition generated from: '<Root>/C Function Call1' */
    soru_20_1_DW.TmpRTBAtCFunctionCall1Inport2 = soru_20_1_DW.TmpRTBAtCFunctionCall1Inport2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/C Function Call1' */

  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call1' */
  ekrana_yaz(
             soru_20_1_DW.TmpRTBAtCFunctionCall1Inport1
             , soru_20_1_DW.TmpRTBAtCFunctionCall1Inport2
             , soru_20_1_DW.DataTypeConversion2
             , soru_20_1_DW.DataTypeConversion3
             );

  /* Switch: '<S13>/FixPt Switch' incorporates:
   *  Constant: '<S12>/FixPt Constant'
   *  Constant: '<S13>/Constant'
   *  Sum: '<S12>/FixPt Sum1'
   *  UnitDelay: '<S11>/Output'
   */
  if ((uint8_T)(soru_20_1_DW.Output_DSTATE + 1U) > 7) {
    soru_20_1_DW.Output_DSTATE = 0U;
  } else {
    soru_20_1_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S13>/FixPt Switch' */
}

/* Model step function for TID2 */
void soru_20_1_step2(void)             /* Sample time: [0.008s, 0.0s] */
{
  real_T rtb_Mod1;
  real_T rtb_Switch1;
  int16_T rtb_DataTypeConversion1;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.008s, 0.0s] to Sample time: [0.512s, 0.0s]  */
  (soru_20_1_M->Timing.RateInteraction.TID2_3)++;
  if ((soru_20_1_M->Timing.RateInteraction.TID2_3) > 63) {
    soru_20_1_M->Timing.RateInteraction.TID2_3 = 0;
  }

  /* MultiPortSwitch: '<S3>/Output' incorporates:
   *  Constant: '<S3>/Vector'
   *  UnitDelay: '<S8>/Output'
   */
  rtb_Switch1 = soru_20_1_ConstP.Vector_Value_k[soru_20_1_DW.Output_DSTATE_o];

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<S3>/Output'
   */
  rtb_Mod1 = floor(rtb_Switch1);
  if (rtIsNaN(rtb_Mod1) || rtIsInf(rtb_Mod1)) {
    rtb_Mod1 = 0.0;
  } else {
    rtb_Mod1 = fmod(rtb_Mod1, 65536.0);
  }

  rtb_DataTypeConversion1 = rtb_Mod1 < 0.0 ? -(int16_T)(uint16_T)-rtb_Mod1 : (int16_T)(uint16_T)rtb_Mod1;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* RateTransition generated from: '<Root>/C Function Call1' */
  soru_20_1_DW.TmpRTBAtCFunctionCall1Inport2_Buffer0 = rtb_DataTypeConversion1;

  /* RateTransition generated from: '<Root>/Switch1' */
  if (soru_20_1_M->Timing.RateInteraction.TID2_3 == 1) {
    /* RateTransition generated from: '<Root>/Switch1' */
    soru_20_1_DW.TmpRTBAtSwitch1Inport2 = soru_20_1_DW.TmpRTBAtSwitch1Inport2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   */
  if (soru_20_1_DW.TmpRTBAtSwitch1Inport2 > 0.0) {
    rtb_Switch1 += 64.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Math: '<Root>/Mod1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_Mod1 = rt_modd_snf(rtb_Switch1, 128.0);

  /* RateTransition generated from: '<Root>/Relational Operator' */
  soru_20_1_DW.TmpRTBAtRelationalOperatorInport2_Buffer0 = rtb_Mod1;

  /* Switch: '<S10>/FixPt Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S9>/FixPt Constant'
   *  Sum: '<S9>/FixPt Sum1'
   *  UnitDelay: '<S8>/Output'
   */
  if ((uint8_T)(soru_20_1_DW.Output_DSTATE_o + 1U) > 63) {
    soru_20_1_DW.Output_DSTATE_o = 0U;
  } else {
    soru_20_1_DW.Output_DSTATE_o++;
  }

  /* End of Switch: '<S10>/FixPt Switch' */
}

/* Model step function for TID3 */
void soru_20_1_step3(void)             /* Sample time: [0.512s, 0.0s] */
{
  real_T rtb_FixPtSum1;
  real_T tmp;
  int16_T rtb_DataTypeConversion;

  /* MultiPortSwitch: '<S2>/Output' incorporates:
   *  Constant: '<S2>/Vector'
   *  UnitDelay: '<S5>/Output'
   */
  rtb_FixPtSum1 = soru_20_1_ConstP.Vector_Value[soru_20_1_DW.Output_DSTATE_f];

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S2>/Vector'
   *  MultiPortSwitch: '<S2>/Output'
   */
  tmp = floor(rtb_FixPtSum1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? -(int16_T)(uint16_T)-tmp : (int16_T)(uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* RateTransition generated from: '<Root>/C Function Call1' */
  soru_20_1_DW.TmpRTBAtCFunctionCall1Inport1_Buffer0 = rtb_DataTypeConversion;

  /* RateTransition generated from: '<Root>/Switch1' incorporates:
   *  Constant: '<S1>/FixPt Constant'
   *  Sum: '<S1>/FixPt Sum1'
   */
  soru_20_1_DW.TmpRTBAtSwitch1Inport2_Buffer0 = rtb_FixPtSum1 - 1.0;

  /* Switch: '<S7>/FixPt Switch' incorporates:
   *  Constant: '<S6>/FixPt Constant'
   *  Constant: '<S7>/Constant'
   *  Sum: '<S6>/FixPt Sum1'
   *  UnitDelay: '<S5>/Output'
   */
  if ((uint8_T)(soru_20_1_DW.Output_DSTATE_f + 1U) > 1) {
    soru_20_1_DW.Output_DSTATE_f = 0U;
  } else {
    soru_20_1_DW.Output_DSTATE_f++;
  }

  /* End of Switch: '<S7>/FixPt Switch' */
}

/* Model step function for TID4 */
void soru_20_1_step4(void)             /* Sample time: [1.0s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void soru_20_1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (soru_20_1_M)->Timing.TaskCounters.cLimit[0] = 1;
  (soru_20_1_M)->Timing.TaskCounters.cLimit[1] = 100;
  (soru_20_1_M)->Timing.TaskCounters.cLimit[2] = 800;
  (soru_20_1_M)->Timing.TaskCounters.cLimit[3] = 51200;
  (soru_20_1_M)->Timing.TaskCounters.cLimit[4] = 100000;

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
  glcd_hazirla(
               );
}

/* Model terminate function */
void soru_20_1_terminate(void)
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
      unsigned int Flags3 : 1;
      unsigned int Flags4 : 1;
    } static volatile Overrun __attribute__ ((near)) ;

    struct {
      unsigned int Flags1 : 1;
      unsigned int Flags2 : 1;
      unsigned int Flags3 : 1;
      unsigned int Flags4 : 1;
    } static volatile event __attribute__ ((near)) ;

    struct {
      uint_T Task1;                    /* 0.001s periodic task. Max value is 100 */
      uint_T Task2;                    /* 0.008s periodic task. Max value is 800 */
      uint_T Task3;                    /* 0.512s periodic task. Max value is 51200 */
      uint32_T Task4;                  /* 1.0s periodic task. Max value is 100000 (ensure 32 bit) */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (100 + 1 - 0 including pre-decrement */
      , .Task2 = 1                     /* Offset is 0 (800 + 1 - 0 including pre-decrement */
      , .Task3 = 1                     /* Offset is 0 (51200 + 1 - 0 including pre-decrement */
      , .Task4 = 1                     /* Offset is 0 (100000 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_T) 100;/* 0.001s periodic task. Max value is 100 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    taskCounter.Task2--;               /* Decrement task internal counter */
    if (taskCounter.Task2 == 0) {      /* task dropped on overload */
      taskCounter.Task2 = (uint16_T) 800;/* 0.008s periodic task. Max value is 800 */
      event.Flags2 = 1U;               /* Flag tag to be executed */
    }

    taskCounter.Task3--;               /* Decrement task internal counter */
    if (taskCounter.Task3 == 0) {      /* task dropped on overload */
      taskCounter.Task3 = (uint16_T) 51200;/* 0.512s periodic task. Max value is 51200 */
      event.Flags3 = 1U;               /* Flag tag to be executed */
    }

    taskCounter.Task4--;               /* Decrement task internal counter */
    if (taskCounter.Task4 == 0) {      /* task dropped on overload */
      taskCounter.Task4 = (uint32_T) 100000;/* 1.0s periodic task. Max value is 100000 */
      event.Flags4 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    soru_20_1_step0();

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
      soru_20_1_step1();

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
      soru_20_1_step2();

      /* Get model outputs here */
    }

    Overrun.Flags2 = 0U;

    /* ---------- Handle Task 3 ---------- */
    if (Overrun.Flags3) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags3) {             /* Execute task tid 3 */
      Overrun.Flags3 = 1U;
      event.Flags3 = 0U;
      soru_20_1_step3();

      /* Get model outputs here */
    }

    Overrun.Flags3 = 0U;

    /* ---------- Handle Task 4 ---------- */
    if (Overrun.Flags4) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags4) {             /* Execute task tid 4 */
      Overrun.Flags4 = 1U;
      event.Flags4 = 0U;
      soru_20_1_step4();

      /* Get model outputs here */
    }

    Overrun.Flags4 = 0U;

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
