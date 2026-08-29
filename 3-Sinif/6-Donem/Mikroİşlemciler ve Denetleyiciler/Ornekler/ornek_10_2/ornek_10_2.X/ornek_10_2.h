/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_10_2.h
 *
 * Code generated for Simulink model 'ornek_10_2'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Aug 29 21:36:28 2026
 */

#ifndef RTW_HEADER_ornek_10_2_h_
#define RTW_HEADER_ornek_10_2_h_
#ifndef ornek_10_2_COMMON_INCLUDES_
#define ornek_10_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_10_2_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_10_2_types.h"

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
  uint8_T UARTRx;                      /* '<Root>/UART Rx' */
  uint8_T Switch;                      /* '<Root>/Switch' */
  uint8_T Output_DSTATE;               /* '<S1>/Output' */
} DW_ornek_10_2_T;

/* Real-time Model Data Structure */
struct tag_RTM_ornek_10_2_T {
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
extern DW_ornek_10_2_T ornek_10_2_DW;

/* Model entry point functions */
extern void ornek_10_2_initialize(void);
extern void ornek_10_2_step0(void);
extern void ornek_10_2_step1(void);
extern void ornek_10_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ornek_10_2_T *const ornek_10_2_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * '<Root>' : 'ornek_10_2'
 * '<S1>'   : 'ornek_10_2/Counter Free-Running'
 * '<S2>'   : 'ornek_10_2/Digital Output'
 * '<S3>'   : 'ornek_10_2/Counter Free-Running/Increment Real World'
 * '<S4>'   : 'ornek_10_2/Counter Free-Running/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_ornek_10_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
