#ifndef __SENSOR_DRIVER_H
#define __SENSOR_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include "gpio.h"
#include "tim.h"

void Delay_us (uint32_t delay);
void ONE_WIRE_SET(GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin);
void ONE_WIRE_RESET(GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin);
uint8_t DS18B20_Init(GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin);
void DS18B20_Write(uint8_t data, GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin);
uint8_t DS18B20_Read(GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin);
	
	
#ifdef __cplusplus
}
#endif

#endif
