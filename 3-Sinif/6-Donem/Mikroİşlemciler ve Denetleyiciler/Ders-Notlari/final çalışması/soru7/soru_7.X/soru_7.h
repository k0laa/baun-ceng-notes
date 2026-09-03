/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_7.h
 *
 * Code generated for Simulink model 'soru_7'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 01:35:47 2026
 */

#ifndef RTW_HEADER_soru_7_h_
#define RTW_HEADER_soru_7_h_
#ifndef soru_7_COMMON_INCLUDES_
#define soru_7_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_7_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_7_types.h"

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
  volatile real_T RateTransition_Buffer[2];/* '<Root>/Rate Transition' */
  real_T RateTransition;               /* '<Root>/Rate Transition' */
  uint16_T ADC;                        /* '<Root>/ADC' */
  volatile int8_T RateTransition_ActiveBufIdx;/* '<Root>/Rate Transition' */
} DW_soru_7_T;

/* Real-time Model Data Structure */
struct tag_RTM_soru_7_T {
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
extern DW_soru_7_T soru_7_DW;

/* Model entry point functions */
extern void soru_7_initialize(void);
extern void soru_7_step0(void);
extern void soru_7_step1(void);
extern void soru_7_terminate(void);

/* Real-time Model object */
extern RT_MODEL_soru_7_T *const soru_7_M;

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
 * '<Root>' : 'soru_7'
 * '<S1>'   : 'soru_7/Digital Output'
 * '<S2>'   : 'soru_7/Function-Call Subsystem'
 */
#endif                                 /* RTW_HEADER_soru_7_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
