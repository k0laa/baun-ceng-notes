/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_13.h
 *
 * Code generated for Simulink model 'soru_13'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 13:14:38 2026
 */

#ifndef RTW_HEADER_soru_13_h_
#define RTW_HEADER_soru_13_h_
#ifndef soru_13_COMMON_INCLUDES_
#define soru_13_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_13_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_13_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint8_T Output_DSTATE;               /* '<S3>/Output' */
} DW_soru_13_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: OutValues
   * Referenced by: '<S2>/Vector'
   */
  real_T Vector_Value[16];
} ConstP_soru_13_T;

/* Real-time Model Data Structure */
struct tag_RTM_soru_13_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
      uint8_T cLimit[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_soru_13_T soru_13_DW;

/* Constant parameters (default storage) */
extern const ConstP_soru_13_T soru_13_ConstP;

/* Model entry point functions */
extern void soru_13_initialize(void);
extern void soru_13_step0(void);
extern void soru_13_step1(void);
extern void soru_13_terminate(void);

/* Real-time Model object */
extern RT_MODEL_soru_13_T *const soru_13_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S2>/Out' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'soru_13'
 * '<S1>'   : 'soru_13/Digital Output'
 * '<S2>'   : 'soru_13/Repeating Sequence Stair'
 * '<S3>'   : 'soru_13/Repeating Sequence Stair/LimitedCounter'
 * '<S4>'   : 'soru_13/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S5>'   : 'soru_13/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_soru_13_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
