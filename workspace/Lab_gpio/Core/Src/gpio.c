/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
# define LED_GPIOx GPIOD
# define LED4_GREEN_PinNumber GPIO_PIN_12
# define LED3_ORANGE_PinNumber GPIO_PIN_13
# define LED5_RED_PinNumber GPIO_PIN_14
# define LED6_BLUE_PinNumber GPIO_PIN_15
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
void gpio_led_state (uint8_t LED_ID, uint8_t state){
	GPIO_PinState pinState;
	pinState = (state == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	switch (LED_ID){
		case LED3_ORANGE_ID:
			HAL_GPIO_WritePin(GPIOD, LED3_ORANGE_PinNumber, pinState);
			break;
		case LED4_GREEN_ID:
			HAL_GPIO_WritePin(GPIOD, LED4_GREEN_PinNumber, pinState);
			break;
		case LED5_RED_ID:
			HAL_GPIO_WritePin(GPIOD, LED5_RED_PinNumber, pinState);
			break;
		case LED6_BLUE_ID:
			HAL_GPIO_WritePin(GPIOD, LED6_BLUE_PinNumber, pinState);
			break;
	}
}
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
