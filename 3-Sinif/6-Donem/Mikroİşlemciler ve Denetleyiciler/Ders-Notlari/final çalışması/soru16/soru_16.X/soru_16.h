/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_16.h
 *
 * Code generated for Simulink model 'soru_16'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jun 20 15:17:51 2026
 */

#ifndef RTW_HEADER_soru_16_h_
#define RTW_HEADER_soru_16_h_
#ifndef soru_16_COMMON_INCLUDES_
#define soru_16_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_16_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_16_types.h"
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
  volatile real_T RateTransition_Buffer[2];/* '<Root>/Rate Transition' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  uint16_T ADC;                        /* '<Root>/ADC' */
  uint16_T TmpRTBAtFunctionCallSubsystemInport1;/* '<Root>/Data Type Conversion' */
  volatile uint16_T TmpRTBAtFunctionCallSubsystemInport1_Buffer0;/* synthesized block */
  struct {
    uint_T Memory_PreviousInput_m:1;   /* '<S7>/Memory' */
    uint_T Memory_PreviousInput_md:1;  /* '<S8>/Memory' */
  } bitsForTID0;

  volatile int8_T RateTransition_ActiveBufIdx;/* '<Root>/Rate Transition' */
  boolean_T TmpRTBAtCompareOutport1;   /* '<S1>/Compare' */
  boolean_T TmpRTBAtANDInport2;        /* '<Root>/Compare To Constant1' */
  boolean_T TmpRTBAtCompareOutport1_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtANDInport2_Buffer0;/* synthesized block */
} DW_soru_16_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S7>/Logic'
   *   '<S8>/Logic'
   */
  boolean_T pooled5[16];
} ConstP_soru_16_T;

/* Real-time Model Data Structure */
struct tag_RTM_soru_16_T {
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

    struct {
      uint8_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_soru_16_T soru_16_DW;

/* Constant parameters (default storage) */
extern const ConstP_soru_16_T soru_16_ConstP;

/* Model entry point functions */
extern void soru_16_initialize(void);
extern void soru_16_step0(void);
extern void soru_16_step1(void);
extern void soru_16_terminate(void);

/* Real-time Model object */
extern RT_MODEL_soru_16_T *const soru_16_M;

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
 * '<Root>' : 'soru_16'
 * '<S1>'   : 'soru_16/Compare To Constant'
 * '<S2>'   : 'soru_16/Compare To Constant1'
 * '<S3>'   : 'soru_16/Compare To Constant2'
 * '<S4>'   : 'soru_16/Digital Output'
 * '<S5>'   : 'soru_16/Digital Output1'
 * '<S6>'   : 'soru_16/Function-Call Subsystem'
 * '<S7>'   : 'soru_16/S-R Flip-Flop'
 * '<S8>'   : 'soru_16/S-R Flip-Flop1'
 */
#endif                                 /* RTW_HEADER_soru_16_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
