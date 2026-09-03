/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_2.h
 *
 * Code generated for Simulink model 'soru_2'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Jun 19 23:42:19 2026
 */

#ifndef RTW_HEADER_soru_2_h_
#define RTW_HEADER_soru_2_h_
#ifndef soru_2_COMMON_INCLUDES_
#define soru_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_2_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_2_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint16_T ADC;                        /* '<Root>/ADC' */
  uint8_T Output_DSTATE;               /* '<S12>/Output' */
} DW_soru_2_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [1 2 4 8 16].'
   * Referenced by: '<Root>/Constant3'
   */
  real_T Constant3_Value[5];

  /* Expression: [28 107 119 107 28].'
   * Referenced by: '<Root>/Constant4'
   */
  real_T Constant4_Value[5];

  /* Expression: [124 123 7 123 124].'
   * Referenced by: '<Root>/Constant5'
   */
  real_T Constant5_Value[5];

  /* Expression: [30 46 54 58 60].'
   * Referenced by: '<Root>/Constant6'
   */
  real_T Constant6_Value[5];

  /* Expression: OutValues
   * Referenced by: '<S11>/Vector'
   */
  real_T Vector_Value[5];
} ConstP_soru_2_T;

/* Block signals and states (default storage) */
extern DW_soru_2_T soru_2_DW;

/* Constant parameters (default storage) */
extern const ConstP_soru_2_T soru_2_ConstP;

/* Model entry point functions */
extern void soru_2_initialize(void);
extern void soru_2_step(void);
extern void soru_2_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S11>/Out' : Eliminate redundant signal conversion block
 */

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
 * '<Root>' : 'soru_2'
 * '<S1>'   : 'soru_2/Compare To Constant'
 * '<S2>'   : 'soru_2/Compare To Constant1'
 * '<S3>'   : 'soru_2/Compare To Constant2'
 * '<S4>'   : 'soru_2/Compare To Constant3'
 * '<S5>'   : 'soru_2/Compare To Constant4'
 * '<S6>'   : 'soru_2/Compare To Constant5'
 * '<S7>'   : 'soru_2/Compare To Constant6'
 * '<S8>'   : 'soru_2/Compare To Constant7'
 * '<S9>'   : 'soru_2/Digital Output'
 * '<S10>'  : 'soru_2/Digital Output1'
 * '<S11>'  : 'soru_2/Repeating Sequence Stair1'
 * '<S12>'  : 'soru_2/Repeating Sequence Stair1/LimitedCounter'
 * '<S13>'  : 'soru_2/Repeating Sequence Stair1/LimitedCounter/Increment Real World'
 * '<S14>'  : 'soru_2/Repeating Sequence Stair1/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_soru_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
