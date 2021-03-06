#ifndef _UTILS_H_
#define _UTILS_H_
	
#include "gpio.h"


enum class ButtonShape
{
	Square,
	Circle
};
	
enum Color
{
	WHITE = 0xFFFF,
	BLACK = 0x0000,
	BLUE = 0x001F,
	BRED = 0XF81F,
	GRED = 0XFFE0,
	GBLUE	= 0X07FF,
	RED = 0xF800,
	MAGENTA = 0xF81F,
	GREEN = 0x07E0,
	CYAN = 0x7FFF,
	YELLOW = 0xFFE0,
	BROWN = 0XBC40,
	BRRED = 0XFC07,
	GRAY = 0X8430,
	BACKGROUND_COLOR = WHITE,
	BUTTON_BACKGROUND_COLOR = GRAY,
	FRAMES_COLOR = BLACK,
	BUTTON_TEXT_COLOR = WHITE,
	TEXT_COLOR = BLACK
};

enum class SensorType
{
	Temperature,
	Size
};

enum class ControllerType
{
	Switch,
	PWM,
	Size
};

#endif
