#include "../Inc/lib2f4.h"

#if defined(__cplusplus)
extern "C" {
#endif

volatile uint64_t systemUpTime = 0;

/*
 * 	@brief 	Initialize peripheral devices to ensure the correct operation of library functions
 * 	@retval none
 */
void InitTimer(void)
{
	/* Enable TIM11 */
	RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;

	/* Enable TIM11 interrupt*/
	NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);

	/* Prescaler: 1000, Compare value: 100 */
	TIM11->PSC = 1120;
	TIM11->ARR = 100;

	/* Enable timer event generation */
	TIM11->DIER |= TIM_DIER_UIE;

	/* Start TIM11 */
	TIM11->CR1 |= TIM_CR1_CEN;
}

/*
 * 	@brief	Stop the execution of the program for the specified period
 * 	@retval	none
 */
void _delay_ms(uint32_t ms)
{
	uint64_t timeStamp = getSystemUpTime();
	while((getSystemUpTime() - timeStamp) < ms);
}

/*
 * 	@brief	Get the time elapsed since the start of the system (in milliseconds)
 * 	@retval	System uptime
 */
uint64_t getSystemUpTime(void)
{
	return systemUpTime;
}

#if defined(__cplusplus)
}
#endif
