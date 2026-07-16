/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_5_9.h
 *
 * Code generated for Simulink model 'ornek_5_9'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jul 16 20:29:58 2026
 */

#ifndef RTW_HEADER_ornek_5_9_h_
#define RTW_HEADER_ornek_5_9_h_
#ifndef ornek_5_9_COMMON_INCLUDES_
#define ornek_5_9_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_5_9_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_5_9_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  struct {
    uint_T Memory_PreviousInput:1;     /* '<S2>/Memory' */
    uint_T Memory_PreviousInput_g:1;   /* '<S3>/Memory' */
  } bitsForTID0;
} DW_ornek_5_9_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S2>/Logic'
   *   '<S3>/Logic'
   */
  boolean_T pooled2[16];
} ConstP_ornek_5_9_T;

/* Block signals and states (default storage) */
extern DW_ornek_5_9_T ornek_5_9_DW;

/* Constant parameters (default storage) */
extern const ConstP_ornek_5_9_T ornek_5_9_ConstP;

/* Model entry point functions */
extern void ornek_5_9_initialize(void);
extern void ornek_5_9_step(void);
extern void ornek_5_9_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

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
 * '<Root>' : 'ornek_5_9'
 * '<S1>'   : 'ornek_5_9/Digital Output'
 * '<S2>'   : 'ornek_5_9/S-R Flip-Flop'
 * '<S3>'   : 'ornek_5_9/S-R Flip-Flop1'
 */
#endif                                 /* RTW_HEADER_ornek_5_9_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
