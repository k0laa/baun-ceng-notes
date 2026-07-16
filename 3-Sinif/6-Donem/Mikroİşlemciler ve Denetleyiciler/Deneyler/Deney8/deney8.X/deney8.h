/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney8.h
 *
 * Code generated for Simulink model 'deney8'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May 13 13:57:13 2026
 */

#ifndef RTW_HEADER_deney8_h_
#define RTW_HEADER_deney8_h_
#ifndef deney8_COMMON_INCLUDES_
#define deney8_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* deney8_COMMON_INCLUDES_ */

#define FCY                            (16000000UL)              /* Instruction Frequency FCY set at  16.0 MHz */

/* Include for pic 30F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "deney8_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint16_T ADC;                        /* '<Root>/ADC' */
} DW_deney8_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0, 1, 3, 7, 15, 31, 63, 127, 255].'
   * Referenced by: '<Root>/Constant'
   */
  real_T Constant_Value[9];
} ConstP_deney8_T;

/* Block signals and states (default storage) */
extern DW_deney8_T deney8_DW;

/* Constant parameters (default storage) */
extern const ConstP_deney8_T deney8_ConstP;

/* Model entry point functions */
extern void deney8_initialize(void);
extern void deney8_step(void);
extern void deney8_terminate(void);

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
 * '<Root>' : 'deney8'
 * '<S1>'   : 'deney8/Digital Output'
 */
#endif                                 /* RTW_HEADER_deney8_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
