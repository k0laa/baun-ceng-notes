/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_12.h
 *
 * Code generated for Simulink model 'ornek_13_12'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 18:38:51 2026
 */

#ifndef RTW_HEADER_ornek_13_12_h_
#define RTW_HEADER_ornek_13_12_h_
#ifndef ornek_13_12_COMMON_INCLUDES_
#define ornek_13_12_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_13_12_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_13_12_types.h"

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
  volatile real_T RateTransition2_Buffer[2];/* '<Root>/Rate Transition2' */
  volatile real_T RateTransition3_Buffer[2];/* '<Root>/Rate Transition3' */
  real_T RateTransition2;              /* '<Root>/Rate Transition2' */
  real_T RateTransition3;              /* '<Root>/Rate Transition3' */
  volatile uint16_T RateTransition_Buffer0[2];/* '<Root>/Rate Transition' */
  uint16_T ADC_o1;                     /* '<Root>/ADC' */
  uint16_T ADC_o2;                     /* '<Root>/ADC' */
  volatile int8_T RateTransition_semaphoreTaken;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition2_ActiveBufIdx;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition3_ActiveBufIdx;/* '<Root>/Rate Transition3' */
} DW_ornek_13_12_T;

/* Real-time Model Data Structure */
struct tag_RTM_ornek_13_12_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
      uint16_T cLimit[3];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_ornek_13_12_T ornek_13_12_DW;

/* Model entry point functions */
extern void ornek_13_12_initialize(void);
extern void ornek_13_12_step0(void);
extern void ornek_13_12_step1(void);
extern void ornek_13_12_step2(void);
extern void ornek_13_12_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ornek_13_12_T *const ornek_13_12_M;

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
 * '<Root>' : 'ornek_13_12'
 * '<S1>'   : 'ornek_13_12/Digital Output'
 * '<S2>'   : 'ornek_13_12/Function-Call Subsystem'
 * '<S3>'   : 'ornek_13_12/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_ornek_13_12_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
