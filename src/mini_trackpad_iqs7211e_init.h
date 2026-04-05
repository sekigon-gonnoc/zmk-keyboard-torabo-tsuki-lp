/*
* This file contains all the necessary settings for the IQS7211E.
* It can be changed from the GUI or edited here.
* File:   IQS7211E_init.h
* Author: Azoteq
*/ 

#pragma once

/* ALP ATI Compensation */
/* Memory Map Position 0x1F - 0x20 */
#define ALP_COMPENSATION_A_0                     0x00
#define ALP_COMPENSATION_A_1                     0x00
#define ALP_COMPENSATION_B_0                     0x00
#define ALP_COMPENSATION_B_1                     0x00

/* ATI Settings */
/* Memory Map Position 0x21 - 0x27 */
#define TP_ATI_MULTIPLIERS_DIVIDERS_0            0x81
#define TP_ATI_MULTIPLIERS_DIVIDERS_1            0x0A
#define TP_COMPENSATION_DIV                      0x05
#define TP_REF_DRIFT_LIMIT                       0x32
#define TP_ATI_TARGET_0                          0x96
#define TP_ATI_TARGET_1                          0x00
#define TP_MIN_COUNT_REATI_0                     0x32
#define TP_MIN_COUNT_REATI_1                     0x00
#define ALP_ATI_MULTIPLIERS_DIVIDERS_0           0x23
#define ALP_ATI_MULTIPLIERS_DIVIDERS_1           0x02
#define ALP_COMPENSATION_DIV                     0x02
#define ALP_LTA_DRIFT_LIMIT                      0x14
#define ALP_ATI_TARGET_0                         0x96
#define ALP_ATI_TARGET_1                         0x00

/* Report Rates and Timing */
/* Memory Map Position 0x28 - 0x32 */
#define ACTIVE_MODE_REPORT_RATE_0                0x0F
#define ACTIVE_MODE_REPORT_RATE_1                0x00
#define IDLE_TOUCH_MODE_REPORT_RATE_0            0x32
#define IDLE_TOUCH_MODE_REPORT_RATE_1            0x00
#define IDLE_MODE_REPORT_RATE_0                  0x1E
#define IDLE_MODE_REPORT_RATE_1                  0x00
#define LP1_MODE_REPORT_RATE_0                   0x50
#define LP1_MODE_REPORT_RATE_1                   0x00
#define LP2_MODE_REPORT_RATE_0                   0xA0
#define LP2_MODE_REPORT_RATE_1                   0x00
#define ACTIVE_MODE_TIMEOUT_0                    0x01
#define ACTIVE_MODE_TIMEOUT_1                    0x00
#define IDLE_TOUCH_MODE_TIMEOUT_0                0x3C
#define IDLE_TOUCH_MODE_TIMEOUT_1                0x00
#define IDLE_MODE_TIMEOUT_0                      0x05
#define IDLE_MODE_TIMEOUT_1                      0x00
#define LP1_MODE_TIMEOUT_0                       0x0A
#define LP1_MODE_TIMEOUT_1                       0x00
#define REATI_RETRY_TIME                         0x05
#define REF_UPDATE_TIME                          0x08
#define I2C_TIMEOUT_0                            0x64
#define I2C_TIMEOUT_1                            0x00

/* System Settings */
/* Memory Map Position 0x33 - 0x35 */
#define SYSTEM_CONTROL_0                         0x40
#define SYSTEM_CONTROL_1                         0x00
#define CONFIG_SETTINGS0                         0x2C
#define CONFIG_SETTINGS1                         0x07
#define OTHER_SETTINGS_0                         0x00
#define OTHER_SETTINGS_1                         0x00

/* ALP Settings */
/* Memory Map Position 0x36 - 0x37 */
#define ALP_SETUP_0                              0x41
#define ALP_SETUP_1                              0x03
#define ALP_TX_ENABLE_0                          0x06
#define ALP_TX_ENABLE_1                          0x10

/* Thresholds and Debounce Settings */
/* Memory Map Position 0x38 - 0x3A */
#define TRACKPAD_TOUCH_SET_THRESHOLD             0x14
#define TRACKPAD_TOUCH_CLEAR_THRESHOLD           0x0E
#define ALP_THRESHOLD_0                          0x08
#define ALP_THRESHOLD_1                          0x00
#define ALP_SET_DEBOUNCE                         0x04
#define ALP_CLEAR_DEBOUNCE                       0x04

