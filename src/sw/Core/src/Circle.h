#ifndef SRC_CIRCLE_H_
#define SRC_CIRCLE_H_

#include "Shape.h"
#include "LCD_GUI.h"


class Circle : public Shape
{
public:
	Circle(int xCenter, int yCenter, int radius, Color color = BUTTON_BACKGROUND_COLOR) :
		Shape(xCenter, yCenter, color), m_radius(radius) {};
	~Circle() = default;

	void render() override
	{
		GUI_DrawCircle(m_xCenter, m_yCenter, m_radius, m_color, DRAW_FULL, DOT_PIXEL_2X2);
	}

private:
	int m_radius;
};

#endif /* SRC_CIRCLE_H_ */
