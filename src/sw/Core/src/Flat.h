#ifndef SRC_FLAT_H_
#define SRC_FLAT_H_

#include "Room.h"
#include "RoomBuilder.h"

#include <memory>


class Flat
{
	public:
		Flat() = default;
		~Flat() = default;

		void addRoom(std::shared_ptr<Room> room);
		const std::vector<std::shared_ptr<Room>> getRooms() const;
		const std::shared_ptr<RoomBuilder> getBuilder() const;

	private:
		std::shared_ptr<RoomBuilder> m_roomBuilder;
		std::vector<std::shared_ptr<Room>> m_rooms;
};


#endif /* SRC_FLAT_H_ */
