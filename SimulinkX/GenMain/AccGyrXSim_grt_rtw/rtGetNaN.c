/*
 * rtGetNaN.c
 *
 * Code generation for model "AccGyrXSim".
 *
 * Model version              : 1.69
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Tue Feb 17 11:40:39 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"

/* Return rtNaN needed by the generated code. */
real_T rtGetNaN(void)
{
  return rtNaN;
}

/* Return rtNaNF needed by the generated code. */
real32_T rtGetNaNF(void)
{
  return rtNaNF;
}
