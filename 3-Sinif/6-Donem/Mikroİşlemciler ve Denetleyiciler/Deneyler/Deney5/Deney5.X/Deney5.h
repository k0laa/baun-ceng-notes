/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Deney5.h
 *
 * Code generated for Simulink model 'Deney5'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jun 10 13:52:05 2026
 */

#ifndef RTW_HEADER_Deney5_h_
#define RTW_HEADER_Deney5_h_
#ifndef Deney5_COMMON_INCLUDES_
#define Deney5_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Deney5_COMMON_INCLUDES_ */

#define FCY                            (1000000UL)               /* Instruction Frequency FCY set at  1.0 MHz */

/* Include for pic 30F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "Deney5_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint32_T Counter_ClkEphState;        /* '<Root>/Counter' */
  uint8_T Counter_Count;               /* '<Root>/Counter' */
} DW_Deney5_T;

/* Block signals and states (default storage) */
extern DW_Deney5_T Deney5_DW;

/* Model entry point functions */
extern void Deney5_initialize(void);
extern void Deney5_step(void);
extern void Deney5_terminate(void);

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
 * '<Root>' : 'Deney5'
 * '<S1>'   : 'Deney5/Digital Output'
 */
#endif                                 /* RTW_HEADER_Deney5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
