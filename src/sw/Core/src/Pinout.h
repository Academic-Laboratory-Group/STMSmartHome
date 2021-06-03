#ifndef SRC_PINOUT_H_
#define SRC_PINOUT_H_

#include "gpio.h"
#include "tim.h"

#include <array>


struct Pin
{
	int pin = -1;
	GPIO_TypeDef * GPIO = nullptr;
};

struct PWMConnection
{
	int channel = -1;
	TIM_HandleTypeDef* htim = nullptr;
};

// Sensors
constexpr std::array<Pin, 3> g_sensorsPinOut =
{{{GPIO_PIN_8, GPIOC}, {GPIO_PIN_6, GPIOC}, {GPIO_PIN_5, GPIOC}}};
static volatile size_t  g_sensorsPinOutIterator = 0;

// Heaters
constexpr std::array<Pin, 3> g_switchPinOut =
{{{GPIO_PIN_9, GPIOC}, {GPIO_PIN_8, GPIOB}, {GPIO_PIN_9, GPIOB}}};
static volatile size_t  g_switchPinOutIterator = 0;

// Lights
constexpr std::array<PWMConnection, 2> g_PWMPinOut =
{{{TIM_CHANNEL_1, &htim12}, {TIM_CHANNEL_2, &htim12}}};
static volatile size_t  g_PWMPinOutIterator = 0;


#endif /* SRC_PINOUT_H_ */
