/*
 * AccGyrXSim.h
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

#ifndef AccGyrXSim_h_
#define AccGyrXSim_h_
#ifndef AccGyrXSim_COMMON_INCLUDES_
#define AccGyrXSim_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
//#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* AccGyrXSim_COMMON_INCLUDES_ */

#include "AccGyrXSim_types.h"
#include "rtGetNaN.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  fusion_internal_simulink_imuf_T obj; /* '<Root>/IMU Filter' */
  boolean_T objisempty;                /* '<Root>/IMU Filter' */
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
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

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
