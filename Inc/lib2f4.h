#ifndef STM32_PERIPH_H
#define STM32_PERIPH_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(STM32F4)

#include "../../CMSIS/Inc/stm32f4xx.h"
#include "STM32F4_RCC.h"
#include "STM32F4_GPIO.h"
#include "STM32F4_SPI.h"

#if defined(STM32F411xE)
#define CLOCK_BASE_TIMER TIM11
#define CPU_STD_SPEED 100000000UL
#endif

#endif

void InitTimer(void);

void _delay_ms(uint32_t ms);
void _delay_ns(uint32_t ns);

extern volatile uint64_t systemUpTime;

uint64_t getSystemUpTime(void);

#if defined(__cplusplus)
}
#endif

#endif
