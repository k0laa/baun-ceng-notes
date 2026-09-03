/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_20.c
 *
 * Code generated for Simulink model 'soru_20'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Jun 23 21:47:15 2026
 */

#include "soru_20.h"
#include "soru_20_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <float.h>

/* Block signals and states (default storage) */
DW_soru_20_T soru_20_DW;

/* Real-time model */
static RT_MODEL_soru_20_T soru_20_M_;
RT_MODEL_soru_20_T *const soru_20_M = &soru_20_M_;
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
void soru_20_step0(void)               /* Sample time: [1.0E-5s, 0.0s] */
{
  real_T rtb_Mod;
  real_T tmp_0;
  uint16_T tmp;
  uint8_T tmp_1;

  /* Math: '<Root>/Mod' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Memory: '<Root>/Memory'
   */
  rtb_Mod = rt_modd_snf(soru_20_DW.Memory_PreviousInput, 1024.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Gain: '<Root>/Gain1'
   *  Math: '<Root>/Mod4'
   *  Rounding: '<Root>/Fix1'
   */
  tmp_0 = rt_modd_snf(floor(0.0078125 * rtb_Mod), 8.0);
  if (rtIsNaN(tmp_0)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    soru_20_DW.DataTypeConversion2 = 0;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    soru_20_DW.DataTypeConversion2 = (int16_T)tmp_0;
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Memory: '<Root>/Memory1'
   */
  tmp_0 = floor(soru_20_DW.Memory1_PreviousInput);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  soru_20_DW.DataTypeConversion = tmp_0 < 0.0 ? -(int16_T)(uint16_T)-tmp_0 : (int16_T)(uint16_T)tmp_0;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Math: '<Root>/Mod3'
   */
  tmp_0 = floor(rt_modd_snf(rtb_Mod, 64.0));
  if (rtIsNaN(tmp_0)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    soru_20_DW.DataTypeConversion1 = 0;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    soru_20_DW.DataTypeConversion1 = (int16_T)tmp_0;
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */
  /* S-Function (MCHP_BUS_I2C_MASTER): '<Root>/BUS I2C MASTER' */
  /* number of I2C blocks : 1 ; Current: 1 ; MCHP_I2C_StartImplemented =  1*/
  if (MCHP_I2C1_State == 0)            /* Free for next sequence ?*/
  {
    soru_20_DW.BUSI2CMASTER = I2C1_Buff8[0];
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

  /* Saturate: '<Root>/Saturation' */
  if (soru_20_DW.BUSI2CMASTER <= 100) {
    tmp_1 = soru_20_DW.BUSI2CMASTER;
  } else {
    tmp_1 = 100U;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Saturate: '<Root>/Saturation'
   */
  tmp = 163U * tmp_1;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Math: '<Root>/Mod1'
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  if (((tmp & 64U) != 0U) + (int16_T)(tmp >> 7) == rt_modd_snf(rtb_Mod, 128.0)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    soru_20_DW.DataTypeConversion3 = MAX_uint8_T;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    soru_20_DW.DataTypeConversion3 = 0U;
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call1' */
  ekrana_yaz(
             soru_20_DW.DataTypeConversion
             , soru_20_DW.DataTypeConversion1
             , soru_20_DW.DataTypeConversion2
             , soru_20_DW.DataTypeConversion3
             );

  /* Update for Memory: '<Root>/Memory' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   */
  soru_20_DW.Memory_PreviousInput = rtb_Mod + 1.0;

  /* Update for Memory: '<Root>/Memory1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<S1>/FixPt Constant'
   *  Gain: '<Root>/Gain'
   *  Math: '<Root>/Mod2'
   *  Rounding: '<Root>/Fix'
   *  Sum: '<S1>/FixPt Sum1'
   */
  soru_20_DW.Memory1_PreviousInput = rt_modd_snf(floor(0.015625 * rtb_Mod), 2.0) + 1.0;
}

/* Model step function for TID1 */
void soru_20_step1(void)               /* Sample time: [1.0s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void soru_20_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Set task counter limit used by the static main program */
  (soru_20_M)->Timing.TaskCounters.cLimit[0] = 1;
  (soru_20_M)->Timing.TaskCounters.cLimit[1] = 100000;

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

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  soru_20_DW.Memory1_PreviousInput = 1.0;
}

/* Model terminate function */
void soru_20_terminate(void)
{
  /* (no terminate code required) */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    struct {
      unsigned int Flags1 : 1;
    } static volatile Overrun __attribute__ ((near)) ;

    struct {
      unsigned int Flags1 : 1;
    } static volatile event __attribute__ ((near)) ;

    struct {
      uint32_T Task1;                  /* 1.0s periodic task. Max value is 100000 (ensure 32 bit) */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (100000 + 1 - 0 including pre-decrement */
    };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint32_T) 100000;/* 1.0s periodic task. Max value is 100000 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    soru_20_step0();

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
      soru_20_step1();

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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
