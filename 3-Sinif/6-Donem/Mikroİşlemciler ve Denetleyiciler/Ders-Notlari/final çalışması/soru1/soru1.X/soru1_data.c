/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru1_data.c
 *
 * Code generated for Simulink model 'soru1'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Jun 14 23:35:26 2026
 */

#include "soru1.h"

/* Invariant block signals (default storage) */
const ConstB_soru1_T soru1_ConstB = {
  { 1.0, 0.0 }                         /* '<S6>/Multiport Switch' */
};

/* Constant parameters (default storage) */
const ConstP_soru1_T soru1_ConstP = {
  /* Expression: [0.45 0.65 0.85 0.05 0.25].'
   * Referenced by: '<Root>/Constant'
   */
  { 0.45, 0.65, 0.85, 0.05, 0.25 },

  /* Computed Parameter: Logic_table
   * Referenced by: '<S9>/Logic'
   */
  { false, false, true, true, true, false, true, false, true, true, false, false, false, true, false, true },

  /* Computed Parameter: Logic_table_n
   * Referenced by: '<S5>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true, false, false, false, false }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
