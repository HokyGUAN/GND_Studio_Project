#include "led.h"
#include "delay.h"
#include "timer.h"

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	delay_enable(TRUE);
	led_enable(TRUE);
	timer_enable(4999, 7199, TRUE);
	
	for(;;)
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
	}
}

//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //���TIMx�����жϱ�־ 
		GPIO_SetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
		delay_ms(100);
	}
}
