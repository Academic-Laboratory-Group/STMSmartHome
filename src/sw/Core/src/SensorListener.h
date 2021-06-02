#ifndef _SENSOR_LISTENER_H_
#define _SENSOR_LISTENER_H_

#include "Utils.h"

class SensorListener
{
public:
	virtual void notify(SensorType sensorType, float value) = 0;
};

#endif
