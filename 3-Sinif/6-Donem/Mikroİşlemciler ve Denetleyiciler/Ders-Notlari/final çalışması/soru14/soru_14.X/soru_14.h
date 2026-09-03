/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_14.h
 *
 * Code generated for Simulink model 'soru_14'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 13:28:21 2026
 */

#ifndef RTW_HEADER_soru_14_h_
#define RTW_HEADER_soru_14_h_
#ifndef soru_14_COMMON_INCLUDES_
#define soru_14_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_14_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_14_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  struct {
    uint_T UnitDelay_DSTATE:1;         /* '<S11>/Unit Delay' */
    uint_T UnitDelay_DSTATE_o:1;       /* '<S5>/Unit Delay' */
    uint_T UnitDelay_DSTATE_c:1;       /* '<S8>/Unit Delay' */
  } bitsForTID0;

  boolean_T RelationalOperator1;       /* '<S13>/Relational Operator1' */
  boolean_T RelationalOperator1_j;     /* '<S12>/Relational Operator1' */
  boolean_T RelationalOperator1_f;     /* '<S10>/Relational Operator1' */
  boolean_T RelationalOperator1_jo;    /* '<S9>/Relational Operator1' */
  boolean_T RelationalOperator1_n;     /* '<S7>/Relational Operator1' */
  boolean_T RelationalOperator1_o;     /* '<S6>/Relational Operator1' */
} DW_soru_14_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S5>/Multiport Switch' */
  const real_T MultiportSwitch_c[2];   /* '<S8>/Multiport Switch' */
  const real_T MultiportSwitch_n[2];   /* '<S11>/Multiport Switch' */
} ConstB_soru_14_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [63 79 115 102 118 57 119].'
   * Referenced by: '<Root>/Constant3'
   */
  real_T Constant3_Value[7];
} ConstP_soru_14_T;

/* Block signals and states (default storage) */
extern DW_soru_14_T soru_14_DW;
extern const ConstB_soru_14_T soru_14_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_soru_14_T soru_14_ConstP;

/* Model entry point functions */
extern void soru_14_initialize(void);
extern void soru_14_step(void);
extern void soru_14_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'soru_14'
 * '<S1>'   : 'soru_14/  '
 * '<S2>'   : 'soru_14/Edge Detector'
 * '<S3>'   : 'soru_14/Edge Detector1'
 * '<S4>'   : 'soru_14/Edge Detector2'
 * '<S5>'   : 'soru_14/Edge Detector/Model'
 * '<S6>'   : 'soru_14/Edge Detector/Model/NEGATIVE Edge'
 * '<S7>'   : 'soru_14/Edge Detector/Model/POSITIVE Edge'
 * '<S8>'   : 'soru_14/Edge Detector1/Model'
 * '<S9>'   : 'soru_14/Edge Detector1/Model/NEGATIVE Edge'
 * '<S10>'  : 'soru_14/Edge Detector1/Model/POSITIVE Edge'
 * '<S11>'  : 'soru_14/Edge Detector2/Model'
 * '<S12>'  : 'soru_14/Edge Detector2/Model/NEGATIVE Edge'
 * '<S13>'  : 'soru_14/Edge Detector2/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_soru_14_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
