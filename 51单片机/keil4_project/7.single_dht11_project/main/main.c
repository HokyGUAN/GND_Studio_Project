#include <reg52.h>
#include <stdio.h>
#include "sys.h"
#include "delay.h"
#include "dht11.h"
#include "usart.h"

void main()
{
	Usart_Enable(TRUE);
	dht11_enable(TRUE);
	for(;;)
	{
		if(dht11_read_data() == TRUE)
		{
			printf("ʪ��Ϊ%d.%d ��RH ���¶�Ϊ %d.%d�� \n", dht11_humi_int(), dht11_humi_deci(), dht11_temp_int(), dht11_temp_deci());
		}
		else
		{
			printf("read error\n");
		}
		delay_ms(1000);
	}
}