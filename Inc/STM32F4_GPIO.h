#ifndef STM32F4_GPIO_H
#define STM32F4_GPIO_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../CMSIS/Inc/stm32f4xx.h"

#define GPIO_MODE_INPUT 	(0U)
#define GPIO_MODE_OUTPUT	(1U)
#define GPIO_MODE_ALT		(2U)
#define GPIO_MODE_ANALOG	(3U)

#define GPIO_OTYPE_PP		(0U << 2)
#define GPIO_OTYPE_OD		(1U << 2)

#define GPIO_OSPEED_2MHZ 	(0U << 4)
#define GPIO_OSPEED_10MHZ	(1U << 4)
#define GPIO_OSPEED_50MHZ	(2U << 4)

#define GPIO_PUPD_NOPULL	(0U << 6)
#define GPIO_PUPD_PULLUP	(1U << 6)
#define GPIO_PUPD_PULLDOWN	(2U << 6)

void GPIO_InitPin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t pinInitParam);

void GPIO_SetAltMode(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode);

void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t pinState);
void GPIO_SetPort(GPIO_TypeDef *GPIOx, uint32_t portState);

uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin);
uint32_t GPIO_ReadPort(GPIO_TypeDef *GPIOx);

#if defined(__cplusplus)
}
#endif

#endif
