/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Deney3.h
 *
 * Code generated for Simulink model 'Deney3'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Mar  4 20:11:42 2026
 */

#ifndef RTW_HEADER_Deney3_h_
#define RTW_HEADER_Deney3_h_
#ifndef Deney3_COMMON_INCLUDES_
#define Deney3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Deney3_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "Deney3_types.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Switch3;                      /* '<Root>/Switch3' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  struct {
    uint_T DataTypeConversion2:1;      /* '<S4>/Data Type Conversion2' */
    uint_T RelationalOperator1:1;      /* '<S7>/Relational Operator1' */
    uint_T RelationalOperator1_d:1;    /* '<S6>/Relational Operator1' */
  } bitsForTID0;

  struct {
    uint_T Memory_PreviousInput_j:1;   /* '<S4>/Memory' */
    uint_T Memory_PreviousInput_b:1;   /* '<S3>/Memory' */
  } bitsForTID1;

  boolean_T Logic[2];                  /* '<S3>/Logic' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
} DW_Deney3_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S5>/Triggered Subsystem' */
} PrevZCX_Deney3_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S4>/Multiport Switch' */
} ConstB_Deney3_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S3>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP_Deney3_T;

/* Real-time Model Data Structure */
struct tag_RTM_Deney3_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_Deney3_T Deney3_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Deney3_T Deney3_PrevZCX;
extern const ConstB_Deney3_T Deney3_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_Deney3_T Deney3_ConstP;

/* Model entry point functions */
extern void Deney3_initialize(void);
extern void Deney3_step(void);
extern void Deney3_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/* Real-time Model object */
extern RT_MODEL_Deney3_T *const Deney3_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S5>/Relational Operator' : Unused code path elimination
 * Block '<S5>/Sum' : Unused code path elimination
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
 * '<Root>' : 'Deney3'
 * '<S1>'   : 'Deney3/Digital Output'
 * '<S2>'   : 'Deney3/Edge Detector1'
 * '<S3>'   : 'Deney3/S-R Flip-Flop'
 * '<S4>'   : 'Deney3/Edge Detector1/Model'
 * '<S5>'   : 'Deney3/Edge Detector1/Model/Internal dirac generator'
 * '<S6>'   : 'Deney3/Edge Detector1/Model/NEGATIVE Edge'
 * '<S7>'   : 'Deney3/Edge Detector1/Model/POSITIVE Edge'
 * '<S8>'   : 'Deney3/Edge Detector1/Model/Internal dirac generator/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_Deney3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
