/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru1.h
 *
 * Code generated for Simulink model 'soru1'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Jun 14 23:35:26 2026
 */

#ifndef RTW_HEADER_soru1_h_
#define RTW_HEADER_soru1_h_
#ifndef soru1_COMMON_INCLUDES_
#define soru1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru1_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru1_types.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  uint16_T Gain;                       /* '<Root>/Gain' */
  struct {
    uint_T OutportBufferForQ:1;        /* 'synthesized block' */
    uint_T RelationalOperator1:1;      /* '<S8>/Relational Operator1' */
    uint_T RelationalOperator1_d:1;    /* '<S7>/Relational Operator1' */
    uint_T UnitDelay_DSTATE:1;         /* '<S6>/Unit Delay' */
    uint_T Memory_PreviousInput_k:1;   /* '<S5>/Memory' */
    uint_T TmpLatchAtJKFlipFlopInport1_PreviousInput:1;/* synthesized block */
    uint_T TmpLatchAtJKFlipFlopInport2_PreviousInput:1;/* synthesized block */
    uint_T Memory_PreviousInput_j:1;   /* '<S9>/Memory' */
  } bitsForTID0;

  boolean_T Logic[2];                  /* '<S9>/Logic' */
} DW_soru1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState JKFlipFlop_Trig_ZCE;      /* '<S4>/J-K Flip-Flop' */
} PrevZCX_soru1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S6>/Multiport Switch' */
} ConstB_soru1_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0.45 0.65 0.85 0.05 0.25].'
   * Referenced by: '<Root>/Constant'
   */
  real_T Constant_Value_p[5];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S9>/Logic'
   */
  boolean_T Logic_table[16];

  /* Computed Parameter: Logic_table_n
   * Referenced by: '<S5>/Logic'
   */
  boolean_T Logic_table_n[16];
} ConstP_soru1_T;

/* Block signals and states (default storage) */
extern DW_soru1_T soru1_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_soru1_T soru1_PrevZCX;
extern const ConstB_soru1_T soru1_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_soru1_T soru1_ConstP;

/* Model entry point functions */
extern void soru1_initialize(void);
extern void soru1_step(void);
extern void soru1_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'soru1'
 * '<S1>'   : 'soru1/Compare To Constant'
 * '<S2>'   : 'soru1/Digital Output'
 * '<S3>'   : 'soru1/Edge Detector'
 * '<S4>'   : 'soru1/J-K Flip-Flop'
 * '<S5>'   : 'soru1/S-R Flip-Flop'
 * '<S6>'   : 'soru1/Edge Detector/Model'
 * '<S7>'   : 'soru1/Edge Detector/Model/NEGATIVE Edge'
 * '<S8>'   : 'soru1/Edge Detector/Model/POSITIVE Edge'
 * '<S9>'   : 'soru1/J-K Flip-Flop/J-K Flip-Flop'
 */
#endif                                 /* RTW_HEADER_soru1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
