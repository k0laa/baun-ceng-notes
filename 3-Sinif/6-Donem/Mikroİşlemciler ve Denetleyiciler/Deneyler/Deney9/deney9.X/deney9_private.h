/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney9_private.h
 *
 * Code generated for Simulink model 'deney9'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jun  3 14:34:43 2026
 */

#ifndef RTW_HEADER_deney9_private_h_
#define RTW_HEADER_deney9_private_h_
#include "rtwtypes.h"
#include "deney9_types.h"
#include "deney9.h"

extern uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta);
extern void deney9_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T
  *rty_OUT);
extern void deney9_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T
  *rty_OUT);

#endif                                 /* RTW_HEADER_deney9_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
