/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney9.h
 *
 * Code generated for Simulink model 'deney9'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jun  3 14:34:43 2026
 */

#ifndef RTW_HEADER_deney9_h_
#define RTW_HEADER_deney9_h_
#ifndef deney9_COMMON_INCLUDES_
#define deney9_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* deney9_COMMON_INCLUDES_ */

#define FCY                            (16000000UL)              /* Instruction Frequency FCY set at  16.0 MHz */

/* Include for pic 30F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "deney9_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  real_T Memory4_PreviousInput;        /* '<Root>/Memory4' */
  real_T Memory3_PreviousInput;        /* '<Root>/Memory3' */
  uint32_T Counter_ClkEphState;        /* '<Root>/Counter' */
  uint32_T Counter_RstEphState;        /* '<Root>/Counter' */
  uint32_T Counter1_ClkEphState;       /* '<Root>/Counter1' */
  uint32_T Counter1_RstEphState;       /* '<Root>/Counter1' */
  struct {
    uint_T OR:1;                       /* '<Root>/OR' */
    uint_T OR1:1;                      /* '<Root>/OR1' */
    uint_T UnitDelay_DSTATE:1;         /* '<S19>/Unit Delay' */
    uint_T UnitDelay_DSTATE_m:1;       /* '<S13>/Unit Delay' */
    uint_T UnitDelay_DSTATE_d:1;       /* '<S16>/Unit Delay' */
  } bitsForTID0;

  uint8_T Counter_Count;               /* '<Root>/Counter' */
  uint8_T Counter1_Count;              /* '<Root>/Counter1' */
  boolean_T RelationalOperator1;       /* '<S21>/Relational Operator1' */
  boolean_T RelationalOperator1_p;     /* '<S20>/Relational Operator1' */
  boolean_T RelationalOperator1_c;     /* '<S18>/Relational Operator1' */
  boolean_T RelationalOperator1_l;     /* '<S17>/Relational Operator1' */
  boolean_T RelationalOperator1_g;     /* '<S15>/Relational Operator1' */
  boolean_T RelationalOperator1_a;     /* '<S14>/Relational Operator1' */
} DW_deney9_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S13>/Multiport Switch' */
  const real_T MultiportSwitch_j[2];   /* '<S16>/Multiport Switch' */
  const real_T MultiportSwitch_b[2];   /* '<S19>/Multiport Switch' */
} ConstB_deney9_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [1 3 2 6 4 12 8 9].'
   * Referenced by: '<Root>/Constant2'
   */
  real_T Constant2_Value[8];
} ConstP_deney9_T;

/* Block signals and states (default storage) */
extern DW_deney9_T deney9_DW;
extern const ConstB_deney9_T deney9_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_deney9_T deney9_ConstP;

/* Model entry point functions */
extern void deney9_initialize(void);
extern void deney9_step(void);
extern void deney9_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S7>/FixPt Gateway In' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S12>/FixPt Gateway In' : Eliminate redundant data type conversion
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
 * '<Root>' : 'deney9'
 * '<S1>'   : 'deney9/Compare To Constant'
 * '<S2>'   : 'deney9/Compare To Constant1'
 * '<S3>'   : 'deney9/Compare To Constant2'
 * '<S4>'   : 'deney9/Compare To Constant3'
 * '<S5>'   : 'deney9/Compare To Constant4'
 * '<S6>'   : 'deney9/Compare To Constant5'
 * '<S7>'   : 'deney9/Decrement Stored Integer'
 * '<S8>'   : 'deney9/Digital Output'
 * '<S9>'   : 'deney9/Edge Detector'
 * '<S10>'  : 'deney9/Edge Detector1'
 * '<S11>'  : 'deney9/Edge Detector2'
 * '<S12>'  : 'deney9/Increment Stored Integer'
 * '<S13>'  : 'deney9/Edge Detector/Model'
 * '<S14>'  : 'deney9/Edge Detector/Model/NEGATIVE Edge'
 * '<S15>'  : 'deney9/Edge Detector/Model/POSITIVE Edge'
 * '<S16>'  : 'deney9/Edge Detector1/Model'
 * '<S17>'  : 'deney9/Edge Detector1/Model/NEGATIVE Edge'
 * '<S18>'  : 'deney9/Edge Detector1/Model/POSITIVE Edge'
 * '<S19>'  : 'deney9/Edge Detector2/Model'
 * '<S20>'  : 'deney9/Edge Detector2/Model/NEGATIVE Edge'
 * '<S21>'  : 'deney9/Edge Detector2/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_deney9_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
