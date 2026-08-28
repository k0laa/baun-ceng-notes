/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_6_15.h
 *
 * Code generated for Simulink model 'ornek_6_15'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Aug 26 22:11:21 2026
 */

#ifndef RTW_HEADER_ornek_6_15_h_
#define RTW_HEADER_ornek_6_15_h_
#ifndef ornek_6_15_COMMON_INCLUDES_
#define ornek_6_15_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_6_15_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_6_15_types.h"
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
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  struct {
    uint_T Memory_PreviousInput_k:1;   /* '<S4>/Memory' */
  } bitsForTID0;

  boolean_T TmpRTBAtSwitch2Inport1;    /* '<Root>/Data Type Conversion' */
  boolean_T TmpRTBAtSwitch2Inport1_Buffer0;/* synthesized block */
} DW_ornek_6_15_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [63 6 91 79 102 109].'
   * Referenced by: '<Root>/Constant3'
   */
  real_T Constant3_Value[6];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S4>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP_ornek_6_15_T;

/* Real-time Model Data Structure */
struct tag_RTM_ornek_6_15_T {
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
extern DW_ornek_6_15_T ornek_6_15_DW;

/* Constant parameters (default storage) */
extern const ConstP_ornek_6_15_T ornek_6_15_ConstP;

/* Model entry point functions */
extern void ornek_6_15_initialize(void);
extern void ornek_6_15_step0(void);
extern void ornek_6_15_step1(void);
extern void ornek_6_15_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ornek_6_15_T *const ornek_6_15_M;

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
 * '<Root>' : 'ornek_6_15'
 * '<S1>'   : 'ornek_6_15/Clock'
 * '<S2>'   : 'ornek_6_15/Digital Output'
 * '<S3>'   : 'ornek_6_15/Digital Output1'
 * '<S4>'   : 'ornek_6_15/S-R Flip-Flop'
 */
#endif                                 /* RTW_HEADER_ornek_6_15_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
