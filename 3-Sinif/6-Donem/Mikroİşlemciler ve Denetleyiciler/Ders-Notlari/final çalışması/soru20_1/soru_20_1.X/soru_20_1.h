/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_20_1.h
 *
 * Code generated for Simulink model 'soru_20_1'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Jun 23 22:12:54 2026
 */

#ifndef RTW_HEADER_soru_20_1_h_
#define RTW_HEADER_soru_20_1_h_
#ifndef soru_20_1_COMMON_INCLUDES_
#define soru_20_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* soru_20_1_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "soru_20_1_types.h"
#include "rtGetNaN.h"
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
  real_T TmpRTBAtRelationalOperatorInport2;/* '<Root>/Mod1' */
  real_T TmpRTBAtSwitch1Inport2;       /* '<Root>/Decrement Stored Integer' */
  real_T TmpRTBAtRelationalOperatorInport2_Buffer0;/* synthesized block */
  real_T TmpRTBAtSwitch1Inport2_Buffer0;/* synthesized block */
  int16_T DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  int16_T TmpRTBAtCFunctionCall1Inport1;/* '<Root>/Data Type Conversion' */
  int16_T TmpRTBAtCFunctionCall1Inport2;/* '<Root>/Data Type Conversion1' */
  int16_T TmpRTBAtCFunctionCall1Inport1_Buffer0;/* synthesized block */
  int16_T TmpRTBAtCFunctionCall1Inport2_Buffer0;/* synthesized block */
  uint8_T BUSI2CMASTER;                /* '<Root>/BUS I2C MASTER' */
  uint8_T DataTypeConversion3;         /* '<Root>/Data Type Conversion3' */
  uint8_T Output_DSTATE;               /* '<S11>/Output' */
  uint8_T Output_DSTATE_o;             /* '<S8>/Output' */
  uint8_T Output_DSTATE_f;             /* '<S5>/Output' */
} DW_soru_20_1_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: OutValues
   * Referenced by: '<S2>/Vector'
   */
  real_T Vector_Value[2];

  /* Expression: OutValues
   * Referenced by: '<S3>/Vector'
   */
  real_T Vector_Value_k[64];

  /* Expression: OutValues
   * Referenced by: '<S4>/Vector'
   */
  real_T Vector_Value_h[8];
} ConstP_soru_20_1_T;

/* Real-time Model Data Structure */
struct tag_RTM_soru_20_1_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[5];
      uint32_T cLimit[5];
    } TaskCounters;

    struct {
      uint32_T TID1_2;
      uint32_T TID1_3;
      uint32_T TID2_3;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_soru_20_1_T soru_20_1_DW;

/* Constant parameters (default storage) */
extern const ConstP_soru_20_1_T soru_20_1_ConstP;

/* Model entry point functions */
extern void soru_20_1_initialize(void);
extern void soru_20_1_step0(void);
extern void soru_20_1_step1(void);
extern void soru_20_1_step2(void);
extern void soru_20_1_step3(void);
extern void soru_20_1_step4(void);
extern void soru_20_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_soru_20_1_T *const soru_20_1_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/FixPt Gateway In' : Eliminate redundant data type conversion
 * Block '<S2>/Out' : Eliminate redundant signal conversion block
 * Block '<S3>/Out' : Eliminate redundant signal conversion block
 * Block '<S4>/Out' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'soru_20_1'
 * '<S1>'   : 'soru_20_1/Decrement Stored Integer'
 * '<S2>'   : 'soru_20_1/Repeating Sequence Stair'
 * '<S3>'   : 'soru_20_1/Repeating Sequence Stair1'
 * '<S4>'   : 'soru_20_1/Repeating Sequence Stair2'
 * '<S5>'   : 'soru_20_1/Repeating Sequence Stair/LimitedCounter'
 * '<S6>'   : 'soru_20_1/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S7>'   : 'soru_20_1/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S8>'   : 'soru_20_1/Repeating Sequence Stair1/LimitedCounter'
 * '<S9>'   : 'soru_20_1/Repeating Sequence Stair1/LimitedCounter/Increment Real World'
 * '<S10>'  : 'soru_20_1/Repeating Sequence Stair1/LimitedCounter/Wrap To Zero'
 * '<S11>'  : 'soru_20_1/Repeating Sequence Stair2/LimitedCounter'
 * '<S12>'  : 'soru_20_1/Repeating Sequence Stair2/LimitedCounter/Increment Real World'
 * '<S13>'  : 'soru_20_1/Repeating Sequence Stair2/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_soru_20_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
