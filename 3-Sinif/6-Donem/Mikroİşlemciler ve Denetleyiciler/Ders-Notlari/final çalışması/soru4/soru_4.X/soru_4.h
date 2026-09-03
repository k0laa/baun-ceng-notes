/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_4.h
 *
 * Code generated for Simulink model 'soru_4'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Jun 15 18:32:09 2026
 */

#ifndef RTW_HEADER_soru_4_h_
#define RTW_HEADER_soru_4_h_
#ifndef soru_4_COMMON_INCLUDES_
#define soru_4_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_4_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_4_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint16_T ADC;                        /* '<Root>/ADC' */
} DW_soru_4_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [1 2 4].'
   * Referenced by: '<Root>/Constant'
   */
  real_T Constant_Value_c[3];
} ConstP_soru_4_T;

/* Block signals and states (default storage) */
extern DW_soru_4_T soru_4_DW;

/* Constant parameters (default storage) */
extern const ConstP_soru_4_T soru_4_ConstP;

/* Model entry point functions */
extern void soru_4_initialize(void);
extern void soru_4_step(void);
extern void soru_4_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'soru_4'
 * '<S1>'   : 'soru_4/Compare To Constant'
 * '<S2>'   : 'soru_4/Compare To Constant1'
 * '<S3>'   : 'soru_4/Compare To Constant2'
 * '<S4>'   : 'soru_4/Compare To Constant3'
 * '<S5>'   : 'soru_4/Compare To Constant4'
 * '<S6>'   : 'soru_4/Digital Output'
 */
#endif                                 /* RTW_HEADER_soru_4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
