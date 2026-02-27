/*
 * File: AccGyrXSim.h
 *
 * Code generated for Simulink model 'AccGyrXSim'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Feb 23 16:50:48 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef AccGyrXSim_h_
#define AccGyrXSim_h_
#ifndef AccGyrXSim_COMMON_INCLUDES_
#define AccGyrXSim_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* AccGyrXSim_COMMON_INCLUDES_ */

#include "AccGyrXSim_types.h"
#include "rtGetNaN.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Ppost[81];
  real_T H[27];
  real_T y[27];
  real_T y_m[27];
  real_T y_tmp[27];
  real_T Rpost[9];
  real_T Rpost_c[9];
  real_T x[9];
} B_AccGyrXSim_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  fusion_internal_simulink_imuf_T obj; /* '<Root>/IMU Filter' */
} DW_AccGyrXSim_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T AccX;                         /* '<Root>/AccX' */
  real_T AccY;                         /* '<Root>/AccY' */
  real_T AccZ;                         /* '<Root>/AccZ' */
  real_T GyrX;                         /* '<Root>/GyrX' */
  real_T GyrY;                         /* '<Root>/GyrY' */
  real_T GyrZ;                         /* '<Root>/GyrZ' */
} ExtU_AccGyrXSim_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Roll;                         /* '<Root>/Roll' */
  real_T Pitch;                        /* '<Root>/Pitch' */
  real_T Yaw;                          /* '<Root>/Yaw' */
  real_T AngX;                         /* '<Root>/AngX' */
  real_T AngY;                         /* '<Root>/AngY' */
  real_T AngZ;                         /* '<Root>/AngZ' */
} ExtY_AccGyrXSim_T;

/* Real-time Model Data Structure */
struct tag_RTM_AccGyrXSim_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_AccGyrXSim_T AccGyrXSim_B;

/* Block states (default storage) */
extern DW_AccGyrXSim_T AccGyrXSim_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_AccGyrXSim_T AccGyrXSim_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_AccGyrXSim_T AccGyrXSim_Y;

/* Model entry point functions */
extern void AccGyrXSim_initialize(void);
extern void AccGyrXSim_step(void);
extern void AccGyrXSim_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AccGyrXSim_T *const AccGyrXSim_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Zero-Order Hold3' : Eliminated since input and output rates are identical
 * Block '<Root>/Zero-Order Hold4' : Eliminated since input and output rates are identical
 * Block '<Root>/Zero-Order Hold5' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'AccGyrXSim'
 * '<S1>'   : 'AccGyrXSim/MATLAB Function'
 * '<S2>'   : 'AccGyrXSim/MATLAB Function1'
 */
#endif                                 /* AccGyrXSim_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
