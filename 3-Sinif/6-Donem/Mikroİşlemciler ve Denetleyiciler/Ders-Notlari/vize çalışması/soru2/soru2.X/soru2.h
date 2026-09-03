/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru2.h
 *
 * Code generated for Simulink model 'soru2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Apr  4 20:40:17 2026
 */

#ifndef RTW_HEADER_soru2_h_
#define RTW_HEADER_soru2_h_
#ifndef soru2_COMMON_INCLUDES_
#define soru2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru2_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru2_types.h"
#include "zero_crossing_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  struct {
    uint_T TmpLatchAtJKFlipFlopInport1_PreviousInput:1;/* synthesized block */
    uint_T TmpLatchAtJKFlipFlopInport2_PreviousInput:1;/* synthesized block */
    uint_T Memory_PreviousInput:1;     /* '<S3>/Memory' */
  } bitsForTID0;

  boolean_T Logic[2];                  /* '<S3>/Logic' */
} DW_soru2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState JKFlipFlop_Trig_ZCE;      /* '<S2>/J-K Flip-Flop' */
} PrevZCX_soru2_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S3>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP_soru2_T;

/* Block signals and states (default storage) */
extern DW_soru2_T soru2_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_soru2_T soru2_PrevZCX;

/* Constant parameters (default storage) */
extern const ConstP_soru2_T soru2_ConstP;

/* Model entry point functions */
extern void soru2_initialize(void);
extern void soru2_step(void);
extern void soru2_terminate(void);

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
 * '<Root>' : 'soru2'
 * '<S1>'   : 'soru2/Digital Output'
 * '<S2>'   : 'soru2/J-K Flip-Flop'
 * '<S3>'   : 'soru2/J-K Flip-Flop/J-K Flip-Flop'
 */
#endif                                 /* RTW_HEADER_soru2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
