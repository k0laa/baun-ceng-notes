/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_18.c
 *
 * Code generated for Simulink model 'soru_18'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 20:23:57 2026
 */

#include "soru_18.h"
#include "rtwtypes.h"
#include "soru_18_private.h"

/* Block signals and states (default storage) */
DW_soru_18_T soru_18_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Model step function */
void soru_18_step(void)
{
  uint16_T rtb_DataTypeConversion;

  /* S-Function (MCHP_BUS_SPI): '<Root>/BUS SPI' */
  /* number of SPI blocks : 1 ; Current: 1 ; MCHP_SPI_StartImplemented =  1*/
  if (MCHP_SPI1_State == 0)            /* Free for next sequence ?*/
  {
    soru_18_DW.BUSSPI = SPI1_Buff8[0];
    MCHP_SPI1_State = 1;
    _SPI1IF = 1;                       /* Force Interrupt */
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_DataTypeConversion = soru_18_DW.BUSSPI;

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATC = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */
}

/* Model initialize function */
void soru_18_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_BUS_SPI): '<Root>/BUS SPI' */

  /* Set-up SPI 1 peripheral with Fsck = 2.5E+6  (2.5E+6 with  0.0 % error)  */
  SPI1CON1 = 0x32;
  SPI1CON2 = 0x00;
  SPI1STAT = 0x8000;

  /* Configure SPI1 Tx tnterrupt */
  _SPI1IP = 4;                         /* Set SPI1 Interrupt Priority */
  _SPI1IF = 0;                         /* Clear SPI1 Interrupt Flag */
  _SPI1IE = 1;                         /* Enable SPI1 Interrupt */
}

/* Model terminate function */
void soru_18_terminate(void)
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
    soru_18_step();

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