/* Button and ALP count and LTA betas */
/* Memory Map Position 0x3B - 0x3C */
#define ALP_COUNT_BETA_LP1                       0xDC
#define ALP_LTA_BETA_LP1                         0x08
#define ALP_COUNT_BETA_LP2                       0xF0
#define ALP_LTA_BETA_LP2                         0x10

/* Hardware Settings */
/* Memory Map Position 0x3D - 0x40 */
#define TP_CONVERSION_FREQUENCY_UP_PASS_LENGTH   0x02
#define TP_CONVERSION_FREQUENCY_FRACTION_VALUE   0x1A
#define ALP_CONVERSION_FREQUENCY_UP_PASS_LENGTH  0x02
#define ALP_CONVERSION_FREQUENCY_FRACTION_VALUE  0x1A
#define TRACKPAD_HARDWARE_SETTINGS_0             0x03
#define TRACKPAD_HARDWARE_SETTINGS_1             0x80
#define ALP_HARDWARE_SETTINGS_0                  0x67
#define ALP_HARDWARE_SETTINGS_1                  0x90

/* Trackpad Settings */
/* Memory Map Position 0x41 - 0x49 */
#define TRACKPAD_SETTINGS_0_0                    0x2F // bit0: Flip X, bit1: Flip Y, bit3: Swap X/Y
#define TRACKPAD_SETTINGS_0_1                    0x04
#define TRACKPAD_SETTINGS_1_0                    0x03
#define TRACKPAD_SETTINGS_1_1                    0x02
#define X_RESOLUTION_0                           0xE1 //
#define X_RESOLUTION_1                           0x00 // 0x00E1 = 225
#define Y_RESOLUTION_0                           0x2C //
#define Y_RESOLUTION_1                           0x01 // 0x012C = 300
#define XY_DYNAMIC_FILTER_BOTTOM_SPEED_0         0x06
#define XY_DYNAMIC_FILTER_BOTTOM_SPEED_1         0x00
#define XY_DYNAMIC_FILTER_TOP_SPEED_0            0x7C
#define XY_DYNAMIC_FILTER_TOP_SPEED_1            0x00
#define XY_DYNAMIC_FILTER_BOTTOM_BETA            0x07
#define XY_DYNAMIC_FILTER_STATIC_FILTER_BETA     0x80
#define STATIONARY_TOUCH_MOV_THRESHOLD           0x14
#define FINGER_SPLIT_FACTOR                      0x00 // 0x00 = 1 finger mode
#define X_TRIM_VALUE                             0x14
#define Y_TRIM_VALUE                             0x14

/* Settings Version Numbers */
/* Memory Map Position 0x4A - 0x4A */
#define MINOR_VERSION                            0x00
#define MAJOR_VERSION                            0x00

/* Gesture Settings */
/* Memory Map Position 0x4B - 0x55 */
#define GESTURE_ENABLE_0                         0x1F
#define GESTURE_ENABLE_1                         0xFF
#define TAP_TOUCH_TIME_0                         0x96
#define TAP_TOUCH_TIME_1                         0x00
#define TAP_WAIT_TIME_0                          0x96
#define TAP_WAIT_TIME_1                          0x00
#define TAP_DISTANCE_0                           0x32
#define TAP_DISTANCE_1                           0x00
#define HOLD_TIME_0                              0x2C
#define HOLD_TIME_1                              0x01
#define SWIPE_TIME_0                             0x96
#define SWIPE_TIME_1                             0x00
#define SWIPE_X_DISTANCE_0                       0xC8
#define SWIPE_X_DISTANCE_1                       0x00
#define SWIPE_Y_DISTANCE_0                       0xC8
#define SWIPE_Y_DISTANCE_1                       0x00
#define SWIPE_X_CONS_DIST_0                      0x64
#define SWIPE_X_CONS_DIST_1                      0x00
#define SWIPE_Y_CONS_DIST_0                      0x64
#define SWIPE_Y_CONS_DIST_1                      0x00
#define SWIPE_ANGLE                              0x17
#define PALM_THRESHOLD                           0x1E

