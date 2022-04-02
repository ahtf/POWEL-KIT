/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SEGMENT_H
#define __SEGMENT_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "main.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define NBOF_DIGITS           					4
#define NBOF_OFF_SEGMENT_LED_GROUPS			0
#define NBOF_LED_GROUPS									(NBOF_DIGITS + NBOF_OFF_SEGMENT_LED_GROUPS)


#define SEGMENT_SHIFT_REGISTER_DRIVER_USED
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
int   SEG_procesString                (char *str);
void  SEG_refreshDigits               (void);


/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#define SDI_SET() 	(HAL_GPIO_WritePin(SEG_SDI_GPIO_Port,	SEG_SDI_Pin, GPIO_PIN_SET))
#define SDI_RESET() (HAL_GPIO_WritePin(SEG_SDI_GPIO_Port,	SEG_SDI_Pin, GPIO_PIN_RESET))
#define CLK_SET() 	(HAL_GPIO_WritePin(SEG_CLK_GPIO_Port,	SEG_CLK_Pin, GPIO_PIN_SET))
#define CLK_RESET() (HAL_GPIO_WritePin(SEG_CLK_GPIO_Port,	SEG_CLK_Pin, GPIO_PIN_RESET))
#define LAT_SET() 	(HAL_GPIO_WritePin(SEG_LAT_GPIO_Port,	SEG_LAT_Pin, GPIO_PIN_SET))
#define LAT_RESET()	(HAL_GPIO_WritePin(SEG_LAT_GPIO_Port,	SEG_LAT_Pin, GPIO_PIN_RESET))
/* Private functions ---------------------------------------------------------*/

#endif /* __SEGMENT_H */