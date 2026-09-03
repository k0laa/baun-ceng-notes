/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru5.h
 *
 * Code generated for Simulink model 'soru5'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Apr  9 12:44:43 2026
 */

#ifndef RTW_HEADER_soru5_h_
#define RTW_HEADER_soru5_h_
#ifndef soru5_COMMON_INCLUDES_
#define soru5_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru5_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru5_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  real_T Memory2_PreviousInput;        /* '<Root>/Memory2' */
  struct {
    uint_T Memory1_PreviousInput:1;    /* '<Root>/Memory1' */
    uint_T Memory3_PreviousInput:1;    /* '<Root>/Memory3' */
  } bitsForTID0;
} DW_soru5_T;

/* Block signals and states (default storage) */
extern DW_soru5_T soru5_DW;

/* Model entry point functions */
extern void soru5_initialize(void);
extern void soru5_step(void);
extern void soru5_terminate(void);

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
 * '<Root>' : 'soru5'
 * '<S1>'   : 'soru5/Digital Output'
 */
#endif                                 /* RTW_HEADER_soru5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
