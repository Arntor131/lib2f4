#include "../Inc/STM32F4_SPI.h"

void SPI_TransmitByte(SPI_TypeDef *SPIx, uint8_t data)
{
	*(volatile uint8_t *)&SPIx->DR = data;
	while(!(SPIx->SR & SPI_SR_TXE));
	while(SPIx->SR & SPI_SR_BSY);
}
