/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_6.h
 *
 * Code generated for Simulink model 'ornek_6_6'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Aug 24 20:35:29 2026
 */

#ifndef RTW_HEADER_ornek_6_6_h_
#define RTW_HEADER_ornek_6_6_h_
#ifndef ornek_6_6_COMMON_INCLUDES_
#define ornek_6_6_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_6_6_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_6_6_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  real_T Memory1_PreviousInput;        /* '<Root>/Memory1' */
  struct {
    uint_T RelationalOperator1:1;      /* '<S7>/Relational Operator1' */
    uint_T RelationalOperator1_a:1;    /* '<S6>/Relational Operator1' */
    uint_T UnitDelay_DSTATE:1;         /* '<S5>/Unit Delay' */
    uint_T Memory_PreviousInput_j:1;   /* '<S3>/Memory' */
    uint_T Memory_PreviousInput_a:1;   /* '<S4>/Memory' */
  } bitsForTID0;
} DW_ornek_6_6_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S5>/Multiport Switch' */
} ConstB_ornek_6_6_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S3>/Logic'
   *   '<S4>/Logic'
   */
  boolean_T pooled4[16];
} ConstP_ornek_6_6_T;

/* Block signals and states (default storage) */
extern DW_ornek_6_6_T ornek_6_6_DW;
extern const ConstB_ornek_6_6_T ornek_6_6_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_ornek_6_6_T ornek_6_6_ConstP;

/* Model entry point functions */
extern void ornek_6_6_initialize(void);
extern void ornek_6_6_step(void);
extern void ornek_6_6_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ornek_6_6'
 * '<S1>'   : 'ornek_6_6/Digital Output'
 * '<S2>'   : 'ornek_6_6/Edge Detector'
 * '<S3>'   : 'ornek_6_6/S-R Flip-Flop'
 * '<S4>'   : 'ornek_6_6/S-R Flip-Flop2'
 * '<S5>'   : 'ornek_6_6/Edge Detector/Model'
 * '<S6>'   : 'ornek_6_6/Edge Detector/Model/NEGATIVE Edge'
 * '<S7>'   : 'ornek_6_6/Edge Detector/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_ornek_6_6_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
