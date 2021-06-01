#ifndef SRC_SHAPE_H_
#define SRC_SHAPE_H_

#include "Utils.h"
#include "Renderable.h"


class Shape : public Renderable
{
public:
	Shape(int xCenter, int yCenter, Color color = BUTTON_BACKGROUND_COLOR) :
		m_xCenter(xCenter), m_yCenter(yCenter), m_color(color) {};
	virtual ~Shape() = default;

protected:
	int m_xCenter;
	int m_yCenter;
	Color m_color;
};

#endif /* SRC_SHAPE_H_ */
