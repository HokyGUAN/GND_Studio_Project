#ifndef __dht11_H
#define __dht11_H

#include "stm32f10x.h"

void dht11_enable(char enable);

unsigned char dht11_read_data(void);

typedef struct
{
	unsigned char humi_int;		//ʪ������
	unsigned char humi_deci;	//ʪ��С��
	unsigned char temp_int;		//�¶�����
	unsigned char temp_deci;	//�¶�С��
	unsigned char check_sum;
		                 
}dht11_data_t;

unsigned char dht11_humi_int(void);
unsigned char dht11_humi_deci(void);
unsigned char dht11_temp_int(void);
unsigned char dht11_temp_deci(void);

#endif
