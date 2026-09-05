/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_6.h
 *
 * Code generated for Simulink model 'ornek_13_6'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 16:18:06 2026
 */

#ifndef RTW_HEADER_ornek_13_6_h_
#define RTW_HEADER_ornek_13_6_h_
#ifndef ornek_13_6_COMMON_INCLUDES_
#define ornek_13_6_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_13_6_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_13_6_types.h"

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
  uint16_T RateTransition;             /* '<Root>/Rate Transition' */
  uint16_T RateTransition1;            /* '<Root>/Rate Transition1' */
  volatile uint16_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  volatile uint16_T RateTransition1_Buffer0;/* '<Root>/Rate Transition1' */
  uint8_T BUSI2CMASTER_o1;             /* '<Root>/BUS I2C MASTER' */
  uint8_T BUSI2CMASTER_o2;             /* '<Root>/BUS I2C MASTER' */
} DW_ornek_13_6_T;

/* Real-time Model Data Structure */
struct tag_RTM_ornek_13_6_T {
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
extern DW_ornek_13_6_T ornek_13_6_DW;

/* Model entry point functions */
extern void ornek_13_6_initialize(void);
extern void ornek_13_6_step0(void);
extern void ornek_13_6_step1(void);
extern void ornek_13_6_step2(void);
extern void ornek_13_6_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ornek_13_6_T *const ornek_13_6_M;

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
 * '<Root>' : 'ornek_13_6'
 * '<S1>'   : 'ornek_13_6/Digital Output'
 * '<S2>'   : 'ornek_13_6/Function-Call Subsystem'
 */
#endif                                 /* RTW_HEADER_ornek_13_6_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
