/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_7.h
 *
 * Code generated for Simulink model 'ornek_6_7'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Aug 24 20:44:22 2026
 */

#ifndef RTW_HEADER_ornek_6_7_h_
#define RTW_HEADER_ornek_6_7_h_
#ifndef ornek_6_7_COMMON_INCLUDES_
#define ornek_6_7_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_6_7_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_6_7_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  struct {
    uint_T UnitDelay_DSTATE:1;         /* '<S6>/Unit Delay' */
    uint_T UnitDelay_DSTATE_e:1;       /* '<S9>/Unit Delay' */
    uint_T Memory_PreviousInput_j:1;   /* '<S4>/Memory' */
    uint_T Memory_PreviousInput_b:1;   /* '<S5>/Memory' */
  } bitsForTID0;

  boolean_T RelationalOperator1;       /* '<S11>/Relational Operator1' */
  boolean_T RelationalOperator1_a;     /* '<S10>/Relational Operator1' */
  boolean_T RelationalOperator1_h;     /* '<S8>/Relational Operator1' */
  boolean_T RelationalOperator1_p;     /* '<S7>/Relational Operator1' */
} DW_ornek_6_7_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S6>/Multiport Switch' */
  const real_T MultiportSwitch_o[2];   /* '<S9>/Multiport Switch' */
} ConstB_ornek_6_7_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S4>/Logic'
   *   '<S5>/Logic'
   */
  boolean_T pooled6[16];
} ConstP_ornek_6_7_T;

/* Block signals and states (default storage) */
extern DW_ornek_6_7_T ornek_6_7_DW;
extern const ConstB_ornek_6_7_T ornek_6_7_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_ornek_6_7_T ornek_6_7_ConstP;

/* Model entry point functions */
extern void ornek_6_7_initialize(void);
extern void ornek_6_7_step(void);
extern void ornek_6_7_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ornek_6_7'
 * '<S1>'   : 'ornek_6_7/Digital Output'
 * '<S2>'   : 'ornek_6_7/Edge Detector'
 * '<S3>'   : 'ornek_6_7/Edge Detector1'
 * '<S4>'   : 'ornek_6_7/S-R Flip-Flop'
 * '<S5>'   : 'ornek_6_7/S-R Flip-Flop1'
 * '<S6>'   : 'ornek_6_7/Edge Detector/Model'
 * '<S7>'   : 'ornek_6_7/Edge Detector/Model/NEGATIVE Edge'
 * '<S8>'   : 'ornek_6_7/Edge Detector/Model/POSITIVE Edge'
 * '<S9>'   : 'ornek_6_7/Edge Detector1/Model'
 * '<S10>'  : 'ornek_6_7/Edge Detector1/Model/NEGATIVE Edge'
 * '<S11>'  : 'ornek_6_7/Edge Detector1/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_ornek_6_7_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
