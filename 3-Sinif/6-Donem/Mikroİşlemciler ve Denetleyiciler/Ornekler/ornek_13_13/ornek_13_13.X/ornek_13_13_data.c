/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek_13_13_data.c
 *
 * Code generated for Simulink model 'ornek_13_13'.
 *
 * Model version                  : 1.41
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Sep  5 19:27:35 2026
 */

#include "ornek_13_13.h"

/* Constant parameters (default storage) */
const ConstP_ornek_13_13_T ornek_13_13_ConstP = {
  /* Expression: resim
   * Referenced by: '<Root>/Constant2'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    64U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 16U, 16U, 32U, 40U, 56U, 24U, 8U, 104U, 96U, 112U, 240U, 240U, 240U, 240U,
    240U, 248U, 248U, 248U, 248U, 248U, 240U, 16U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 32U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 128U, 192U, 200U, 192U, 224U, 224U, 224U, 224U,
    128U, 128U, 0U, 128U, 128U, 0U, 0U, 0U, 0U, 32U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 160U, 184U, 252U, 252U, 252U, 252U, 252U, 252U,
    252U, 252U, 252U, 248U, 248U, 248U, 248U, 252U, 252U, 252U, 249U, 249U, 249U, 247U, 246U, 254U, 254U, 240U,
    240U, 112U, 60U, 56U, 18U, 14U, 6U, 134U, 36U, 124U, 16U, 0U, 0U, 0U, 1U, 255U, 255U, 255U, 63U, 63U, 31U,
    15U, 15U, 69U, 65U, 96U, 0U, 0U, 0U, 0U, 0U, 0U, 128U, 192U, 240U, 120U, 24U, 252U, 248U, 248U, 216U, 208U,
    240U, 240U, 240U, 250U, 248U, 248U, 248U, 248U, 254U, 254U, 254U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 254U, 255U, 254U, 255U, 255U, 255U, 255U, 255U, 254U,
    254U, 254U, 126U, 124U, 124U, 252U, 252U, 254U, 124U, 124U, 60U, 8U, 24U, 16U, 16U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 1U, 3U, 3U, 7U, 3U, 1U, 1U, 0U, 1U, 1U, 1U, 1U, 3U, 15U, 63U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 255U, 252U, 252U, 248U, 224U, 248U, 255U, 255U, 255U, 190U, 30U, 24U,
    64U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 8U, 6U, 88U, 224U, 240U, 249U, 249U, 251U,
    248U, 252U, 255U, 255U, 127U, 127U, 127U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 249U, 120U, 0U, 0U, 0U, 0U, 0U, 14U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 12U, 31U, 127U, 255U,
    255U, 255U, 255U, 255U, 255U, 127U, 127U, 127U, 63U, 127U, 255U, 31U, 15U, 3U, 3U, 1U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 128U, 192U, 247U, 255U, 247U, 249U, 248U, 248U, 248U, 225U,
    224U, 225U, 227U, 225U, 230U, 230U, 230U, 126U, 255U, 255U, 255U, 255U, 191U, 191U, 255U, 127U, 127U, 127U,
    127U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 125U,
    113U, 3U, 4U, 0U, 8U, 0U, 4U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 1U, 3U, 15U,
    15U, 15U, 16U, 16U, 24U, 32U, 0U, 0U, 128U, 192U, 192U, 192U, 192U, 192U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 10U, 31U, 63U, 127U, 127U, 127U, 127U, 63U, 127U, 127U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 252U, 249U, 255U, 103U, 55U, 7U, 3U, 1U, 0U, 0U, 0U, 0U, 0U, 3U, 15U, 31U,
    1U, 0U, 0U, 0U, 1U, 3U, 71U, 135U, 142U, 12U, 0U, 128U, 192U, 224U, 0U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 28U, 127U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 254U, 252U, 252U, 252U, 56U, 24U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 3U, 127U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 127U, 63U, 0U, 0U, 224U,
    48U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U, 0U, 128U,
    192U, 192U, 224U, 240U, 240U, 248U, 248U, 240U, 225U, 251U, 241U, 226U, 192U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 128U, 253U, 255U, 255U, 255U, 127U, 63U, 31U, 15U, 3U, 1U,
    1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 3U, 15U, 15U, 15U, 7U,
    3U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 1U, 7U, 7U, 7U, 3U, 3U, 3U, 7U, 7U, 15U, 31U, 95U, 15U, 7U, 1U, 0U, 0U, 0U, 0U, 0U, 128U,
    64U, 32U, 16U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 13U, 31U, 7U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U, 0U, 0U, 0U
  }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
