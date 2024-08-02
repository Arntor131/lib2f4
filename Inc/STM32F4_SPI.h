#ifndef STM32F4_SPI_H
#define STM32F4_SPI_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../CMSIS/Inc/stm32f4xx.h"

void SPI_TransmitByte(SPI_TypeDef *SPIx, uint8_t data);
void SPI_TransmitWord(SPI_TypeDef *SPIx, uint16_t data);

#if defined(__cplusplus)
}
#endif

#endif
