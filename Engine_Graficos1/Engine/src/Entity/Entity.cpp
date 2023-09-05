#include "Entity.h"

Entity::Entity()
{
	vBuffer = new unsigned int;
	iBuffer = new unsigned int;
}

Entity::~Entity()
{
	delete vBuffer;
	delete iBuffer;
}

void Entity::Draw()
{
}
