/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: soru6_private.h
 *
 * Code generated for Simulink model 'soru6'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Sep  3 21:52:54 2026
 */

#ifndef RTW_HEADER_soru6_private_h_
#define RTW_HEADER_soru6_private_h_
#include "rtwtypes.h"
#include "soru6_types.h"
#include "soru6.h"

extern uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern void soru6_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T
  *rty_OUT);
extern void soru6_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T rtu_INprevious, boolean_T
  *rty_OUT);

#endif                                 /* RTW_HEADER_soru6_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
