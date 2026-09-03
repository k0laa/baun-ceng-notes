/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_11_3.h
 *
 * Code generated for Simulink model 'ornek_11_3'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 00:41:30 2026
 */

#ifndef RTW_HEADER_ornek_11_3_h_
#define RTW_HEADER_ornek_11_3_h_
#ifndef ornek_11_3_COMMON_INCLUDES_
#define ornek_11_3_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek_11_3_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "ornek_11_3_types.h"
#include "rt_nonfinite.h"

/* user code (top of header file) */
#include "dsPIC_lcd.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  uint16_T RateTransition1;            /* '<Root>/Rate Transition1' */
  volatile uint16_T RateTransition1_Buffer0;/* '<Root>/Rate Transition1' */
  struct {
    uint_T RelationalOperator1:1;      /* '<S6>/Relational Operator1' */
    uint_T RelationalOperator1_m:1;    /* '<S5>/Relational Operator1' */
    uint_T UnitDelay_DSTATE:1;         /* '<S4>/Unit Delay' */
  } bitsForTID0;
} DW_ornek_11_3_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S4>/Multiport Switch' */
} ConstB_ornek_11_3_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [1 2 3 0 4 5 6 0 7 8 9 0 0 0 0 0].'
   * Referenced by: '<Root>/Constant1'
   */
  real_T Constant1_Value[16];
} ConstP_ornek_11_3_T;

/* Real-time Model Data Structure */
struct tag_RTM_ornek_11_3_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_ornek_11_3_T ornek_11_3_DW;
extern const ConstB_ornek_11_3_T ornek_11_3_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_ornek_11_3_T ornek_11_3_ConstP;

/* Model entry point functions */
extern void ornek_11_3_initialize(void);
extern void ornek_11_3_step(void);
extern void ornek_11_3_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) ;

/* Real-time Model object */
extern RT_MODEL_ornek_11_3_T *const ornek_11_3_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ornek_11_3'
 * '<S1>'   : 'ornek_11_3/Digital Output'
 * '<S2>'   : 'ornek_11_3/Edge Detector'
 * '<S3>'   : 'ornek_11_3/Function-Call Subsystem'
 * '<S4>'   : 'ornek_11_3/Edge Detector/Model'
 * '<S5>'   : 'ornek_11_3/Edge Detector/Model/NEGATIVE Edge'
 * '<S6>'   : 'ornek_11_3/Edge Detector/Model/POSITIVE Edge'
 */
#endif                                 /* RTW_HEADER_ornek_11_3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
