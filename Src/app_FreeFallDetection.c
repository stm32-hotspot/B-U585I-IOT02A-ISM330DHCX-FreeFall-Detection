/**
 ******************************************************************************
 * @file    app_FreeFallDetection.c
 * @author  AME Sensors, RF & Cloud Support Team
 * @brief   This file provides a set of functions needed to manage the motion sensors
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

/* Includes ------------------------------------------------------------------*/
#include "app_FreeFallDetection.h"
#include "custom_mems_conf.h"
#include "ism330dhcx.h"


/* Use ism330dhcx for free-fall detection */
/* ism330dhcx object */
ISM330DHCX_Object_t ism330dhcx_object;
uint32_t uFreeFallDetected;

static int32_t ISM330DHCX_Probe(void);

/**
  * @brief  Query whether a free-fall event was detected
  * @retval Current state: 0=no free-fall, 1=free-fall detected
  */
uint32_t FreeFallDetection_GetState()
{
	return uFreeFallDetected;
}

/**
  * @brief  Set/Clear free-fall detected state
  * @retval None
  */
void FreeFallDetection_SetState(uint32_t newState)
{
	switch(newState)
	{
		case 0:
			uFreeFallDetected = 0;
			break;
		default:
			uFreeFallDetected = 1;
	}
}

/**
  * @brief  Handle a detected free fall event
  * @retval None
  */
void FreeFallDetection_Handler()
{
	ISM330DHCX_Event_Status_t EventStatus = {0};
	int32_t xReturn = 0;

	/* Get event which generated the interrupt */
	xReturn = ISM330DHCX_ACC_Get_Event_Status(&ism330dhcx_object, &EventStatus);
	if(ISM330DHCX_OK == xReturn)
	{

		if(EventStatus.FreeFallStatus==1)
		{
			if(FreeFallDetection_GetState() == 0)
			{
				FreeFallDetection_SetState(1);
			}
		}
	}
}

/**
  * @brief  Start free-fall detection using ISM330DLHC
  * @retval Error code
  */
int32_t FreeFallDetection_Init()
{
	int32_t xReturn = FFD_ERROR_NONE;
	int32_t xLocalReturn = ISM330DHCX_OK;

	uFreeFallDetected = 0;

	/* Configure bus and check device ID */
	xLocalReturn = ISM330DHCX_Probe();

	/* Enable freefall detection */
	if(ISM330DHCX_OK == xLocalReturn)
	{
		xLocalReturn = ISM330DHCX_ACC_Enable_Free_Fall_Detection(&ism330dhcx_object, FREEFALL_DETECTION_INT_PIN);
	}
	else
	{
		/* device probe error */
		xReturn = FFD_ERROR_NO_DEVICE_FOUND;
	}

	if(ISM330DHCX_OK == xLocalReturn)
	{
		xLocalReturn = ISM330DHCX_ACC_Set_Free_Fall_Threshold(&ism330dhcx_object, FREEFALL_DETECTION_THRESHOLD);
	}
	else
	{
		/*Free-fall detection enable error */
		xReturn = FFD_ERROR_DEVICE_OP_FAILED;
	}

	if(ISM330DHCX_OK == xLocalReturn)
	{
		xLocalReturn = ISM330DHCX_ACC_Set_Free_Fall_Duration(&ism330dhcx_object, FREEFALL_DETECTION_DURATION);
	}
	else
	{
		/*Free-fall detection threshold error */
		xReturn = FFD_ERROR_DEVICE_OP_FAILED;
	}

	/* Enable accelerometer */
	if(ISM330DHCX_OK == xLocalReturn)
	{
		xLocalReturn = ISM330DHCX_ACC_Enable(&ism330dhcx_object);
	}
	else
	{
		/*Free-fall detection duration error */
		xReturn = FFD_ERROR_DEVICE_OP_FAILED;
	}

	if(ISM330DHCX_OK != xLocalReturn)
	{
		/* Accelerometer enable error */
		xReturn = FFD_ERROR_DEVICE_OP_FAILED;
	}
	return xReturn;
}

/**
  * @brief  Stop free-fall detection
  * @retval Error code
  */
int32_t FreeFallDetection_DeInit()
{
	int32_t xReturn = FFD_ERROR_NONE;
	int32_t xLocalReturn = ISM330DHCX_OK;
	xLocalReturn = ISM330DHCX_ACC_Disable(&ism330dhcx_object);
	xLocalReturn |= ISM330DHCX_ACC_Disable_Free_Fall_Detection(&ism330dhcx_object);
	if(ISM330DHCX_OK != xLocalReturn)
	{
		xReturn = FFD_ERROR_DEVICE_OP_FAILED;
	}
	return xReturn;
}

/**
  * @brief  Configure sensor driver and probe for correct sensor id
  * @retval Error code
  */
static int32_t ISM330DHCX_Probe()
{
	ISM330DHCX_IO_t         io_ctx = {0};
	uint8_t                 id;
	int32_t ret = ISM330DHCX_OK;

	/* Configure the accelerometer driver */
	io_ctx.BusType     = ISM330DHCX_I2C_BUS; /* I2C */
	io_ctx.Address     = ISM330DHCX_I2C_ADD_H;
	io_ctx.Init        = CUSTOM_ISM330DHCX_0_I2C_Init;
	io_ctx.DeInit      = CUSTOM_ISM330DHCX_0_I2C_DeInit;
	io_ctx.ReadReg     = CUSTOM_ISM330DHCX_0_I2C_ReadReg;
	io_ctx.WriteReg    = CUSTOM_ISM330DHCX_0_I2C_WriteReg;

	if (ISM330DHCX_RegisterBusIO(&ism330dhcx_object, &io_ctx) != ISM330DHCX_OK)
	{
	  ret = ISM330DHCX_ERROR;
	}
	else if (ISM330DHCX_ReadID(&ism330dhcx_object, &id) != ISM330DHCX_OK)
	{
	  ret = ISM330DHCX_ERROR;
	}
	else if (id != ISM330DHCX_ID)
	{
	  ret = ISM330DHCX_ERROR;
	}
	return ret;
}
