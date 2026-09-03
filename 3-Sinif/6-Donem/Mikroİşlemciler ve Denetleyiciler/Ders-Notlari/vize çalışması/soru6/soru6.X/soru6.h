/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru6.h
 *
 * Code generated for Simulink model 'soru6'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Sep  3 21:52:54 2026
 */

#ifndef RTW_HEADER_soru6_h_
#define RTW_HEADER_soru6_h_
#ifndef soru6_COMMON_INCLUDES_
#define soru6_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru6_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru6_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory1_PreviousInput;        /* '<Root>/Memory1' */
  uint32_T Counter_ClkEphState;        /* '<Root>/Counter' */
  uint16_T Counter_Count;              /* '<Root>/Counter' */
  struct {
    uint_T UnitDelay_DSTATE:1;         /* '<S15>/Unit Delay' */
    uint_T UnitDelay_DSTATE_h:1;       /* '<S12>/Unit Delay' */
    uint_T UnitDelay_DSTATE_f:1;       /* '<S18>/Unit Delay' */
    uint_T UnitDelay_DSTATE_d:1;       /* '<S21>/Unit Delay' */
    uint_T Memory_PreviousInput:1;     /* '<Root>/Memory' */
    uint_T Memory_PreviousInput_j:1;   /* '<S10>/Memory' */
    uint_T Memory_PreviousInput_p:1;   /* '<S11>/Memory' */
  } bitsForTID0;

  boolean_T RelationalOperator1;       /* '<S23>/Relational Operator1' */
  boolean_T RelationalOperator1_g;     /* '<S22>/Relational Operator1' */
  boolean_T RelationalOperator1_e;     /* '<S20>/Relational Operator1' */
  boolean_T RelationalOperator1_n;     /* '<S19>/Relational Operator1' */
  boolean_T RelationalOperator1_j;     /* '<S17>/Relational Operator1' */
  boolean_T RelationalOperator1_d;     /* '<S16>/Relational Operator1' */
  boolean_T RelationalOperator1_m;     /* '<S14>/Relational Operator1' */
  boolean_T RelationalOperator1_c;     /* '<S13>/Relational Operator1' */
} DW_soru6_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S12>/Multiport Switch' */
  const real_T MultiportSwitch_b[2];   /* '<S15>/Multiport Switch' */
  const real_T MultiportSwitch_k[2];   /* '<S18>/Multiport Switch' */
  const real_T MultiportSwitch_n[2];   /* '<S21>/Multiport Switch' */
} ConstB_soru6_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S10>/Logic'
   *   '<S11>/Logic'
   */
  boolean_T pooled8[16];
} ConstP_soru6_T;

/* Block signals and states (default storage) */
extern DW_soru6_T soru6_DW;
extern const ConstB_soru6_T soru6_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_soru6_T soru6_ConstP;

/* Model entry point functions */
extern void soru6_initialize(void);
extern void soru6_step(void);
extern void soru6_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'soru6'
 * '<S1>'   : 'soru6/Compare To Constant1'
 * '<S2>'   : 'soru6/Compare To Constant2'
 * '<S3>'   : 'soru6/Compare To Constant3'
 * '<S4>'   : 'soru6/Digital Output'
 * '<S5>'   : 'soru6/Digital Output1'
 * '<S6>'   : 'soru6/Edge Detector'
 * '<S7>'   : 'soru6/Edge Detector1'
 * '<S8>'   : 'soru6/Edge Detector2'
 * '<S9>'   : 'soru6/Edge Detector3'
 * '<S10>'  : 'soru6/S-R Flip-Flop'
 * '<S11>'  : 'soru6/S-R Flip-Flop1'
 * '<S12>'  : 'soru6/Edge Detector/Model'
 * '<S13>'  : 'soru6/Edge Detector/Model/NEGATIVE Edge'
 * '<S14>'  : 'soru6/Edge Detector/Model/POSITIVE Edge'
 * '<S15>'  : 'soru6/Edge Detector1/Model'
 * '<S16>'  : 'soru6/Edge Detector1/Model/NEGATIVE Edge'
 * '<S17>'  : 'soru6/Edge Detector1/Model/POSITIVE Edge'
 * '<S18>'  : 'soru6/Edge Detector2/Model'
 * '<S19>'  : 'soru6/Edge Detector2/Model/NEGATIVE Edge'
 * '<S20>'  : 'soru6/Edge Detector2/Model/POSITIVE Edge'
 * '<S21>'  : 'soru6/Edge Detector3/Model'
 * '<S22>'  : 'soru6/Edge Detector3/Model/NEGATIVE Edge'
 * '<S23>'  : 'soru6/Edge Detector3/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_soru6_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
