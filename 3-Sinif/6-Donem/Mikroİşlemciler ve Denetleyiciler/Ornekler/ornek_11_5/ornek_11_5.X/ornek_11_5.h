/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_11_5.h
 *
 * Code generated for Simulink model 'ornek_11_5'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 01:22:14 2026
 */

#ifndef RTW_HEADER_ornek_11_5_h_
#define RTW_HEADER_ornek_11_5_h_
#ifndef ornek_11_5_COMMON_INCLUDES_
#define ornek_11_5_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_11_5_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_11_5_types.h"
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
  int16_T DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  int16_T TmpRTBAtCFunctionCall1Inport1;/* '<Root>/Data Type Conversion' */
  int16_T TmpRTBAtCFunctionCall1Inport2;/* '<Root>/Data Type Conversion1' */
  int16_T TmpRTBAtCFunctionCall1Inport1_Buffer0;/* synthesized block */
  int16_T TmpRTBAtCFunctionCall1Inport2_Buffer0;/* synthesized block */
  uint8_T IndexVector;                 /* '<Root>/Index Vector' */
  uint8_T Output_DSTATE;               /* '<S10>/Output' */
  uint8_T Output_DSTATE_e;             /* '<S4>/Output' */
  uint8_T Output_DSTATE_a;             /* '<S7>/Output' */
} DW_ornek_11_5_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: OutValues
   * Referenced by: '<S1>/Vector'
   */
  real_T Vector_Value[2];

  /* Expression: OutValues
   * Referenced by: '<S2>/Vector'
   */
  real_T Vector_Value_f[64];

  /* Expression: OutValues
   * Referenced by: '<S3>/Vector'
   */
  real_T Vector_Value_g[7];

  /* Expression: [0X01 0X03 0X07 0X0F 0X1F 0X3F 0X7F 0XFF].'
   * Referenced by: '<Root>/Constant'
   */
  uint8_T Constant_Value[8];
} ConstP_ornek_11_5_T;

/* Real-time Model Data Structure */
struct tag_RTM_ornek_11_5_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[4];
      uint16_T cLimit[4];
    } TaskCounters;

    struct {
      uint16_T TID0_1;
      uint16_T TID0_2;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_ornek_11_5_T ornek_11_5_DW;

/* Constant parameters (default storage) */
extern const ConstP_ornek_11_5_T ornek_11_5_ConstP;

/* Model entry point functions */
extern void ornek_11_5_initialize(void);
extern void ornek_11_5_step0(void);
extern void ornek_11_5_step1(void);
extern void ornek_11_5_step2(void);
extern void ornek_11_5_step3(void);
extern void ornek_11_5_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ornek_11_5_T *const ornek_11_5_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S1>/Out' : Eliminate redundant signal conversion block
 * Block '<S2>/Out' : Eliminate redundant signal conversion block
 * Block '<S3>/Out' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'ornek_11_5'
 * '<S1>'   : 'ornek_11_5/Repeating Sequence Stair'
 * '<S2>'   : 'ornek_11_5/Repeating Sequence Stair1'
 * '<S3>'   : 'ornek_11_5/Repeating Sequence Stair2'
 * '<S4>'   : 'ornek_11_5/Repeating Sequence Stair/LimitedCounter'
 * '<S5>'   : 'ornek_11_5/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S6>'   : 'ornek_11_5/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S7>'   : 'ornek_11_5/Repeating Sequence Stair1/LimitedCounter'
 * '<S8>'   : 'ornek_11_5/Repeating Sequence Stair1/LimitedCounter/Increment Real World'
 * '<S9>'   : 'ornek_11_5/Repeating Sequence Stair1/LimitedCounter/Wrap To Zero'
 * '<S10>'  : 'ornek_11_5/Repeating Sequence Stair2/LimitedCounter'
 * '<S11>'  : 'ornek_11_5/Repeating Sequence Stair2/LimitedCounter/Increment Real World'
 * '<S12>'  : 'ornek_11_5/Repeating Sequence Stair2/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_ornek_11_5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
