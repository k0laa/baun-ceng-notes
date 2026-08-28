/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_8_1.h
 *
 * Code generated for Simulink model 'ornek_8_1'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 18:14:52 2026
 */

#ifndef RTW_HEADER_ornek_8_1_h_
#define RTW_HEADER_ornek_8_1_h_
#ifndef ornek_8_1_COMMON_INCLUDES_
#define ornek_8_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_8_1_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_8_1_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  uint16_T Gain;                       /* '<Root>/Gain' */
  struct {
    uint_T UnitDelay_DSTATE:1;         /* '<S6>/Unit Delay' */
    uint_T UnitDelay_DSTATE_a:1;       /* '<S3>/Unit Delay' */
  } bitsForTID0;

  boolean_T RelationalOperator1;       /* '<S8>/Relational Operator1' */
  boolean_T RelationalOperator1_a;     /* '<S7>/Relational Operator1' */
  boolean_T RelationalOperator1_i;     /* '<S5>/Relational Operator1' */
  boolean_T RelationalOperator1_o;     /* '<S4>/Relational Operator1' */
} DW_ornek_8_1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S3>/Multiport Switch' */
  const real_T MultiportSwitch_j[2];   /* '<S6>/Multiport Switch' */
} ConstB_ornek_8_1_T;

/* Block signals and states (default storage) */
extern DW_ornek_8_1_T ornek_8_1_DW;
extern const ConstB_ornek_8_1_T ornek_8_1_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void ornek_8_1_initialize(void);
extern void ornek_8_1_step(void);
extern void ornek_8_1_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) ;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ornek_8_1'
 * '<S1>'   : 'ornek_8_1/Edge Detector'
 * '<S2>'   : 'ornek_8_1/Edge Detector1'
 * '<S3>'   : 'ornek_8_1/Edge Detector/Model'
 * '<S4>'   : 'ornek_8_1/Edge Detector/Model/NEGATIVE Edge'
 * '<S5>'   : 'ornek_8_1/Edge Detector/Model/POSITIVE Edge'
 * '<S6>'   : 'ornek_8_1/Edge Detector1/Model'
 * '<S7>'   : 'ornek_8_1/Edge Detector1/Model/NEGATIVE Edge'
 * '<S8>'   : 'ornek_8_1/Edge Detector1/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_ornek_8_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
