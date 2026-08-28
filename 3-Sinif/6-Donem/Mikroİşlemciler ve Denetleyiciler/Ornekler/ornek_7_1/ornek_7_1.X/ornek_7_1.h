/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_7_1.h
 *
 * Code generated for Simulink model 'ornek_7_1'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug 28 10:11:19 2026
 */

#ifndef RTW_HEADER_ornek_7_1_h_
#define RTW_HEADER_ornek_7_1_h_
#ifndef ornek_7_1_COMMON_INCLUDES_
#define ornek_7_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_7_1_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_7_1_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T Memory_PreviousInput;       /* '<Root>/Memory' */
  uint16_T InputCapture_o1;            /* '<Root>/Input Capture' */
  uint16_T InputCapture_o2;            /* '<Root>/Input Capture' */
  uint16_T InputCapture_o3;            /* '<Root>/Input Capture' */
  uint16_T InputCapture_o4;            /* '<Root>/Input Capture' */
} DW_ornek_7_1_T;

/* Block signals and states (default storage) */
extern DW_ornek_7_1_T ornek_7_1_DW;

/* Model entry point functions */
extern void ornek_7_1_initialize(void);
extern void ornek_7_1_step(void);
extern void ornek_7_1_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S1>/FixPt Gateway In' : Eliminate redundant data type conversion
 * Block '<S3>/FixPt Gateway In' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ornek_7_1'
 * '<S1>'   : 'ornek_7_1/Decrement Stored Integer'
 * '<S2>'   : 'ornek_7_1/Digital Output'
 * '<S3>'   : 'ornek_7_1/Increment Stored Integer'
 */
#endif                                 /* RTW_HEADER_ornek_7_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
