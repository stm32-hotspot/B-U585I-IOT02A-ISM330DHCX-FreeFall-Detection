/**
 ******************************************************************************
 * @file    app_FreeFallDetection.h
 * @author  AME Sensors, RF & Cloud Support Team
 * @brief   freefall_detection application header file
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef APP_FREEFALLDETECTION_H
#define APP_FREEFALLDETECTION_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "ism330dhcx.h"
#include <string.h>

/** @addtogroup BSP BSP
 * @{
 */

/** @addtogroup Component Component
 * @{
 */

/** @addtogroup ISM330DHCX ISM330DHCX
 * @{
 */

/** @defgroup Freefall_Detection_Exported_Types Freefall Detection Exported Types
 * @{
 */



/**
 * @}
 */

/** @defgroup ISM330DHCX_Exported_Constants ISM330DHCX Exported Constants
 * @{
 */

#define FREEFALL_DETECTION_INT_PIN ISM330DHCX_INT1_PIN
#define FREEFALL_DETECTION_THRESHOLD 0x0  /* 3 bits: 0x0=156mg -> 0x7=500mg */
#define FREEFALL_DETECTION_DURATION  0xF  /* 6 bits: 1 lsb = 1/ODR time */

#define FFD_ERROR_NONE             0
#define FFD_ERROR_NO_DEVICE_FOUND  1
#define FFD_ERROR_DEVICE_OP_FAILED 2

/**
 * @}
 */

/** @addtogroup Freefall_Detection_Exported_Functions Freefall Detection Exported Functions
 * @{
 */
uint32_t FreeFallDetection_GetState(void);
void FreeFallDetection_SetState(uint32_t);
void FreeFallDetection_Handler(void);
int32_t FreeFallDetection_Init(void);
int32_t FreeFallDetection_DeInit(void);

/**
 * @}
 */

/** @addtogroup Freefall_Detection_Exported_Variables Freefall Detection Exported Variables
 * @{
 */


/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
