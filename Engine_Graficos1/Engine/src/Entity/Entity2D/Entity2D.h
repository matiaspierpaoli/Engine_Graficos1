#pragma once
#include "Entity/Entity.h"

class Entity2D : public Entity
{
public:
	Entity2D();
	~Entity2D();

	void Draw() override;
};
