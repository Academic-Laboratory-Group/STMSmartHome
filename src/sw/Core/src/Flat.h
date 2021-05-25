#ifndef SRC_FLAT_H_
#define SRC_FLAT_H_

#include "Room.h"
#include "RoomBuilder.h"

class Flat
{
	public:
		Flat();

		void addRoom(Room &room);

	private:
		RoomBuilder m_roomBuilder;
		std::vector<Room> m_rooms;
};


#endif /* SRC_FLAT_H_ */
