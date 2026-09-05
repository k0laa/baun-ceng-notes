/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_7.h
 *
 * Code generated for Simulink model 'ornek_13_7'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 16:29:46 2026
 */

#ifndef RTW_HEADER_ornek_13_7_h_
#define RTW_HEADER_ornek_13_7_h_
#ifndef ornek_13_7_COMMON_INCLUDES_
#define ornek_13_7_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_13_7_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_13_7_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint16_T ADC;                        /* '<Root>/ADC' */
  uint16_T Gain1;                      /* '<Root>/Gain1' */
} DW_ornek_13_7_T;

/* Block signals and states (default storage) */
extern DW_ornek_13_7_T ornek_13_7_DW;

/* Model entry point functions */
extern void ornek_13_7_initialize(void);
extern void ornek_13_7_step(void);
extern void ornek_13_7_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) ;

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
 * '<Root>' : 'ornek_13_7'
 */
#endif                                 /* RTW_HEADER_ornek_13_7_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
