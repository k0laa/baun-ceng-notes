/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_5.h
 *
 * Code generated for Simulink model 'ornek_13_5'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 15:34:46 2026
 */

#ifndef RTW_HEADER_ornek_13_5_h_
#define RTW_HEADER_ornek_13_5_h_
#ifndef ornek_13_5_COMMON_INCLUDES_
#define ornek_13_5_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_13_5_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_13_5_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  uint32_T Counter_ClkEphState;        /* '<Root>/Counter' */
  uint32_T Counter_RstEphState;        /* '<Root>/Counter' */
  struct {
    uint_T Memory2:1;                  /* '<Root>/Memory2' */
    uint_T UnitDelay_DSTATE:1;         /* '<S7>/Unit Delay' */
    uint_T UnitDelay_DSTATE_n:1;       /* '<S10>/Unit Delay' */
    uint_T Memory2_PreviousInput:1;    /* '<Root>/Memory2' */
    uint_T Memory1_PreviousInput:1;    /* '<Root>/Memory1' */
    uint_T Memory_PreviousInput_a:1;   /* '<S6>/Memory' */
  } bitsForTID0;

  uint8_T Counter_Count;               /* '<Root>/Counter' */
  boolean_T RelationalOperator1;       /* '<S12>/Relational Operator1' */
  boolean_T RelationalOperator1_p;     /* '<S11>/Relational Operator1' */
  boolean_T RelationalOperator1_k;     /* '<S9>/Relational Operator1' */
  boolean_T RelationalOperator1_a;     /* '<S8>/Relational Operator1' */
} DW_ornek_13_5_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S7>/Multiport Switch' */
  const real_T MultiportSwitch_a[2];   /* '<S10>/Multiport Switch' */
} ConstB_ornek_13_5_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S6>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP_ornek_13_5_T;

/* Block signals and states (default storage) */
extern DW_ornek_13_5_T ornek_13_5_DW;
extern const ConstB_ornek_13_5_T ornek_13_5_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_ornek_13_5_T ornek_13_5_ConstP;

/* Model entry point functions */
extern void ornek_13_5_initialize(void);
extern void ornek_13_5_step(void);
extern void ornek_13_5_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ornek_13_5'
 * '<S1>'   : 'ornek_13_5/Compare To Constant'
 * '<S2>'   : 'ornek_13_5/Compare To Constant1'
 * '<S3>'   : 'ornek_13_5/Digital Output'
 * '<S4>'   : 'ornek_13_5/Edge Detector'
 * '<S5>'   : 'ornek_13_5/Edge Detector1'
 * '<S6>'   : 'ornek_13_5/S-R Flip-Flop'
 * '<S7>'   : 'ornek_13_5/Edge Detector/Model'
 * '<S8>'   : 'ornek_13_5/Edge Detector/Model/NEGATIVE Edge'
 * '<S9>'   : 'ornek_13_5/Edge Detector/Model/POSITIVE Edge'
 * '<S10>'  : 'ornek_13_5/Edge Detector1/Model'
 * '<S11>'  : 'ornek_13_5/Edge Detector1/Model/NEGATIVE Edge'
 * '<S12>'  : 'ornek_13_5/Edge Detector1/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_ornek_13_5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
