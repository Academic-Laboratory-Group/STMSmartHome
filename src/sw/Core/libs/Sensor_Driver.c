#include "Sensor_Driver.h"

void Delay_us (uint32_t delay)
{
	htim14.Instance->CNT = 0;
	while (htim14.Instance->CNT <= delay);
}

void ONE_WIRE_SET(GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin)
{
	HAL_GPIO_WritePin(m_GPIOx, m_GPIO_pin, GPIO_PIN_SET);
}

void ONE_WIRE_RESET(GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin)
{
	HAL_GPIO_WritePin(m_GPIOx, m_GPIO_pin, GPIO_PIN_RESET);
}

uint8_t DS18B20_Init(GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin)
{
	ONE_WIRE_OUTPUT(m_GPIOx, m_GPIO_pin);
	ONE_WIRE_SET(m_GPIOx, m_GPIO_pin);
	Delay_us(5);
	ONE_WIRE_RESET(m_GPIOx, m_GPIO_pin);
	Delay_us(750);
	ONE_WIRE_SET(m_GPIOx, m_GPIO_pin);
	ONE_WIRE_INPUT(m_GPIOx, m_GPIO_pin);
	
	int i = 0;
	while(HAL_GPIO_ReadPin(m_GPIOx, m_GPIO_pin))
	{
		i++;
		if(i > 60)
			return 0;
		Delay_us(1);
	}
	i = 480 - i;
	ONE_WIRE_OUTPUT(m_GPIOx, m_GPIO_pin);
	Delay_us(i);
	ONE_WIRE_SET(m_GPIOx, m_GPIO_pin);
	return 1;
}

void DS18B20_Write(uint8_t data, GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin)
{
  ONE_WIRE_OUTPUT(m_GPIOx, m_GPIO_pin);
  for (unsigned i = 0; i < 8; ++i)
  {
    ONE_WIRE_RESET(m_GPIOx, m_GPIO_pin);
    Delay_us(10);
    if (data & 1) ONE_WIRE_SET(m_GPIOx, m_GPIO_pin);
    else ONE_WIRE_RESET(m_GPIOx, m_GPIO_pin);
    data >>= 1;
    Delay_us(50);
    ONE_WIRE_SET(m_GPIOx, m_GPIO_pin);
  }
}

uint8_t DS18B20_Read(GPIO_TypeDef* m_GPIOx, uint16_t m_GPIO_pin)
{
  ONE_WIRE_OUTPUT(m_GPIOx, m_GPIO_pin);
  ONE_WIRE_SET(m_GPIOx, m_GPIO_pin);
  Delay_us(2);
  uint8_t data = 0;
  for (unsigned i = 0; i < 8; ++i)
  {
    ONE_WIRE_RESET(m_GPIOx, m_GPIO_pin);
    Delay_us(1);
    ONE_WIRE_SET(m_GPIOx, m_GPIO_pin);
    ONE_WIRE_INPUT(m_GPIOx, m_GPIO_pin);
    Delay_us(5);
    data >>= 1;
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)) data |= 0x80;
    Delay_us(55);
    ONE_WIRE_OUTPUT(m_GPIOx, m_GPIO_pin);
    ONE_WIRE_SET(m_GPIOx, m_GPIO_pin);
  }
  return data;
}
