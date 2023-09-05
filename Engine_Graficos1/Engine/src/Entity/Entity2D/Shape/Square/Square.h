#pragma once
#include "Entity/Entity2D/Shape/Shape.h"

class Square : public Shape
{
public:
	Square();
	~Square();

	void Draw() override;
};
