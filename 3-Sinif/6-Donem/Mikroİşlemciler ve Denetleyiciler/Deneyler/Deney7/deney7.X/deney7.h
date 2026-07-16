/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney7.h
 *
 * Code generated for Simulink model 'deney7'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May  6 13:54:10 2026
 */

#ifndef RTW_HEADER_deney7_h_
#define RTW_HEADER_deney7_h_
#ifndef deney7_COMMON_INCLUDES_
#define deney7_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* deney7_COMMON_INCLUDES_ */

#define FCY                            (16000000UL)              /* Instruction Frequency FCY set at  16.0 MHz */

/* Include for pic 30F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "deney7_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  struct {
    uint_T RelationalOperator1:1;      /* '<S5>/Relational Operator1' */
    uint_T RelationalOperator1_l:1;    /* '<S4>/Relational Operator1' */
    uint_T UnitDelay_DSTATE:1;         /* '<S3>/Unit Delay' */
  } bitsForTID0;
} DW_deney7_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S3>/Multiport Switch' */
} ConstB_deney7_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [56 84 118 57].'
   * Referenced by: '<Root>/Constant3'
   */
  real_T Constant3_Value[4];
} ConstP_deney7_T;

/* Block signals and states (default storage) */
extern DW_deney7_T deney7_DW;
extern const ConstB_deney7_T deney7_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_deney7_T deney7_ConstP;

/* Model entry point functions */
extern void deney7_initialize(void);
extern void deney7_step(void);
extern void deney7_terminate(void);

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
 * '<Root>' : 'deney7'
 * '<S1>'   : 'deney7/Digital Output'
 * '<S2>'   : 'deney7/Edge Detector'
 * '<S3>'   : 'deney7/Edge Detector/Model'
 * '<S4>'   : 'deney7/Edge Detector/Model/NEGATIVE Edge'
 * '<S5>'   : 'deney7/Edge Detector/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_deney7_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
