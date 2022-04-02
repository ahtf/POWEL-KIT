/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOD
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOD
#define POT1_Pin GPIO_PIN_0
#define POT1_GPIO_Port GPIOA
#define POT2_Pin GPIO_PIN_1
#define POT2_GPIO_Port GPIOA
#define TX2_Pin GPIO_PIN_2
#define TX2_GPIO_Port GPIOA
#define RX2_Pin GPIO_PIN_3
#define RX2_GPIO_Port GPIOA
#define POT3_Pin GPIO_PIN_4
#define POT3_GPIO_Port GPIOA
#define TEMP_Pin GPIO_PIN_5
#define TEMP_GPIO_Port GPIOA
#define PWM_R_Pin GPIO_PIN_6
#define PWM_R_GPIO_Port GPIOA
#define PWM_G_Pin GPIO_PIN_7
#define PWM_G_GPIO_Port GPIOA
#define PWM_B_Pin GPIO_PIN_0
#define PWM_B_GPIO_Port GPIOB
#define USB_PU_Pin GPIO_PIN_1
#define USB_PU_GPIO_Port GPIOB
#define SEG_SDI_Pin GPIO_PIN_2
#define SEG_SDI_GPIO_Port GPIOB
#define SEG_CLK_Pin GPIO_PIN_10
#define SEG_CLK_GPIO_Port GPIOB
#define SEG_LAT_Pin GPIO_PIN_11
#define SEG_LAT_GPIO_Port GPIOB
#define PWM_N_Pin GPIO_PIN_13
#define PWM_N_GPIO_Port GPIOB
#define PWM_P_Pin GPIO_PIN_8
#define PWM_P_GPIO_Port GPIOA
#define RGB_DI_Pin GPIO_PIN_10
#define RGB_DI_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define BUZ_Pin GPIO_PIN_15
#define BUZ_GPIO_Port GPIOA
#define SW2_Pin GPIO_PIN_3
#define SW2_GPIO_Port GPIOB
#define SW3_Pin GPIO_PIN_5
#define SW3_GPIO_Port GPIOB
#define ROT_A_Pin GPIO_PIN_6
#define ROT_A_GPIO_Port GPIOB
#define ROT_B_Pin GPIO_PIN_7
#define ROT_B_GPIO_Port GPIOB
#define SW1_Pin GPIO_PIN_8
#define SW1_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
