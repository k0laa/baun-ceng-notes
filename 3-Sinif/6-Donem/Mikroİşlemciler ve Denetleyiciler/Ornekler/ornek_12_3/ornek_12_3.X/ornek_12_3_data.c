/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_12_3_data.c
 *
 * Code generated for Simulink model 'ornek_12_3'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Sep  4 14:51:32 2026
 */

#include "ornek_12_3.h"

/* Invariant block signals (default storage) */
const ConstB_ornek_12_3_T ornek_12_3_ConstB = {
  { 1.0, 0.0 },                        /* '<S7>/Multiport Switch' */

  { 1.0, 0.0 }                         /* '<S10>/Multiport Switch' */
};

/* Constant parameters (default storage) */
const ConstP_ornek_12_3_T ornek_12_3_ConstP = {
  /* Expression: [0 1 3 2 6 4 12 8 9].'
   * Referenced by: '<Root>/Constant5'
   */
  { 0.0, 1.0, 3.0, 2.0, 6.0, 4.0, 12.0, 8.0, 9.0 },

  /* Computed Parameter: Logic_table
   * Referenced by: '<S6>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true, false, false, false, false }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
