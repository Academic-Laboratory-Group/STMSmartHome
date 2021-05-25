#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_

#include "TemperatureSensor.h"

class Room
{
	public:
		Room();

		float getTemperature();
		void setControllerValue(int controllerId, float value);

	private:
		TemperatureSensor m_sensor;

};

#endif /* SRC_ROOM_H_ */
