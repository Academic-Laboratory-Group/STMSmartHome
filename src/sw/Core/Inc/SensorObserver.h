#ifndef _SENSOROBSERVER_H_
#define _SENSOROBSERVER_H_

#include "Utils.h"

class SensorListener
{
	public:
		virtual void notify(Sensor sensor, int value) = 0;
};
	
#endif
