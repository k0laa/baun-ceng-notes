/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_9_2.c
 *
 * Code generated for Simulink model 'ornek_9_2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 18:35:57 2026
 */

#include "ornek_9_2.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "ornek_9_2_private.h"

/* Block signals and states (default storage) */
DW_ornek_9_2_T ornek_9_2_DW;

/* ADC - Interrupt: <Root>/ADC */
volatile uint16_T ADC1BuffChannelA[1];
void __attribute__((__interrupt__,__auto_psv__)) _T3Interrupt(void)
{
  AD1CON1 = 0x80E4;                    /* Force bits 4-7 for automatic sampling */
  _T3IF = 0;                           /* Disable Interrupt */
}

void __attribute__((__interrupt__,__auto_psv__)) _ADC1Interrupt(void)
{
  ADC1BuffChannelA[0] = ADC1BUF0;      /* Copy value from ADC buffer  */
  AD1CON1 &= 0x7FFF;                   /* Must cancel current sampling */

  {
    /* Re-enable timer or interrupt */
    _AD1IF = 0;                        /*  */
    MCHP_Scheduler();
  }
}

uint32_T MultiWord2uLong(const uint32_T u[])
{
  return u[0];
}

void uMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T i1;
  int16_T nb;
  nb = (int16_T)(n2 >> 5);
  i = 0;
  if (nb < n1) {
    int16_T nc;
    uint16_T nr;
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint16_T)nb << 5);
    if (nr > 0U) {
      uint32_T u1i;
      uint32_T yi;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << (32U - nr);
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0UL;
    i++;
  }
}

void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T n2, uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T j;
  int16_T k;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    uint32_T a0;
    uint32_T a1;
    uint32_T cb;
    uint32_T u1i;
    int16_T ni;
    cb = 0UL;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      uint32_T b1;
      uint32_T w01;
      uint32_T w10;
      uint32_T yk;
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

/* Model step function */
void ornek_9_2_step(void)
{
  uint64m_T tmp;
  uint64m_T tmp_0;
  uint32_T tmp_1;
  uint32_T tmp_2;
  uint16_T rtb_DataTypeConversion;

  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  ornek_9_2_DW.ADC = ADC1BuffChannelA[0];

  /* Gain: '<Root>/Gain1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  tmp_1 = 3355443200UL;
  tmp_2 = 54067UL * ornek_9_2_DW.ADC;
  uMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  uMultiWordShr(&tmp_0.chunks[0U], 2, 49U, &tmp.chunks[0U], 2);
  rtb_DataTypeConversion = (uint16_T)MultiWord2uLong(&tmp.chunks[0U]);

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */
}

/* Model initialize function */
void ornek_9_2_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_ADC): '<Root>/ADC' */

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Initialize */
  AD1CHS0 = 0x00;
  AD1CHS123 = 0x00;
  AD1CON3 = 0x06;
  AD1CON2 = 0x00;
  AD1CON1 = 0x8044;
  _AD1IP = 2;                          /*Interrupt Priority : 2*/
  _AD1IF = 0;
  _AD1IE = 1;                          /* Enable ADC Interrupt */
}

/* Model terminate function */
void ornek_9_2_terminate(void)
{
  /* (no terminate code required) */
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  /* Call model Scheduler */

  /* Step the model for base rate */
  ornek_9_2_step();

  /* Get model outputs here */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
