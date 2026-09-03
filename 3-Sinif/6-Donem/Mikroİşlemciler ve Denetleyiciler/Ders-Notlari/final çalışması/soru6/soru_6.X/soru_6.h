/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_6.h
 *
 * Code generated for Simulink model 'soru_6'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 00:51:59 2026
 */

#ifndef RTW_HEADER_soru_6_h_
#define RTW_HEADER_soru_6_h_
#ifndef soru_6_COMMON_INCLUDES_
#define soru_6_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_6_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_6_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  uint16_T ADC;                        /* '<Root>/ADC' */
  uint16_T Gain2;                      /* '<Root>/Gain2' */
  struct {
    uint_T RelationalOperator1:1;      /* '<S13>/Relational Operator1' */
    uint_T RelationalOperator1_f:1;    /* '<S12>/Relational Operator1' */
    uint_T UnitDelay_DSTATE:1;         /* '<S11>/Unit Delay' */
    uint_T Memory_PreviousInput_f:1;   /* '<S10>/Memory' */
  } bitsForTID0;
} DW_soru_6_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S11>/Multiport Switch' */
} ConstB_soru_6_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S10>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP_soru_6_T;

/* Block signals and states (default storage) */
extern DW_soru_6_T soru_6_DW;
extern const ConstB_soru_6_T soru_6_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_soru_6_T soru_6_ConstP;

/* Model entry point functions */
extern void soru_6_initialize(void);
extern void soru_6_step(void);
extern void soru_6_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'soru_6'
 * '<S1>'   : 'soru_6/Compare To Constant1'
 * '<S2>'   : 'soru_6/Compare To Constant2'
 * '<S3>'   : 'soru_6/Compare To Constant3'
 * '<S4>'   : 'soru_6/Compare To Constant4'
 * '<S5>'   : 'soru_6/Compare To Constant5'
 * '<S6>'   : 'soru_6/Compare To Constant6'
 * '<S7>'   : 'soru_6/Compare To Constant7'
 * '<S8>'   : 'soru_6/Digital Output'
 * '<S9>'   : 'soru_6/Edge Detector'
 * '<S10>'  : 'soru_6/S-R Flip-Flop'
 * '<S11>'  : 'soru_6/Edge Detector/Model'
 * '<S12>'  : 'soru_6/Edge Detector/Model/NEGATIVE Edge'
 * '<S13>'  : 'soru_6/Edge Detector/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_soru_6_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
