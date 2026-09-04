/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_12_4.h
 *
 * Code generated for Simulink model 'ornek_12_4'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 15:06:26 2026
 */

#ifndef RTW_HEADER_ornek_12_4_h_
#define RTW_HEADER_ornek_12_4_h_
#ifndef ornek_12_4_COMMON_INCLUDES_
#define ornek_12_4_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ornek_12_4_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_12_4_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  struct {
    uint_T UnitDelay_DSTATE:1;         /* '<S12>/Unit Delay' */
    uint_T UnitDelay_DSTATE_n:1;       /* '<S15>/Unit Delay' */
    uint_T UnitDelay_DSTATE_e:1;       /* '<S18>/Unit Delay' */
    uint_T Memory_PreviousInput_p:1;   /* '<S10>/Memory' */
    uint_T Memory_PreviousInput_c:1;   /* '<S11>/Memory' */
    uint_T Memory_PreviousInput_g:1;   /* '<S9>/Memory' */
  } bitsForTID0;

  boolean_T RelationalOperator1;       /* '<S20>/Relational Operator1' */
  boolean_T RelationalOperator1_f;     /* '<S19>/Relational Operator1' */
  boolean_T RelationalOperator1_h;     /* '<S17>/Relational Operator1' */
  boolean_T RelationalOperator1_a;     /* '<S16>/Relational Operator1' */
  boolean_T RelationalOperator1_n;     /* '<S14>/Relational Operator1' */
  boolean_T RelationalOperator1_p;     /* '<S13>/Relational Operator1' */
} DW_ornek_12_4_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S12>/Multiport Switch' */
  const real_T MultiportSwitch_h[2];   /* '<S15>/Multiport Switch' */
  const real_T MultiportSwitch_j[2];   /* '<S18>/Multiport Switch' */
} ConstB_ornek_12_4_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 1 3 2 6 4 12 8 9].'
   * Referenced by: '<Root>/Constant5'
   */
  real_T Constant5_Value[9];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S9>/Logic'
   *   '<S10>/Logic'
   *   '<S11>/Logic'
   */
  boolean_T pooled6[16];
} ConstP_ornek_12_4_T;

/* Block signals and states (default storage) */
extern DW_ornek_12_4_T ornek_12_4_DW;
extern const ConstB_ornek_12_4_T ornek_12_4_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_ornek_12_4_T ornek_12_4_ConstP;

/* Model entry point functions */
extern void ornek_12_4_initialize(void);
extern void ornek_12_4_step(void);
extern void ornek_12_4_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) ;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S8>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S3>/FixPt Gateway In' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S8>/FixPt Gateway In' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ornek_12_4'
 * '<S1>'   : 'ornek_12_4/Compare To Constant'
 * '<S2>'   : 'ornek_12_4/Compare To Constant1'
 * '<S3>'   : 'ornek_12_4/Decrement Stored Integer'
 * '<S4>'   : 'ornek_12_4/Digital Output'
 * '<S5>'   : 'ornek_12_4/Edge Detector'
 * '<S6>'   : 'ornek_12_4/Edge Detector1'
 * '<S7>'   : 'ornek_12_4/Edge Detector2'
 * '<S8>'   : 'ornek_12_4/Increment Stored Integer'
 * '<S9>'   : 'ornek_12_4/S-R Flip-Flop'
 * '<S10>'  : 'ornek_12_4/S-R Flip-Flop1'
 * '<S11>'  : 'ornek_12_4/S-R Flip-Flop2'
 * '<S12>'  : 'ornek_12_4/Edge Detector/Model'
 * '<S13>'  : 'ornek_12_4/Edge Detector/Model/NEGATIVE Edge'
 * '<S14>'  : 'ornek_12_4/Edge Detector/Model/POSITIVE Edge'
 * '<S15>'  : 'ornek_12_4/Edge Detector1/Model'
 * '<S16>'  : 'ornek_12_4/Edge Detector1/Model/NEGATIVE Edge'
 * '<S17>'  : 'ornek_12_4/Edge Detector1/Model/POSITIVE Edge'
 * '<S18>'  : 'ornek_12_4/Edge Detector2/Model'
 * '<S19>'  : 'ornek_12_4/Edge Detector2/Model/NEGATIVE Edge'
 * '<S20>'  : 'ornek_12_4/Edge Detector2/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_ornek_12_4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
