/*
 * AccGyrXSim_types.h
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

#ifndef AccGyrXSim_types_h_
#define AccGyrXSim_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_PNHAOeXMeBDLyeZaJKzdBF
#define struct_tag_PNHAOeXMeBDLyeZaJKzdBF

struct tag_PNHAOeXMeBDLyeZaJKzdBF
{
  real_T a;
  real_T b;
  real_T c;
  real_T d;
};

#endif                                 /* struct_tag_PNHAOeXMeBDLyeZaJKzdBF */

#ifndef typedef_d_quaternion_AccGyrXSim_T
#define typedef_d_quaternion_AccGyrXSim_T

typedef struct tag_PNHAOeXMeBDLyeZaJKzdBF d_quaternion_AccGyrXSim_T;

#endif                                 /* typedef_d_quaternion_AccGyrXSim_T */

#ifndef struct_tag_rE0p9RRszDGqA6Mm8JUyIH
#define struct_tag_rE0p9RRszDGqA6Mm8JUyIH

struct tag_rE0p9RRszDGqA6Mm8JUyIH
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_rE0p9RRszDGqA6Mm8JUyIH */

#ifndef typedef_c_fusion_internal_frames_NED__T
#define typedef_c_fusion_internal_frames_NED__T

typedef struct tag_rE0p9RRszDGqA6Mm8JUyIH c_fusion_internal_frames_NED__T;

#endif                             /* typedef_c_fusion_internal_frames_NED__T */

#ifndef struct_tag_zPI27RVtJmMPrEpr7VhydH
#define struct_tag_zPI27RVtJmMPrEpr7VhydH

struct tag_zPI27RVtJmMPrEpr7VhydH
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T AccelerometerNoise;
  real_T GyroscopeNoise;
  real_T GyroscopeDriftNoise;
  real_T LinearAccelerationNoise;
  real_T LinearAccelerationDecayFactor;
  real_T pQw[81];
  real_T pQv[9];
  d_quaternion_AccGyrXSim_T pOrientPost;
  boolean_T pFirstTime;
  c_fusion_internal_frames_NED__T pRefSys;
  real_T pSensorPeriod;
  real_T pKalmanPeriod;
  real_T pGyroOffset[3];
  real_T pLinAccelPost[3];
  real_T pInputPrototype[3];
};

#endif                                 /* struct_tag_zPI27RVtJmMPrEpr7VhydH */

#ifndef typedef_fusion_internal_simulink_imuf_T
#define typedef_fusion_internal_simulink_imuf_T

typedef struct tag_zPI27RVtJmMPrEpr7VhydH fusion_internal_simulink_imuf_T;

#endif                             /* typedef_fusion_internal_simulink_imuf_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_AccGyrXSim_T RT_MODEL_AccGyrXSim_T;

#endif                                 /* AccGyrXSim_types_h_ */
