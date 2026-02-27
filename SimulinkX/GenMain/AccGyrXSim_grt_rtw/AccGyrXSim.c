/*
 * AccGyrXSim.c
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

#include "AccGyrXSim.h"
#include "AccGyrXSim_types.h"
#include "rtwtypes.h"
#include <emmintrin.h>
#include <string.h>
#include <math.h>
#include "AccGyrXSim_private.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block states (default storage) */
DW_AccGyrXSim_T AccGyrXSim_DW;

/* External inputs (root inport signals with default storage) */
ExtU_AccGyrXSim_T AccGyrXSim_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_AccGyrXSim_T AccGyrXSim_Y;

/* Real-time model */
static RT_MODEL_AccGyrXSim_T AccGyrXSim_M_;
RT_MODEL_AccGyrXSim_T *const AccGyrXSim_M = &AccGyrXSim_M_;

/* Forward declaration for local functions */
static void AccGyrXSim_NED_ecompass(const real_T a[3], const real_T m[3], real_T
  R[9]);
static void AccGyrXSi_quaternion_quaternion(const real_T varargin_1[3], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d);
static void AccGyrXSim_imufilter_stepImpl(fusion_internal_simulink_imuf_T *obj,
  const real_T accelIn[3], const real_T gyroIn[3], real_T orientOut[4], real_T
  angvel[3]);
static void AccGyrXSim_NED_ecompass(const real_T a[3], const real_T m[3], real_T
  R[9])
{
  __m128d tmp;
  real_T x[9];
  real_T Reast[3];
  int32_T i2;
  int32_T xpageoffset;
  boolean_T b[9];
  boolean_T y[3];
  boolean_T exitg1;
  boolean_T nanPageIdx;

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  _mm_storeu_pd(&Reast[0], _mm_sub_pd(_mm_mul_pd(_mm_set_pd(m[0], a[1]),
    _mm_set_pd(a[2], m[2])), _mm_mul_pd(_mm_set_pd(a[0], m[1]), _mm_set_pd(m[2],
    a[2]))));
  Reast[2] = a[0] * m[1] - m[0] * a[1];
  R[6] = a[0];
  R[3] = Reast[0];

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  R[7] = a[1];
  R[4] = Reast[1];

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  R[8] = a[2];
  R[5] = Reast[2];

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  _mm_storeu_pd(&R[0], _mm_sub_pd(_mm_mul_pd(_mm_set_pd(a[0], Reast[1]),
    _mm_set_pd(Reast[2], a[2])), _mm_mul_pd(_mm_set_pd(Reast[0], a[1]),
    _mm_set_pd(a[2], Reast[2]))));
  R[2] = Reast[0] * a[1] - a[0] * Reast[1];
  for (i2 = 0; i2 <= 6; i2 += 2) {
    tmp = _mm_loadu_pd(&R[i2]);
    _mm_storeu_pd(&x[i2], _mm_mul_pd(tmp, tmp));
  }

  for (i2 = 8; i2 < 9; i2++) {
    real_T R_0;
    R_0 = R[i2];
    x[i2] = R_0 * R_0;
  }

  for (i2 = 0; i2 < 3; i2++) {
    xpageoffset = i2 * 3;

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    Reast[i2] = sqrt((x[xpageoffset + 1] + x[xpageoffset]) + x[xpageoffset + 2]);
  }

  memcpy(&x[0], &R[0], 9U * sizeof(real_T));
  for (i2 = 0; i2 < 3; i2++) {
    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    tmp = _mm_div_pd(_mm_loadu_pd(&x[3 * i2]), _mm_set1_pd(Reast[i2]));
    _mm_storeu_pd(&R[3 * i2], tmp);
    xpageoffset = 3 * i2 + 2;
    R[xpageoffset] = x[xpageoffset] / Reast[i2];
  }

  for (i2 = 0; i2 < 9; i2++) {
    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    b[i2] = rtIsNaN(R[i2]);
  }

  y[0] = false;
  y[1] = false;
  y[2] = false;
  i2 = 1;
  for (xpageoffset = 0; xpageoffset < 3; xpageoffset++) {
    int32_T i2_0;
    int32_T ix;

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    i2_0 = i2;
    ix = i2;

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    i2 += 3;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2_0 + 2)) {
      if (b[ix - 1]) {
        y[xpageoffset] = true;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  nanPageIdx = false;
  i2 = 0;
  exitg1 = false;
  while ((!exitg1) && (i2 < 3)) {
    if (y[i2]) {
      nanPageIdx = true;
      exitg1 = true;
    } else {
      i2++;
    }
  }

  if (nanPageIdx) {
    memset(&R[0], 0, 9U * sizeof(real_T));
    R[0] = 1.0;
    R[4] = 1.0;
    R[8] = 1.0;
  }
}

static void AccGyrXSi_quaternion_quaternion(const real_T varargin_1[3], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d)
{
  real_T tmp[2];
  real_T st;
  real_T st_tmp;
  real_T theta;
  *obj_a = 1.0;
  *obj_b = 0.0;
  *obj_c = 0.0;
  *obj_d = 0.0;

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  theta = sqrt((varargin_1[0] * varargin_1[0] + varargin_1[1] * varargin_1[1]) +
               varargin_1[2] * varargin_1[2]);
  st_tmp = theta / 2.0;
  st = sin(st_tmp);
  if (theta != 0.0) {
    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    *obj_a = cos(st_tmp);
    _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_div_pd(_mm_loadu_pd(&varargin_1[0]),
      _mm_set1_pd(theta)), _mm_set1_pd(st)));
    *obj_b = tmp[0];
    *obj_c = tmp[1];

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    *obj_d = varargin_1[2] / theta * st;
  }
}

