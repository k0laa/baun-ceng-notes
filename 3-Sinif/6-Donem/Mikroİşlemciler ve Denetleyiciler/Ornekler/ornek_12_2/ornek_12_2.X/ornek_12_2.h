/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_12_2.h
 *
 * Code generated for Simulink model 'ornek_12_2'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 14:56:15 2026
 */

#ifndef RTW_HEADER_ornek_12_2_h_
#define RTW_HEADER_ornek_12_2_h_
#ifndef ornek_12_2_COMMON_INCLUDES_
#define ornek_12_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ornek_12_2_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_12_2_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  uint16_T Gain;                       /* '<Root>/Gain' */
  struct {
    uint_T UnitDelay_DSTATE:1;         /* '<S5>/Unit Delay' */
    uint_T UnitDelay_DSTATE_n:1;       /* '<S8>/Unit Delay' */
    uint_T Memory_PreviousInput_a:1;   /* '<S4>/Memory' */
  } bitsForTID0;

  boolean_T RelationalOperator1;       /* '<S10>/Relational Operator1' */
  boolean_T RelationalOperator1_a;     /* '<S9>/Relational Operator1' */
  boolean_T RelationalOperator1_n;     /* '<S7>/Relational Operator1' */
  boolean_T RelationalOperator1_p;     /* '<S6>/Relational Operator1' */
} DW_ornek_12_2_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S5>/Multiport Switch' */
  const real_T MultiportSwitch_h[2];   /* '<S8>/Multiport Switch' */
} ConstB_ornek_12_2_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S4>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP_ornek_12_2_T;

/* Block signals and states (default storage) */
extern DW_ornek_12_2_T ornek_12_2_DW;
extern const ConstB_ornek_12_2_T ornek_12_2_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_ornek_12_2_T ornek_12_2_ConstP;

/* Model entry point functions */
extern void ornek_12_2_initialize(void);
extern void ornek_12_2_step(void);
extern void ornek_12_2_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) ;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ornek_12_2'
 * '<S1>'   : 'ornek_12_2/Digital Output'
 * '<S2>'   : 'ornek_12_2/Edge Detector'
 * '<S3>'   : 'ornek_12_2/Edge Detector1'
 * '<S4>'   : 'ornek_12_2/S-R Flip-Flop'
 * '<S5>'   : 'ornek_12_2/Edge Detector/Model'
 * '<S6>'   : 'ornek_12_2/Edge Detector/Model/NEGATIVE Edge'
 * '<S7>'   : 'ornek_12_2/Edge Detector/Model/POSITIVE Edge'
 * '<S8>'   : 'ornek_12_2/Edge Detector1/Model'
 * '<S9>'   : 'ornek_12_2/Edge Detector1/Model/NEGATIVE Edge'
 * '<S10>'  : 'ornek_12_2/Edge Detector1/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_ornek_12_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
