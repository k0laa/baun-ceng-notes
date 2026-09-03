/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_19.h
 *
 * Code generated for Simulink model 'soru_19'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 22:48:52 2026
 */

#ifndef RTW_HEADER_soru_19_h_
#define RTW_HEADER_soru_19_h_
#ifndef soru_19_COMMON_INCLUDES_
#define soru_19_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_19_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_19_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  real_T Memory1_PreviousInput;        /* '<Root>/Memory1' */
  uint16_T ADC;                        /* '<Root>/ADC' */
  struct {
    uint_T RelationalOperator1:1;      /* '<S18>/Relational Operator1' */
    uint_T RelationalOperator1_f:1;    /* '<S17>/Relational Operator1' */
    uint_T UnitDelay_DSTATE:1;         /* '<S16>/Unit Delay' */
    uint_T Memory2_PreviousInput:1;    /* '<Root>/Memory2' */
    uint_T Memory_PreviousInput_b:1;   /* '<S15>/Memory' */
    uint_T Memory_PreviousInput_o:1;   /* '<S14>/Memory' */
    uint_T Memory_PreviousInput_p:1;   /* '<S13>/Memory' */
  } bitsForTID0;
} DW_soru_19_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S16>/Multiport Switch' */
} ConstB_soru_19_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 1 3 2 6 4 12 8 9].'
   * Referenced by: '<Root>/Constant5'
   */
  real_T Constant5_Value[9];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S13>/Logic'
   *   '<S14>/Logic'
   *   '<S15>/Logic'
   */
  boolean_T pooled7[16];
} ConstP_soru_19_T;

/* Block signals and states (default storage) */
extern DW_soru_19_T soru_19_DW;
extern const ConstB_soru_19_T soru_19_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_soru_19_T soru_19_ConstP;

/* Model entry point functions */
extern void soru_19_initialize(void);
extern void soru_19_step(void);
extern void soru_19_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S16>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S12>/FixPt Gateway In' : Eliminate redundant data type conversion
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
 * '<Root>' : 'soru_19'
 * '<S1>'   : 'soru_19/Compare To Constant'
 * '<S2>'   : 'soru_19/Compare To Constant1'
 * '<S3>'   : 'soru_19/Compare To Constant2'
 * '<S4>'   : 'soru_19/Compare To Constant3'
 * '<S5>'   : 'soru_19/Compare To Constant4'
 * '<S6>'   : 'soru_19/Compare To Constant5'
 * '<S7>'   : 'soru_19/Compare To Constant6'
 * '<S8>'   : 'soru_19/Digital Output'
 * '<S9>'   : 'soru_19/Digital Output1'
 * '<S10>'  : 'soru_19/Digital Output2'
 * '<S11>'  : 'soru_19/Edge Detector'
 * '<S12>'  : 'soru_19/Increment Stored Integer'
 * '<S13>'  : 'soru_19/S-R Flip-Flop'
 * '<S14>'  : 'soru_19/S-R Flip-Flop1'
 * '<S15>'  : 'soru_19/S-R Flip-Flop2'
 * '<S16>'  : 'soru_19/Edge Detector/Model'
 * '<S17>'  : 'soru_19/Edge Detector/Model/NEGATIVE Edge'
 * '<S18>'  : 'soru_19/Edge Detector/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_soru_19_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
