/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_21.h
 *
 * Code generated for Simulink model 'ornek_6_21'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 09:45:40 2026
 */

#ifndef RTW_HEADER_ornek_6_21_h_
#define RTW_HEADER_ornek_6_21_h_
#ifndef ornek_6_21_COMMON_INCLUDES_
#define ornek_6_21_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_6_21_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_6_21_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T Memory_PreviousInput;       /* '<Root>/Memory' */
  uint8_T Output_DSTATE;               /* '<S7>/Output' */
} DW_ornek_6_21_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [3 117 118 117 3].'
   * Referenced by: '<Root>/Constant'
   */
  real_T Constant_Value[5];

  /* Expression: [0 54 54 54 73].'
   * Referenced by: '<Root>/Constant1'
   */
  real_T Constant1_Value[5];

  /* Expression: [65 62 62 62 93].'
   * Referenced by: '<Root>/Constant2'
   */
  real_T Constant2_Value[5];

  /* Expression: [1 2 4 8 16].'
   * Referenced by: '<Root>/Constant3'
   */
  real_T Constant3_Value[5];

  /* Expression: OutValues
   * Referenced by: '<S6>/Vector'
   */
  real_T Vector_Value[5];
} ConstP_ornek_6_21_T;

/* Block signals and states (default storage) */
extern DW_ornek_6_21_T ornek_6_21_DW;

/* Constant parameters (default storage) */
extern const ConstP_ornek_6_21_T ornek_6_21_ConstP;

/* Model entry point functions */
extern void ornek_6_21_initialize(void);
extern void ornek_6_21_step(void);
extern void ornek_6_21_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant4' : Unused code path elimination
 * Block '<Root>/Constant5' : Unused code path elimination
 * Block '<Root>/Constant6' : Unused code path elimination
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S6>/Out' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'ornek_6_21'
 * '<S1>'   : 'ornek_6_21/Compare To Constant'
 * '<S2>'   : 'ornek_6_21/Compare To Constant1'
 * '<S3>'   : 'ornek_6_21/Compare To Constant2'
 * '<S4>'   : 'ornek_6_21/Digital Output'
 * '<S5>'   : 'ornek_6_21/Digital Output1'
 * '<S6>'   : 'ornek_6_21/Repeating Sequence Stair1'
 * '<S7>'   : 'ornek_6_21/Repeating Sequence Stair1/LimitedCounter'
 * '<S8>'   : 'ornek_6_21/Repeating Sequence Stair1/LimitedCounter/Increment Real World'
 * '<S9>'   : 'ornek_6_21/Repeating Sequence Stair1/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_ornek_6_21_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