static void AccGyrXSim_imufilter_stepImpl(fusion_internal_simulink_imuf_T *obj,
  const real_T accelIn[3], const real_T gyroIn[3], real_T orientOut[4], real_T
  angvel[3])
{
  __m128d tmp;
  __m128d tmp_1;
  real_T Ppost[81];
  real_T H[27];
  real_T y[27];
  real_T y_0[27];
  real_T y_tmp[27];
  real_T Rpost[9];
  real_T Rpost_0[9];
  real_T psquared[4];
  real_T deltaAng[3];
  real_T tmp_0[2];
  real_T a21;
  real_T deltaAng_idx_1;
  real_T deltaAng_idx_2;
  real_T e_c;
  real_T e_d;
  real_T invpa;
  real_T invpd;
  real_T maxval;
  real_T n;
  real_T pGyroOffsetIn_idx_0;
  real_T pGyroOffsetIn_idx_1;
  real_T pGyroOffsetIn_idx_2;
  real_T pa;
  real_T pd;
  real_T q_a;
  real_T y_1;
  real_T y_2;
  int32_T H_tmp;
  int32_T H_tmp_0;
  int32_T H_tmp_1;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  static const real_T tmp_2[3] = { 1.0, 0.0, 0.0 };

  static const int8_T tmp_3[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  boolean_T exitg1;

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  pGyroOffsetIn_idx_0 = obj->pGyroOffset[0];
  pGyroOffsetIn_idx_1 = obj->pGyroOffset[1];
  pGyroOffsetIn_idx_2 = obj->pGyroOffset[2];
  if (obj->pFirstTime) {
    AccGyrXSim_NED_ecompass(accelIn, tmp_2, Rpost);
    pd = (Rpost[0] + Rpost[4]) + Rpost[8];
    psquared[0] = (pd * 2.0 + 1.0) - pd;
    _mm_storeu_pd(&psquared[1], _mm_sub_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(2.0),
      _mm_set_pd(Rpost[4], Rpost[0])), _mm_set1_pd(1.0)), _mm_set1_pd(pd)));
    psquared[3] = (2.0 * Rpost[8] + 1.0) - pd;
    if (!rtIsNaN(psquared[0])) {
      r2 = 1;
    } else {
      r2 = 0;
      r1 = 2;
      exitg1 = false;
      while ((!exitg1) && (r1 < 5)) {
        if (!rtIsNaN(psquared[r1 - 1])) {
          r2 = r1;
          exitg1 = true;
        } else {
          r1++;
        }
      }
    }

    if (r2 == 0) {
      pd = psquared[0];
      r2 = 1;
    } else {
      pd = psquared[r2 - 1];
      r3 = r2;
      for (r1 = r2 + 1; r1 < 5; r1++) {
        pa = psquared[r1 - 1];
        if (pd < pa) {
          pd = pa;
          r3 = r1;
        }
      }

      r2 = r3;
    }

    switch (r2) {
     case 1:
      pa = sqrt(pd);
      pd = 0.5 * pa;
      invpa = 0.5 / pa;
      tmp_1 = _mm_mul_pd(_mm_sub_pd(_mm_set_pd(Rpost[2], Rpost[7]), _mm_loadu_pd
        (&Rpost[5])), _mm_set1_pd(invpa));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      pa = tmp_0[0];
      invpd = tmp_0[1];
      invpa *= Rpost[3] - Rpost[1];
      break;

     case 2:
      pd = sqrt(pd);
      pa = 0.5 * pd;
      invpa = 0.5 / pd;
      _mm_storeu_pd(&tmp_0[0], _mm_mul_pd(_mm_add_pd(_mm_set_pd(Rpost[1], Rpost
        [7]), _mm_mul_pd(_mm_set_pd(Rpost[3], Rpost[5]), _mm_set_pd(1.0, -1.0))),
        _mm_set1_pd(invpa)));
      pd = tmp_0[0];
      invpd = tmp_0[1];
      invpa *= Rpost[2] + Rpost[6];
      break;

     case 3:
      pd = sqrt(pd);
      invpd = 0.5 * pd;
      invpa = 0.5 / pd;
      _mm_storeu_pd(&tmp_0[0], _mm_mul_pd(_mm_add_pd(_mm_set_pd(Rpost[1], Rpost
        [2]), _mm_mul_pd(_mm_set_pd(Rpost[3], Rpost[6]), _mm_set_pd(1.0, -1.0))),
        _mm_set1_pd(invpa)));
      pd = tmp_0[0];
      pa = tmp_0[1];
      invpa *= Rpost[5] + Rpost[7];
      break;

     default:
      pd = sqrt(pd);
      invpa = 0.5 * pd;
      invpd = 0.5 / pd;
      _mm_storeu_pd(&tmp_0[0], _mm_mul_pd(_mm_add_pd(_mm_set_pd(Rpost[2], Rpost
        [3]), _mm_mul_pd(_mm_set_pd(Rpost[6], Rpost[1]), _mm_set_pd(1.0, -1.0))),
        _mm_set1_pd(invpd)));
      pd = tmp_0[0];
      pa = tmp_0[1];
      invpd *= Rpost[5] + Rpost[7];
      break;
    }

    if (pd < 0.0) {
      pd = -pd;
      pa = -pa;
      invpd = -invpd;
      invpa = -invpa;
    }

    obj->pOrientPost.a = pd;
    obj->pOrientPost.b = pa;
    obj->pOrientPost.c = invpd;
    obj->pOrientPost.d = invpa;
  }

  tmp_1 = _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(&gyroIn[0]), _mm_loadu_pd
    (&obj->pGyroOffset[0])), _mm_set1_pd(obj->pSensorPeriod));
  _mm_storeu_pd(&deltaAng[0], tmp_1);

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  deltaAng[2] = (gyroIn[2] - obj->pGyroOffset[2]) * obj->pSensorPeriod;
  AccGyrXSi_quaternion_quaternion(deltaAng, &n, &deltaAng_idx_1, &deltaAng_idx_2,
    &a21);

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  invpd = ((obj->pOrientPost.a * n - obj->pOrientPost.b * deltaAng_idx_1) -
           obj->pOrientPost.c * deltaAng_idx_2) - obj->pOrientPost.d * a21;
  invpa = ((obj->pOrientPost.a * deltaAng_idx_1 + obj->pOrientPost.b * n) +
           obj->pOrientPost.c * a21) - obj->pOrientPost.d * deltaAng_idx_2;
  e_c = ((obj->pOrientPost.a * deltaAng_idx_2 - obj->pOrientPost.b * a21) +
         obj->pOrientPost.c * n) + obj->pOrientPost.d * deltaAng_idx_1;
  e_d = ((obj->pOrientPost.a * a21 + obj->pOrientPost.b * deltaAng_idx_2) -
         obj->pOrientPost.c * deltaAng_idx_1) + obj->pOrientPost.d * n;
  if (((obj->pOrientPost.a * n - obj->pOrientPost.b * deltaAng_idx_1) -
       obj->pOrientPost.c * deltaAng_idx_2) - obj->pOrientPost.d * a21 < 0.0) {
    invpd = -invpd;
    invpa = -invpa;
    e_c = -e_c;
    e_d = -e_d;
  }

  n = sqrt(((invpd * invpd + invpa * invpa) + e_c * e_c) + e_d * e_d);
  q_a = invpd / n;
  pa = invpa / n;
  deltaAng_idx_1 = e_c / n;
  maxval = e_d / n;
  n = (pa * maxval * 2.0 - q_a * deltaAng_idx_1 * 2.0) * 9.81;
  pd = obj->LinearAccelerationDecayFactor * obj->pLinAccelPost[0];
  deltaAng_idx_1 = (deltaAng_idx_1 * maxval * 2.0 + q_a * pa * 2.0) * 9.81;
  pa = obj->LinearAccelerationDecayFactor * obj->pLinAccelPost[1];
  deltaAng_idx_2 = ((q_a * q_a * 2.0 - 1.0) + maxval * maxval * 2.0) * 9.81;
  q_a = obj->LinearAccelerationDecayFactor * obj->pLinAccelPost[2];
  memset(&Rpost[0], 0, 9U * sizeof(real_T));

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  Rpost[3] = deltaAng_idx_2;
  Rpost[6] = -deltaAng_idx_1;
  Rpost[7] = n;
  for (r1 = 0; r1 < 3; r1++) {
    Rpost_0[3 * r1] = Rpost[3 * r1];
    r2 = 3 * r1 + 1;
    tmp_1 = _mm_sub_pd(_mm_loadu_pd(&Rpost[r2]), _mm_set_pd(Rpost[r1 + 6],
      Rpost[r1 + 3]));
    _mm_storeu_pd(&Rpost_0[r2], tmp_1);
  }

  for (r1 = 0; r1 < 9; r1++) {
    maxval = Rpost_0[r1];
    H[r1] = maxval;

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    H[r1 + 9] = -maxval * obj->pKalmanPeriod;
    H[r1 + 18] = tmp_3[r1];
    y[3 * r1] = 0.0;
    y[3 * r1 + 1] = 0.0;
    y[3 * r1 + 2] = 0.0;
  }

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  for (r1 = 0; r1 < 9; r1++) {
    a21 = y[3 * r1];
    rtemp = 3 * r1 + 1;
    y_1 = y[rtemp];
    r3 = 3 * r1 + 2;
    y_2 = y[r3];
    for (r2 = 0; r2 < 9; r2++) {
      maxval = obj->pQw[9 * r1 + r2];
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&H[3 * r2]), _mm_set1_pd(maxval)),
                         _mm_set_pd(y_1, a21));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      a21 = tmp_0[0];
      y_1 = tmp_0[1];
      y_2 += H[3 * r2 + 2] * maxval;
    }

    y[r3] = y_2;
    y[rtemp] = y_1;
    y[3 * r1] = a21;
    y_tmp[r1] = H[3 * r1];
    y_tmp[r1 + 9] = H[rtemp];
    y_tmp[r1 + 18] = H[r3];
  }

  for (r1 = 0; r1 < 3; r1++) {
    maxval = 0.0;
    a21 = 0.0;
    y_1 = 0.0;
    for (r2 = 0; r2 < 9; r2++) {
      y_2 = y_tmp[9 * r1 + r2];
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&y[3 * r2]), _mm_set1_pd(y_2)),
                         _mm_set_pd(a21, maxval));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      maxval = tmp_0[0];
      a21 = tmp_0[1];
      y_1 += y[3 * r2 + 2] * y_2;
    }

    Rpost_0[3 * r1 + 2] = y_1;
    Rpost_0[3 * r1 + 1] = a21;
    Rpost_0[3 * r1] = maxval;
  }

  for (r1 = 0; r1 < 3; r1++) {
    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    _mm_storeu_pd(&Rpost[3 * r1], _mm_add_pd(_mm_set_pd(Rpost_0[r1 + 3],
      Rpost_0[r1]), _mm_set_pd(obj->pQv[r1 + 3], obj->pQv[r1])));
    Rpost[3 * r1 + 2] = Rpost_0[r1 + 6] + obj->pQv[r1 + 6];
  }

  for (r1 = 0; r1 < 9; r1++) {
    y_0[r1] = 0.0;
    y_0[r1 + 9] = 0.0;
    y_0[r1 + 18] = 0.0;
  }

  for (r1 = 0; r1 < 3; r1++) {
    for (r2 = 0; r2 < 9; r2++) {
      maxval = y_tmp[9 * r1 + r2];
      for (r3 = 0; r3 <= 6; r3 += 2) {
        /* Start for MATLABSystem: '<Root>/IMU Filter' */
        tmp_1 = _mm_loadu_pd(&obj->pQw[9 * r2 + r3]);
        rtemp = 9 * r1 + r3;
        tmp = _mm_loadu_pd(&y_0[rtemp]);
        _mm_storeu_pd(&y_0[rtemp], _mm_add_pd(_mm_mul_pd(tmp_1, _mm_set1_pd
          (maxval)), tmp));
      }

      for (r3 = 8; r3 < 9; r3++) {
        rtemp = 9 * r1 + r3;

        /* Start for MATLABSystem: '<Root>/IMU Filter' */
        y_0[rtemp] += obj->pQw[9 * r2 + r3] * maxval;
      }
    }
  }

  r1 = 0;

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  r2 = 1;
  r3 = 2;
  maxval = fabs(Rpost[0]);
  a21 = fabs(Rpost[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    r2 = 0;
  }

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  if (fabs(Rpost[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  Rpost[r2] /= Rpost[r1];
  Rpost[r3] /= Rpost[r1];
  Rpost[r2 + 3] -= Rpost[r1 + 3] * Rpost[r2];
  Rpost[r3 + 3] -= Rpost[r1 + 3] * Rpost[r3];
  Rpost[r2 + 6] -= Rpost[r1 + 6] * Rpost[r2];
  Rpost[r3 + 6] -= Rpost[r1 + 6] * Rpost[r3];

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  if (fabs(Rpost[r3 + 3]) > fabs(Rpost[r2 + 3])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  Rpost[r3 + 3] /= Rpost[r2 + 3];
  Rpost[r3 + 6] -= Rpost[r3 + 3] * Rpost[r2 + 6];
  for (rtemp = 0; rtemp < 9; rtemp++) {
    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    H_tmp = 9 * r1 + rtemp;
    H[H_tmp] = y_0[rtemp] / Rpost[r1];
    H_tmp_0 = 9 * r2 + rtemp;
    H[H_tmp_0] = y_0[rtemp + 9] - Rpost[r1 + 3] * H[H_tmp];
    H_tmp_1 = 9 * r3 + rtemp;
    H[H_tmp_1] = y_0[rtemp + 18] - Rpost[r1 + 6] * H[H_tmp];
    H[H_tmp_0] /= Rpost[r2 + 3];
    H[H_tmp_1] -= Rpost[r2 + 6] * H[H_tmp_0];
    H[H_tmp_1] /= Rpost[r3 + 6];
    H[H_tmp_0] -= Rpost[r3 + 3] * H[H_tmp_1];
    H[H_tmp] -= H[H_tmp_1] * Rpost[r3];
    H[H_tmp] -= H[H_tmp_0] * Rpost[r2];
  }

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  _mm_storeu_pd(&deltaAng[0], _mm_sub_pd(_mm_add_pd(_mm_loadu_pd(&accelIn[0]),
    _mm_set_pd(pa, pd)), _mm_set_pd(deltaAng_idx_1, n)));
  deltaAng[2] = (accelIn[2] + q_a) - deltaAng_idx_2;
  memset(&Rpost[0], 0, 9U * sizeof(real_T));
  for (r1 = 0; r1 < 3; r1++) {
    maxval = deltaAng[r1];
    for (r2 = 0; r2 <= 6; r2 += 2) {
      /* Start for MATLABSystem: '<Root>/IMU Filter' */
      tmp_1 = _mm_loadu_pd(&H[9 * r1 + r2]);
      tmp = _mm_loadu_pd(&Rpost[r2]);
      _mm_storeu_pd(&Rpost[r2], _mm_add_pd(_mm_mul_pd(tmp_1, _mm_set1_pd(maxval)),
        tmp));
    }

    for (r2 = 8; r2 < 9; r2++) {
      /* Start for MATLABSystem: '<Root>/IMU Filter' */
      Rpost[r2] += H[9 * r1 + r2] * maxval;
    }
  }

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  AccGyrXSi_quaternion_quaternion(&Rpost[0], &n, &deltaAng_idx_1,
    &deltaAng_idx_2, &a21);
  maxval = ((invpd * n - invpa * -deltaAng_idx_1) - e_c * -deltaAng_idx_2) - e_d
    * -a21;
  obj->pOrientPost.a = maxval;
  obj->pOrientPost.b = ((invpd * -deltaAng_idx_1 + invpa * n) + e_c * -a21) -
    e_d * -deltaAng_idx_2;
  obj->pOrientPost.c = ((invpd * -deltaAng_idx_2 - invpa * -a21) + e_c * n) +
    e_d * -deltaAng_idx_1;
  obj->pOrientPost.d = ((invpd * -a21 + invpa * -deltaAng_idx_2) - e_c *
                        -deltaAng_idx_1) + e_d * n;
  if (maxval < 0.0) {
    obj->pOrientPost.a = -obj->pOrientPost.a;
    obj->pOrientPost.b = -obj->pOrientPost.b;
    obj->pOrientPost.c = -obj->pOrientPost.c;
    obj->pOrientPost.d = -obj->pOrientPost.d;
  }

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  n = sqrt(((obj->pOrientPost.a * obj->pOrientPost.a + obj->pOrientPost.b *
             obj->pOrientPost.b) + obj->pOrientPost.c * obj->pOrientPost.c) +
           obj->pOrientPost.d * obj->pOrientPost.d);
  obj->pOrientPost.a /= n;
  obj->pOrientPost.b /= n;
  obj->pOrientPost.c /= n;
  obj->pOrientPost.d /= n;
  for (r1 = 0; r1 < 9; r1++) {
    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    invpd = H[r1 + 9];
    invpa = H[r1];
    e_c = H[r1 + 18];
    for (r2 = 0; r2 < 9; r2++) {
      /* Start for MATLABSystem: '<Root>/IMU Filter' */
      r3 = 9 * r2 + r1;
      Ppost[r3] = obj->pQw[r3] - ((y[3 * r2 + 1] * invpd + y[3 * r2] * invpa) +
        y[3 * r2 + 2] * e_c);
    }
  }

  memset(&obj->pQw[0], 0, 81U * sizeof(real_T));

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  a21 = obj->pKalmanPeriod * obj->pKalmanPeriod;
  invpd = obj->GyroscopeDriftNoise + obj->GyroscopeNoise;
  obj->pQw[0] = (Ppost[30] + invpd) * a21 + Ppost[0];
  obj->pQw[30] = Ppost[30] + obj->GyroscopeDriftNoise;
  obj->pQw[10] = (Ppost[40] + invpd) * a21 + Ppost[10];
  obj->pQw[40] = Ppost[40] + obj->GyroscopeDriftNoise;
  obj->pQw[20] = (Ppost[50] + invpd) * a21 + Ppost[20];
  obj->pQw[50] = Ppost[50] + obj->GyroscopeDriftNoise;
  _mm_storeu_pd(&tmp_0[0], _mm_mul_pd(_mm_set1_pd(-obj->pKalmanPeriod),
    _mm_set_pd(obj->pQw[40], obj->pQw[30])));
  deltaAng_idx_1 = tmp_0[1];

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  deltaAng_idx_2 = -obj->pKalmanPeriod * obj->pQw[50];
  a21 = obj->LinearAccelerationDecayFactor * obj->LinearAccelerationDecayFactor;
  obj->pFirstTime = false;
  obj->pQw[3] = tmp_0[0];
  obj->pQw[27] = tmp_0[0];

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  obj->pQw[60] = a21 * Ppost[60] + obj->LinearAccelerationNoise;
  _mm_storeu_pd(&tmp_0[0], _mm_sub_pd(_mm_set_pd(pd, obj->pGyroOffset[0]),
    _mm_set_pd(Rpost[6], Rpost[3])));
  obj->pGyroOffset[0] = tmp_0[0];
  obj->pLinAccelPost[0] = tmp_0[1];
  angvel[0] = gyroIn[0] - pGyroOffsetIn_idx_0;
  obj->pQw[13] = deltaAng_idx_1;
  obj->pQw[37] = deltaAng_idx_1;

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  obj->pQw[70] = a21 * Ppost[70] + obj->LinearAccelerationNoise;
  _mm_storeu_pd(&tmp_0[0], _mm_sub_pd(_mm_set_pd(pa, obj->pGyroOffset[1]),
    _mm_set_pd(Rpost[7], Rpost[4])));
  obj->pGyroOffset[1] = tmp_0[0];
  obj->pLinAccelPost[1] = tmp_0[1];
  angvel[1] = gyroIn[1] - pGyroOffsetIn_idx_1;
  obj->pQw[23] = deltaAng_idx_2;
  obj->pQw[47] = deltaAng_idx_2;

  /* Start for MATLABSystem: '<Root>/IMU Filter' */
  obj->pQw[80] = a21 * Ppost[80] + obj->LinearAccelerationNoise;
  _mm_storeu_pd(&tmp_0[0], _mm_sub_pd(_mm_set_pd(q_a, obj->pGyroOffset[2]),
    _mm_set_pd(Rpost[8], Rpost[5])));
  obj->pGyroOffset[2] = tmp_0[0];
  obj->pLinAccelPost[2] = tmp_0[1];
  angvel[2] = gyroIn[2] - pGyroOffsetIn_idx_2;
  orientOut[0] = obj->pOrientPost.a;
  orientOut[1] = obj->pOrientPost.b;
  orientOut[2] = obj->pOrientPost.c;
  orientOut[3] = obj->pOrientPost.d;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void AccGyrXSim_step(void)
{
  __m128d tmp_1;
  __m128d tmp_3;
  real_T tmp[4];
  real_T rtb_Transpose[3];
  real_T rtb_VectorConcatenate1[3];
  real_T tmp_0[3];
  real_T tmp_2[2];
  real_T a;
  real_T a_tmp;
  real_T b;
  real_T c;
  real_T f_idx_0;
  int32_T i;
  int8_T b_I[9];

  /* Math: '<Root>/Transpose' incorporates:
   *  Inport: '<Root>/AccX'
   *  Inport: '<Root>/AccY'
   *  Inport: '<Root>/AccZ'
   */
  rtb_Transpose[0] = AccGyrXSim_U.AccX;
  rtb_Transpose[1] = AccGyrXSim_U.AccY;
  rtb_Transpose[2] = AccGyrXSim_U.AccZ;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/GyrX'
   */
  rtb_VectorConcatenate1[0] = 0.0010652644360316954 * AccGyrXSim_U.GyrX;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Inport: '<Root>/GyrY'
   */
  rtb_VectorConcatenate1[1] = 0.0010652644360316954 * AccGyrXSim_U.GyrY;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Inport: '<Root>/GyrZ'
   */
  rtb_VectorConcatenate1[2] = 0.0010652644360316954 * AccGyrXSim_U.GyrZ;

  /* MATLABSystem: '<Root>/IMU Filter' incorporates:
   *  Math: '<Root>/Transpose'
   *  Math: '<Root>/Transpose1'
   */
  if (AccGyrXSim_DW.obj.AccelerometerNoise != 0.0001924722) {
    if (AccGyrXSim_DW.obj.isInitialized == 1) {
      AccGyrXSim_DW.obj.TunablePropsChanged = true;
    }

    AccGyrXSim_DW.obj.AccelerometerNoise = 0.0001924722;
  }

  if (AccGyrXSim_DW.obj.GyroscopeNoise != 9.1385E-5) {
    if (AccGyrXSim_DW.obj.isInitialized == 1) {
      AccGyrXSim_DW.obj.TunablePropsChanged = true;
    }

    AccGyrXSim_DW.obj.GyroscopeNoise = 9.1385E-5;
  }

  if (AccGyrXSim_DW.obj.GyroscopeDriftNoise != 3.0462E-13) {
    if (AccGyrXSim_DW.obj.isInitialized == 1) {
      AccGyrXSim_DW.obj.TunablePropsChanged = true;
    }

    AccGyrXSim_DW.obj.GyroscopeDriftNoise = 3.0462E-13;
  }

  if (AccGyrXSim_DW.obj.LinearAccelerationNoise != 0.0096236100000000012) {
    if (AccGyrXSim_DW.obj.isInitialized == 1) {
      AccGyrXSim_DW.obj.TunablePropsChanged = true;
    }

    AccGyrXSim_DW.obj.LinearAccelerationNoise = 0.0096236100000000012;
  }

  if (AccGyrXSim_DW.obj.LinearAccelerationDecayFactor != 0.5) {
    if (AccGyrXSim_DW.obj.isInitialized == 1) {
      AccGyrXSim_DW.obj.TunablePropsChanged = true;
    }

    AccGyrXSim_DW.obj.LinearAccelerationDecayFactor = 0.5;
  }

  if (AccGyrXSim_DW.obj.TunablePropsChanged) {
    AccGyrXSim_DW.obj.TunablePropsChanged = false;
    AccGyrXSim_DW.obj.pSensorPeriod = 0.43999999999999995;
    AccGyrXSim_DW.obj.pKalmanPeriod = 0.43999999999999995;
    for (i = 0; i < 9; i++) {
      b_I[i] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    for (i = 0; i <= 6; i += 2) {
      _mm_storeu_pd(&AccGyrXSim_DW.obj.pQv[i], _mm_mul_pd(_mm_set1_pd
        (0.0098337743360589758), _mm_set_pd(b_I[i + 1], b_I[i])));
    }

    for (i = 8; i < 9; i++) {
      AccGyrXSim_DW.obj.pQv[i] = 0.0098337743360589758 * (real_T)b_I[i];
    }
  }

  AccGyrXSim_imufilter_stepImpl(&AccGyrXSim_DW.obj, rtb_Transpose,
    rtb_VectorConcatenate1, tmp, tmp_0);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  MATLABSystem: '<Root>/IMU Filter'
   */
  tmp_3 = _mm_set1_pd(sqrt(((tmp[0] * tmp[0] + tmp[1] * tmp[1]) + tmp[2] * tmp[2])
    + tmp[3] * tmp[3]));

  /* MATLABSystem: '<Root>/IMU Filter' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  tmp_1 = _mm_div_pd(_mm_loadu_pd(&tmp[0]), tmp_3);
  _mm_storeu_pd(&tmp_2[0], tmp_1);

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  c = tmp_2[0];
  b = tmp_2[1];

  /* MATLABSystem: '<Root>/IMU Filter' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  tmp_3 = _mm_div_pd(_mm_loadu_pd(&tmp[2]), tmp_3);
  _mm_storeu_pd(&tmp_2[0], tmp_3);

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  a = b * tmp_2[1] * 2.0 - c * tmp_2[0] * 2.0;
  if (a > 1.0) {
    a = 1.0;
  }

  f_idx_0 = a;
  if (a < -1.0) {
    f_idx_0 = -1.0;
  }

  if ((f_idx_0 < 0.0) && (fabs(f_idx_0 + 1.0) < 2.2204460492503131E-15)) {
    a = -2.0 * rt_atan2d_snf(b, c);
    c = 0.0;
    b = 1.5707963267948966;
  } else if ((f_idx_0 > 0.0) && (fabs(f_idx_0 - 1.0) < 2.2204460492503131E-15))
  {
    a = 2.0 * rt_atan2d_snf(b, c);
    c = 0.0;
    b = -1.5707963267948966;
  } else {
    a_tmp = c * c * 2.0 - 1.0;
    a = rt_atan2d_snf(c * tmp_2[1] * 2.0 + b * tmp_2[0] * 2.0, b * b * 2.0 +
                      a_tmp);
    c = rt_atan2d_snf(c * b * 2.0 + tmp_2[0] * tmp_2[1] * 2.0, tmp_2[1] * tmp_2
                      [1] * 2.0 + a_tmp);
    b = -asin(f_idx_0);
  }

  rtb_VectorConcatenate1[0] = 57.295779513082323 * a;
  rtb_VectorConcatenate1[1] = 57.295779513082323 * b;
  rtb_VectorConcatenate1[2] = 57.295779513082323 * c;
  if (rtIsNaN((rtb_VectorConcatenate1[0] - 45.0) + 180.0) || rtIsInf
      ((rtb_VectorConcatenate1[0] - 45.0) + 180.0)) {
    b = (rtNaN);
  } else {
    b = fmod((rtb_VectorConcatenate1[0] - 45.0) + 180.0, 360.0);
    if (b == 0.0) {
      b = 0.0;
    } else if (b < 0.0) {
      b += 360.0;
    }
  }

  if (rtIsNaN(rtb_VectorConcatenate1[1] + 180.0) || rtIsInf
      (rtb_VectorConcatenate1[1] + 180.0)) {
    c = (rtNaN);
  } else {
    c = fmod(rtb_VectorConcatenate1[1] + 180.0, 360.0);
    if (c == 0.0) {
      c = 0.0;
    } else if (c < 0.0) {
      c += 360.0;
    }
  }

  if (rtIsNaN(rtb_VectorConcatenate1[2] + 180.0) || rtIsInf
      (rtb_VectorConcatenate1[2] + 180.0)) {
    a = (rtNaN);
  } else {
    a = fmod(rtb_VectorConcatenate1[2] + 180.0, 360.0);
    if (a == 0.0) {
      a = 0.0;
    } else if (a < 0.0) {
      a += 360.0;
    }
  }

  /* Outport: '<Root>/Roll' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  AccGyrXSim_Y.Roll = b - 180.0;

  /* Outport: '<Root>/Pitch' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  AccGyrXSim_Y.Pitch = c - 180.0;

  /* Outport: '<Root>/Yaw' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  AccGyrXSim_Y.Yaw = a - 180.0;

  /* Outport: '<Root>/AngX' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLABSystem: '<Root>/IMU Filter'
   */
  AccGyrXSim_Y.AngX = tmp_0[0];

  /* Outport: '<Root>/AngY' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLABSystem: '<Root>/IMU Filter'
   */
  AccGyrXSim_Y.AngY = tmp_0[1];

  /* Outport: '<Root>/AngZ' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLABSystem: '<Root>/IMU Filter'
   */
  AccGyrXSim_Y.AngZ = tmp_0[2];

  /* Matfile logging */
  rt_UpdateTXYLogVars(AccGyrXSim_M->rtwLogInfo, (&AccGyrXSim_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.44s, 0.0s] */
    if ((rtmGetTFinal(AccGyrXSim_M)!=-1) &&
        !((rtmGetTFinal(AccGyrXSim_M)-AccGyrXSim_M->Timing.taskTime0) >
          AccGyrXSim_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(AccGyrXSim_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++AccGyrXSim_M->Timing.clockTick0)) {
    ++AccGyrXSim_M->Timing.clockTickH0;
  }

  AccGyrXSim_M->Timing.taskTime0 = AccGyrXSim_M->Timing.clockTick0 *
    AccGyrXSim_M->Timing.stepSize0 + AccGyrXSim_M->Timing.clockTickH0 *
    AccGyrXSim_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void AccGyrXSim_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)AccGyrXSim_M, 0,
                sizeof(RT_MODEL_AccGyrXSim_T));
  rtmSetTFinal(AccGyrXSim_M, 22.0);
  AccGyrXSim_M->Timing.stepSize0 = 0.44;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    AccGyrXSim_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(AccGyrXSim_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(AccGyrXSim_M->rtwLogInfo, (NULL));
    rtliSetLogT(AccGyrXSim_M->rtwLogInfo, "tout");
    rtliSetLogX(AccGyrXSim_M->rtwLogInfo, "");
    rtliSetLogXFinal(AccGyrXSim_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(AccGyrXSim_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(AccGyrXSim_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(AccGyrXSim_M->rtwLogInfo, 0);
    rtliSetLogDecimation(AccGyrXSim_M->rtwLogInfo, 1);
    rtliSetLogY(AccGyrXSim_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(AccGyrXSim_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(AccGyrXSim_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&AccGyrXSim_DW, 0,
                sizeof(DW_AccGyrXSim_T));

  /* external inputs */
  (void)memset(&AccGyrXSim_U, 0, sizeof(ExtU_AccGyrXSim_T));

  /* external outputs */
  (void)memset(&AccGyrXSim_Y, 0, sizeof(ExtY_AccGyrXSim_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(AccGyrXSim_M->rtwLogInfo, 0.0, rtmGetTFinal
    (AccGyrXSim_M), AccGyrXSim_M->Timing.stepSize0, (&rtmGetErrorStatus
    (AccGyrXSim_M)));

  {
    int32_T i;
    int8_T b_I[9];
    static const real_T tmp[81] = { 6.0923483957341713E-6, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 6.0923483957341713E-6, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 6.0923483957341713E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 7.6154354946677142E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 7.6154354946677142E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 7.6154354946677142E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0096236100000000012 };

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    AccGyrXSim_DW.objisempty = true;
    AccGyrXSim_DW.obj.AccelerometerNoise = 0.0001924722;
    AccGyrXSim_DW.obj.GyroscopeNoise = 9.1385E-5;
    AccGyrXSim_DW.obj.GyroscopeDriftNoise = 3.0462E-13;
    AccGyrXSim_DW.obj.LinearAccelerationNoise = 0.0096236100000000012;
    AccGyrXSim_DW.obj.LinearAccelerationDecayFactor = 0.5;
    AccGyrXSim_DW.obj.isInitialized = 1;
    AccGyrXSim_DW.obj.pSensorPeriod = 0.43999999999999995;
    AccGyrXSim_DW.obj.pKalmanPeriod = 0.43999999999999995;
    AccGyrXSim_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/IMU Filter' */
    AccGyrXSim_DW.obj.pOrientPost.a = 1.0;
    AccGyrXSim_DW.obj.pOrientPost.b = 0.0;
    AccGyrXSim_DW.obj.pOrientPost.c = 0.0;
    AccGyrXSim_DW.obj.pOrientPost.d = 0.0;

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    AccGyrXSim_DW.obj.pInputPrototype[0] = 0.0;

    /* InitializeConditions for MATLABSystem: '<Root>/IMU Filter' */
    AccGyrXSim_DW.obj.pGyroOffset[0] = 0.0;

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    AccGyrXSim_DW.obj.pInputPrototype[1] = 0.0;

    /* InitializeConditions for MATLABSystem: '<Root>/IMU Filter' */
    AccGyrXSim_DW.obj.pGyroOffset[1] = 0.0;

    /* Start for MATLABSystem: '<Root>/IMU Filter' */
    AccGyrXSim_DW.obj.pInputPrototype[2] = 0.0;

    /* InitializeConditions for MATLABSystem: '<Root>/IMU Filter' */
    AccGyrXSim_DW.obj.pGyroOffset[2] = 0.0;
    for (i = 0; i < 9; i++) {
      b_I[i] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    for (i = 0; i <= 6; i += 2) {
      _mm_storeu_pd(&AccGyrXSim_DW.obj.pQv[i], _mm_mul_pd(_mm_set1_pd
        (0.0098337743360589758), _mm_set_pd(b_I[i + 1], b_I[i])));
    }

    for (i = 8; i < 9; i++) {
      AccGyrXSim_DW.obj.pQv[i] = 0.0098337743360589758 * (real_T)b_I[i];
    }

    memcpy(&AccGyrXSim_DW.obj.pQw[0], &tmp[0], 81U * sizeof(real_T));
    AccGyrXSim_DW.obj.pLinAccelPost[0] = 0.0;
    AccGyrXSim_DW.obj.pLinAccelPost[1] = 0.0;
    AccGyrXSim_DW.obj.pLinAccelPost[2] = 0.0;
    AccGyrXSim_DW.obj.pFirstTime = true;
  }
}

/* Model terminate function */
void AccGyrXSim_terminate(void)
{
  /* (no terminate code required) */
}
