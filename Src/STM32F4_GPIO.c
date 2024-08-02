#include "../Inc/STM32F4_GPIO.h"

void GPIO_InitPin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t pinInitParam)
{
	/*Set port settings to zeros*/
	GPIOx->MODER &= ~(0x3 << (pin * 2));
	GPIOx->OTYPER &= ~(1 << pin) << pin;
	GPIOx->OSPEEDR &= ~(0x3 << (pin * 2));
	GPIOx->PUPDR &= ~(0x3 << (pin * 2));

	/* Get last 2 bits*/
	GPIOx->MODER |= (pinInitParam & 0x3) << (pin * 2);

	/* Delete first 2 bits */
	pinInitParam >>= 2;

	GPIOx->OTYPER |= (pinInitParam & 0x3) << pin;
	pinInitParam >>= 2;

	GPIOx->OSPEEDR |= (pinInitParam & 0x3) << (pin * 2);
	pinInitParam >>= 2;

	GPIOx->PUPDR |= (pinInitParam & 0x3) << (pin * 2);
}

void GPIO_SetAltMode(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode)
{
	/* If pin is in range 0-7 then write in AFRL (AFR[0]), if in range 8-5 then write in AFRH (AFR[1])
	 *
	 */
	GPIOx->AFR[pin >> 3] |= mode << ((pin > 7) ? ((pin * 4) - 32) : (pin * 4));
}

void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t pinState)
{
	if(pinState == 0)
	{
		GPIOx->BSRR = (1 << (pin + 16));
	}
	else
	{
		GPIOx->BSRR = (1 << pin);
	}
}

void GPIO_SetPort(GPIO_TypeDef *GPIOx, uint32_t portState)
{
	GPIOx->ODR = portState;
}

uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
	return (GPIOx->IDR & (1 << pin)) ? 1 : 0;
}

uint32_t GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	return GPIOx->IDR;
}
