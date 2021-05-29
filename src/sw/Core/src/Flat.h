#ifndef SRC_FLAT_H_
#define SRC_FLAT_H_

#include "Room.h"
#include "RoomBuilder.h"

#include <memory>

class Flat
{
	public:
		Flat();
		~Flat() = default;

		using Rooms = std::shared_ptr<std::vector<std::shared_ptr<Room>>>;

		void addRoom(std::shared_ptr<Room> room);
		const Rooms getRooms() const;
		const std::shared_ptr<RoomBuilder> getBuilder() const;

	private:
		std::shared_ptr<RoomBuilder> m_roomBuilder;
		Rooms m_rooms;
};


#endif /* SRC_FLAT_H_ */
