/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru_5_data.c
 *
 * Code generated for Simulink model 'soru_5'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Jun 19 23:45:56 2026
 */

#include "soru_5.h"

/* Invariant block signals (default storage) */
const ConstB_soru_5_T soru_5_ConstB = {
  { 1.0, 0.0 },                        /* '<S14>/Multiport Switch' */

  { 1.0, 0.0 }                         /* '<S17>/Multiport Switch' */
};

/* Constant parameters (default storage) */
const ConstP_soru_5_T soru_5_ConstP = {
  /* Expression: [0.05 0.055 0.065 0.08 0.1].'
   * Referenced by: '<Root>/Constant5'
   */
  { 0.05, 0.055, 0.065, 0.08, 0.1 },

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S12>/Logic'
   *   '<S13>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true, false, false, false, false }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
