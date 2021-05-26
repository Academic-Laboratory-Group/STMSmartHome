#include "Flat.h"


void Flat::addRoom(std::shared_ptr<Room> room)
{
	m_rooms.push_back(room);
}

const std::vector<std::shared_ptr<Room>> Flat::getRooms() const
{
	return m_rooms;
}

const std::shared_ptr<RoomBuilder> Flat::getBuilder() const
{
	return m_roomBuilder;
}