/* RxTx Mapping */
/* Memory Map Position 0x56 - 0x5C */
#define RX_TX_MAP_0                              0x07
#define RX_TX_MAP_1                              0x06
#define RX_TX_MAP_2                              0x03
#define RX_TX_MAP_3                              0x00
#define RX_TX_MAP_4                              0x0C
#define RX_TX_MAP_5                              0x02
#define RX_TX_MAP_6                              0x01
#define RX_TX_MAP_7                              0x07
#define RX_TX_MAP_8                              0x03
#define RX_TX_MAP_9                              0x09
#define RX_TX_MAP_10                             0x0A
#define RX_TX_MAP_11                             0x0B
#define RX_TX_MAP_12                             0x0C
#define RX_TX_MAP_FILLER                         0x00

/* Allocation of channels into cycles 0-9 */
/* Memory Map Position 0x5D - 0x6B */
#define PLACEHOLDER_0                            0x05
#define CH_1_CYCLE_0                             0x02
#define CH_2_CYCLE_0                             0x00
#define PLACEHOLDER_1                            0x05
#define CH_1_CYCLE_1                             0x03
#define CH_2_CYCLE_1                             0x01
#define PLACEHOLDER_2                            0x05
#define CH_1_CYCLE_2                             0x06
#define CH_2_CYCLE_2                             0x04
#define PLACEHOLDER_3                            0x05
#define CH_1_CYCLE_3                             0x07
#define CH_2_CYCLE_3                             0x05
#define PLACEHOLDER_4                            0x05
#define CH_1_CYCLE_4                             0x0A
#define CH_2_CYCLE_4                             0x08
#define PLACEHOLDER_5                            0x05
#define CH_1_CYCLE_5                             0x0B
#define CH_2_CYCLE_5                             0x09
#define PLACEHOLDER_6                            0x05
#define CH_1_CYCLE_6                             0xFF
#define CH_2_CYCLE_6                             0xFF
#define PLACEHOLDER_7                            0x05
#define CH_1_CYCLE_7                             0xFF
#define CH_2_CYCLE_7                             0xFF
#define PLACEHOLDER_8                            0x05
#define CH_1_CYCLE_8                             0xFF
#define CH_2_CYCLE_8                             0xFF
#define PLACEHOLDER_9                            0x05
#define CH_1_CYCLE_9                             0xFF
#define CH_2_CYCLE_9                             0xFF

/* Allocation of channels into cycles 10-19 */
/* Memory Map Position 0x6C - 0x7A */
#define PLACEHOLDER_10                           0x05
#define CH_1_CYCLE_10                            0xFF
#define CH_2_CYCLE_10                            0xFF
#define PLACEHOLDER_11                           0x05
#define CH_1_CYCLE_11                            0xFF
#define CH_2_CYCLE_11                            0xFF
#define PLACEHOLDER_12                           0x05
#define CH_1_CYCLE_12                            0xFF
#define CH_2_CYCLE_12                            0xFF
#define PLACEHOLDER_13                           0x05
#define CH_1_CYCLE_13                            0xFF
#define CH_2_CYCLE_13                            0xFF
#define PLACEHOLDER_14                           0x05
#define CH_1_CYCLE_14                            0xFF
#define CH_2_CYCLE_14                            0xFF
#define PLACEHOLDER_15                           0x05
#define CH_1_CYCLE_15                            0xFF
#define CH_2_CYCLE_15                            0xFF
#define PLACEHOLDER_16                           0x05
#define CH_1_CYCLE_16                            0xFF
#define CH_2_CYCLE_16                            0xFF
#define PLACEHOLDER_17                           0x05
#define CH_1_CYCLE_17                            0xFF
#define CH_2_CYCLE_17                            0xFF
#define PLACEHOLDER_18                           0x05
#define CH_1_CYCLE_18                            0xFF
#define CH_2_CYCLE_18                            0xFF
#define PLACEHOLDER_19                           0x05
#define CH_1_CYCLE_19                            0xFF
#define CH_2_CYCLE_19                            0xFF

/* Allocation of channels into cycles 20 */
/* Memory Map Position 0x7B - 0x7C */
#define PLACEHOLDER_20                           0x05
#define CH_1_CYCLE_20                            0xFF
#define CH_2_CYCLE_20                            0xFF
