/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_5.h
 *
 * Code generated for Simulink model 'soru_5'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Jun 19 23:45:56 2026
 */

#ifndef RTW_HEADER_soru_5_h_
#define RTW_HEADER_soru_5_h_
#ifndef soru_5_COMMON_INCLUDES_
#define soru_5_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_5_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_5_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  uint16_T Gain;                       /* '<Root>/Gain' */
  struct {
    uint_T UnitDelay_DSTATE:1;         /* '<S17>/Unit Delay' */
    uint_T UnitDelay_DSTATE_b:1;       /* '<S14>/Unit Delay' */
    uint_T Memory_PreviousInput_g:1;   /* '<S13>/Memory' */
    uint_T Memory_PreviousInput_n:1;   /* '<S12>/Memory' */
  } bitsForTID0;

  boolean_T RelationalOperator1;       /* '<S19>/Relational Operator1' */
  boolean_T RelationalOperator1_j;     /* '<S18>/Relational Operator1' */
  boolean_T RelationalOperator1_g;     /* '<S16>/Relational Operator1' */
  boolean_T RelationalOperator1_i;     /* '<S15>/Relational Operator1' */
} DW_soru_5_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S14>/Multiport Switch' */
  const real_T MultiportSwitch_m[2];   /* '<S17>/Multiport Switch' */
} ConstB_soru_5_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0.05 0.055 0.065 0.08 0.1].'
   * Referenced by: '<Root>/Constant5'
   */
  real_T Constant5_Value[5];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S12>/Logic'
   *   '<S13>/Logic'
   */
  boolean_T pooled11[16];
} ConstP_soru_5_T;

/* Block signals and states (default storage) */
extern DW_soru_5_T soru_5_DW;
extern const ConstB_soru_5_T soru_5_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_soru_5_T soru_5_ConstP;

/* Model entry point functions */
extern void soru_5_initialize(void);
extern void soru_5_step(void);
extern void soru_5_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S14>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'soru_5'
 * '<S1>'   : 'soru_5/Compare To Constant'
 * '<S2>'   : 'soru_5/Compare To Constant1'
 * '<S3>'   : 'soru_5/Compare To Constant2'
 * '<S4>'   : 'soru_5/Compare To Constant3'
 * '<S5>'   : 'soru_5/Compare To Constant4'
 * '<S6>'   : 'soru_5/Compare To Constant5'
 * '<S7>'   : 'soru_5/Compare To Constant6'
 * '<S8>'   : 'soru_5/Compare To Constant7'
 * '<S9>'   : 'soru_5/Compare To Constant8'
 * '<S10>'  : 'soru_5/Edge Detector'
 * '<S11>'  : 'soru_5/Edge Detector1'
 * '<S12>'  : 'soru_5/S-R Flip-Flop'
 * '<S13>'  : 'soru_5/S-R Flip-Flop1'
 * '<S14>'  : 'soru_5/Edge Detector/Model'
 * '<S15>'  : 'soru_5/Edge Detector/Model/NEGATIVE Edge'
 * '<S16>'  : 'soru_5/Edge Detector/Model/POSITIVE Edge'
 * '<S17>'  : 'soru_5/Edge Detector1/Model'
 * '<S18>'  : 'soru_5/Edge Detector1/Model/NEGATIVE Edge'
 * '<S19>'  : 'soru_5/Edge Detector1/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_soru_5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
