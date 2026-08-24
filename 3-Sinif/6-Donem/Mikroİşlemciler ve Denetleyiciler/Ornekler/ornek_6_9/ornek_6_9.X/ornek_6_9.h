/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_9.h
 *
 * Code generated for Simulink model 'ornek_6_9'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Aug 24 21:06:49 2026
 */

#ifndef RTW_HEADER_ornek_6_9_h_
#define RTW_HEADER_ornek_6_9_h_
#ifndef ornek_6_9_COMMON_INCLUDES_
#define ornek_6_9_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_6_9_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_6_9_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint32_T Counter_ClkEphState;        /* '<Root>/Counter' */
  uint32_T Counter_RstEphState;        /* '<Root>/Counter' */
  uint8_T Counter_Count;               /* '<Root>/Counter' */
  boolean_T DigitalInput_o2;           /* '<Root>/Digital Input' */
} DW_ornek_6_9_T;

/* Block signals and states (default storage) */
extern DW_ornek_6_9_T ornek_6_9_DW;

/* Model entry point functions */
extern void ornek_6_9_initialize(void);
extern void ornek_6_9_step(void);
extern void ornek_6_9_terminate(void);

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
 * '<Root>' : 'ornek_6_9'
 * '<S1>'   : 'ornek_6_9/Digital Output'
 */
#endif                                 /* RTW_HEADER_ornek_6_9_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
