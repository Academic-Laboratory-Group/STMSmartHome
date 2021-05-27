#include "Flat.h"

Flat::Flat() : m_roomBuilder(std::make_shared<RoomBuilder>()),
m_rooms(std::make_shared<std::vector<Room>>())
{

}

void Flat::addRoom(std::shared_ptr<Room> room)
{
	m_rooms->push_back(std::move(*room.get()));
}

const std::shared_ptr<std::vector<Room>> Flat::getRooms() const
{
	return m_rooms;
}

const std::shared_ptr<RoomBuilder> Flat::getBuilder() const
{
	return m_roomBuilder;
}
