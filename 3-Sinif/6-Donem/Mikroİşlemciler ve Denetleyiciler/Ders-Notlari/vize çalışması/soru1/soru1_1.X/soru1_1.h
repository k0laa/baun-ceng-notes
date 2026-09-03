/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru1_1.h
 *
 * Code generated for Simulink model 'soru1_1'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Sep  3 19:48:14 2026
 */

#ifndef RTW_HEADER_soru1_1_h_
#define RTW_HEADER_soru1_1_h_
#ifndef soru1_1_COMMON_INCLUDES_
#define soru1_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru1_1_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru1_1_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  uint32_T Counter_ClkEphState;        /* '<Root>/Counter' */
  uint32_T Counter_RstEphState;        /* '<Root>/Counter' */
  struct {
    uint_T Compare:1;                  /* '<S2>/Compare' */
    uint_T RelationalOperator1:1;      /* '<S8>/Relational Operator1' */
    uint_T RelationalOperator1_o:1;    /* '<S7>/Relational Operator1' */
    uint_T UnitDelay_DSTATE:1;         /* '<S6>/Unit Delay' */
    uint_T Memory_PreviousInput_c:1;   /* '<S5>/Memory' */
  } bitsForTID0;

  uint8_T Counter_Count;               /* '<Root>/Counter' */
} DW_soru1_1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S6>/Multiport Switch' */
} ConstB_soru1_1_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S5>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP_soru1_1_T;

/* Block signals and states (default storage) */
extern DW_soru1_1_T soru1_1_DW;
extern const ConstB_soru1_1_T soru1_1_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_soru1_1_T soru1_1_ConstP;

/* Model entry point functions */
extern void soru1_1_initialize(void);
extern void soru1_1_step(void);
extern void soru1_1_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
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
 * '<Root>' : 'soru1_1'
 * '<S1>'   : 'soru1_1/Compare To Constant'
 * '<S2>'   : 'soru1_1/Compare To Constant1'
 * '<S3>'   : 'soru1_1/Digital Output'
 * '<S4>'   : 'soru1_1/Edge Detector1'
 * '<S5>'   : 'soru1_1/S-R Flip-Flop'
 * '<S6>'   : 'soru1_1/Edge Detector1/Model'
 * '<S7>'   : 'soru1_1/Edge Detector1/Model/NEGATIVE Edge'
 * '<S8>'   : 'soru1_1/Edge Detector1/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_soru1_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
