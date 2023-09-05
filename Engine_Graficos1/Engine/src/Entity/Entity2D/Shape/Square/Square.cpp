#include "Square.h"
#include "RendererSingleton.h"

Square::Square()
{
	float positions[4][2] = { 
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f, 0.5f,
		-0.5f, 0.5f 
	};

	unsigned int tempIndices[6] = {
		0, 1, 2,
		2, 3, 0,
	};

	*vBuffer = RendererSingleton::GetRenderer()->SetNewVertexBuffer(positions, 4 * (sizeof(float) * 2 + sizeof(float) * 4)  );
	*iBuffer = RendererSingleton::GetRenderer()->SetNewIndexBuffer(tempIndices, 6);

}

Square::~Square()
{

}

void Square::Draw()
{
	RendererSingleton::GetRenderer()->Draw(*vBuffer, *iBuffer);
}
