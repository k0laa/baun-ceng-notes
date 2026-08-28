/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_14.h
 *
 * Code generated for Simulink model 'ornek_6_14'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Aug 26 20:24:21 2026
 */

#ifndef RTW_HEADER_ornek_6_14_h_
#define RTW_HEADER_ornek_6_14_h_
#ifndef ornek_6_14_COMMON_INCLUDES_
#define ornek_6_14_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_6_14_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_6_14_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  struct {
    uint_T RelationalOperator1:1;      /* '<S5>/Relational Operator1' */
    uint_T RelationalOperator1_f:1;    /* '<S4>/Relational Operator1' */
    uint_T UnitDelay_DSTATE:1;         /* '<S3>/Unit Delay' */
  } bitsForTID0;
} DW_ornek_6_14_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S3>/Multiport Switch' */
} ConstB_ornek_6_14_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [63 6 91 79 102 109 125 7 127 111 119 124 57 94 121 113 ].'
   * Referenced by: '<Root>/Constant3'
   */
  real_T Constant3_Value[16];
} ConstP_ornek_6_14_T;

/* Block signals and states (default storage) */
extern DW_ornek_6_14_T ornek_6_14_DW;
extern const ConstB_ornek_6_14_T ornek_6_14_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_ornek_6_14_T ornek_6_14_ConstP;

/* Model entry point functions */
extern void ornek_6_14_initialize(void);
extern void ornek_6_14_step(void);
extern void ornek_6_14_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ornek_6_14'
 * '<S1>'   : 'ornek_6_14/Digital Output'
 * '<S2>'   : 'ornek_6_14/Edge Detector'
 * '<S3>'   : 'ornek_6_14/Edge Detector/Model'
 * '<S4>'   : 'ornek_6_14/Edge Detector/Model/NEGATIVE Edge'
 * '<S5>'   : 'ornek_6_14/Edge Detector/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_ornek_6_14_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
