#include "Sprite.h"
#include "RendererSingleton.h"

Sprite::Sprite(const std::string& path)
{
	mRendererID = 0;
	mFilePath = path;
	mWidth = 0;
	mHeight = 0;
	mBPP = 0;
	imageID = mRendererID - 1;
}

Sprite::Sprite(const std::string& path, float vertexCol[4][4]) : mRendererID(0), mFilePath(path), mLocalBuffer(nullptr), mWidth(0), mHeight(0), mBPP(0)
{
	mRendererID = 0;
	mFilePath = path;
	mWidth = 0;
	mHeight = 0;
	mBPP = 0;
	imageID = mRendererID - 1;

	RendererSingleton::GetRenderer()->GetNewSprite(mFilePath, &mWidth, &mHeight, &mBPP, &mRendererID);

	float vertexPos[4][2] =
	{
		{-1, -1},
		{1, -1},
		{1, 1},
		{-1, 1}
	};

	float uvPos[4][2] =
	{
		{0, 0}, //bot left
		{1, 0}, //bot right
		{1, 1}, //top right
		{0, 1}  //top left
	};
	unsigned int indices[6] =
	{
		0, 1, 2,
		2, 3, 0
	};

	for (unsigned short i = 0; i < 4; i++)
	{
		for (unsigned short j = 0; j < 2; j++)
		{
			vertices[i][j] = vertexPos[i][j];
		}
		for (unsigned short j = 2; j < 6; j++)
		{
			vertices[i][j] = vertexCol[i][j - 2];
		}
		for (unsigned short j = 6; j < 8; j++)
		{			
			vertices[i][j] = uvPos[i][j - 6];
		}
	}

	Bind();

	//*vBuffer = RendererSingleton::GetRenderer()->GetNewVertexBuffer(vertices, 4 * (sizeof(float) * 2 + sizeof(float) * 2));
	*vBuffer = RendererSingleton::GetRenderer()->GetNewVertexBuffer(vertices, 4 * (2 * sizeof(float) + 4 * sizeof(float) + 2 * sizeof(float)));
	*iBuffer = RendererSingleton::GetRenderer()->GetNewIndexBuffer(indices, 6);

	Unbind();
}

Sprite::Sprite(const std::string& path, int spriteQuantity, int spriteNumber)
{
	mRendererID = 0;
	mFilePath = path;
	mWidth = 0;
	mHeight = 0;
	mBPP = 0;
	spriteQty = spriteQuantity;

	Renderer* tempRenderer = RendererSingleton::GetRenderer();
	tempRenderer->GetNewSprite(mFilePath, &mWidth, &mHeight, &mBPP, &mRendererID);

	imageID = mRendererID - 1;

	float vertexPos[4][2] =
	{
		{-1, -1},
		{1, -1},
		{1, 1},
		{-1, 1}
	};

	float leftX = (float)spriteNumber / spriteQuantity;
	float rightX = (float)(spriteNumber + 1) / spriteQuantity;

	float uvPos[4][2] =
	{
		{leftX, 0}, //bot left
		{rightX, 0}, //bot right
		{rightX, 1}, //top right
		{leftX, 1}  //top left
	};
	unsigned int indices[6] =
	{
		0, 1, 2,
		2, 3, 0
	};

	for (unsigned short i = 0; i < 4; i++)
	{
		for (unsigned short j = 0; j < 2; j++)
		{
			vertices[i][j] = vertexPos[i][j];
		}
		for (unsigned short j = 2; j < 4; j++)
		{
			vertices[i][j] = uvPos[i][j - 2];
		}
	}

	*vBuffer = tempRenderer->GetNewVertexBuffer(vertices, 4 * (sizeof(float) * 2 + sizeof(float) * 2));
	*iBuffer = tempRenderer->GetNewIndexBuffer(indices, 6);

	Bind();
}

Sprite::Sprite(const std::string& path, int frameQuantity, int spriteWidth, int spriteHeight, std::vector<Frame>& frameData)
{
	mRendererID = 0;
	mFilePath = path;
	mWidth = 0;
	mHeight = 0;
	mBPP = 0;
	imageID = mRendererID - 1;

	Renderer* tempRenderer = RendererSingleton::GetRenderer();
	tempRenderer->GetNewSprite(mFilePath, &mWidth, &mHeight, &mBPP, &mRendererID);

	imageID = mRendererID - 1;

	std::vector<float> allVertices;

	float vertexPos[4][2] =
	{
		{-1, -1},
		{1, -1},
		{1, 1},
		{-1, 1}
	};

	unsigned int indices[6] =
	{
		0, 1, 2,
		2, 3, 0
	};

	for (int frameNumber = 0; frameNumber < frameQuantity; ++frameNumber)
	{
		if (frameNumber >= frameData.size())
			break;


		// Calculate UV coordinates for the specified frame
		float leftX = frameData[frameNumber].GetLeftX() / spriteWidth;
		float rightX = frameData[frameNumber].GetRightX() / spriteWidth;
		float topY = frameData[frameNumber].GetTopY() / spriteHeight;
		float bottomV = frameData[frameNumber].GetBotY() / spriteHeight;

		float uvPos[4][2] =
		{
			{leftX, topY},      // top left
			{rightX, topY},     // top right
			{rightX, bottomV},  // bottom right
			{leftX, bottomV}    // bottom left
		};

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				allVertices.push_back(vertexPos[i][j]);
			}
			for (int j = 2; j < 4; j++)
			{
				allVertices.push_back(uvPos[i][j - 2]);
			}
		}
	}

	*vBuffer = RendererSingleton::GetRenderer()->GetNewVertexBuffer(allVertices.data(), 4 * (sizeof(float) * 2 + sizeof(float) * 2));
	*iBuffer = tempRenderer->GetNewIndexBuffer(indices, 6);

	Bind();
}

Sprite::~Sprite()
{
	RendererSingleton::GetRenderer()->DeleteSprite(&mRendererID);

	if (anim)
		delete anim;
}

void Sprite::Bind(unsigned int slot) const
{
	RendererSingleton::GetRenderer()->BindSprite(imageID, mRendererID);
	RendererSingleton::GetRenderer()->SetSprite(imageID);
}

void Sprite::Unbind()
{
	RendererSingleton::GetRenderer()->UnbindSprite();
}

unsigned int Sprite::GetImageID()
{
	return imageID;
}

void Sprite::ChangeSprite(float leftU, float rightX)
{
	float vertexPos[4][2] =
	{
		{-1, -1},
		{1, -1},
		{1, 1},
		{-1, 1}
	};

	float uvPos[4][2] =
	{
		{leftU, 0}, //bot left
		{rightX, 0}, //bot right
		{rightX, 1}, //top right
		{leftU, 1}  //top left
	};

	//ONLY CHANGES TEX COORD FROM EACH VERTEX
	for (unsigned short i = 0; i < 4; i++)
	{
		for (unsigned short j = 0; j < 2; j++)
		{
			vertices[i][j] = vertices[i][j];
		}
		for (unsigned short j = 2; j < 4; j++)
		{
			vertices[i][j] = uvPos[i][j - 2];
		}
	}

	RendererSingleton::GetRenderer()->GetNewVertexBuffer(*vBuffer, vertices, 4 * (sizeof(float) * 2 + sizeof(float) * 2));

	Bind();

	//UnBind();
}

void Sprite::ChangeSprite(int spriteQuantity, int spriteNumber)
{
	float widthHeightRatio = mWidth / mHeight;
	float adjustedX = 0.5f * widthHeightRatio;

	float vertexPos[4][2] =
	{
		{-adjustedX, -1},
		{adjustedX, -1},
		{adjustedX, 1},
		{-adjustedX, 1}
	};

	float leftX = (float)spriteNumber / spriteQuantity;
	float rightX = (float)(spriteNumber + 1) / spriteQuantity;

	float uvPos[4][2] =
	{
		{leftX, 0},  //bot left
		{rightX, 0}, //bot right
		{rightX, 1}, //top right
		{leftX, 1}   //top left
	};

	for (unsigned short i = 0; i < 4; i++)
	{
		//for (unsigned short j = 0; j < 2; j++)
		//{
		//	vertices[i][j] = vertices[i][j];
		//}
		for (unsigned short j = 2; j < 4; j++)
		{
			vertices[i][j] = uvPos[i][j - 2];
		}
	}

	Bind();

	RendererSingleton::GetRenderer()->GetNewVertexBuffer(*vBuffer, vertices, 4 * (sizeof(float) * 2 + sizeof(float) * 2));
	//Singleton::GetRenderer()->SetNewIndexBuffer(indices, 6);

	Unbind();
}

void Sprite::SetAnim(Animation* _anim)
{
	anim = _anim;
}

void Sprite::UpdateFrame()
{
	//Get old coords
	Vector2 oldCoords = anim->GetCurrentFrame();

	//Update animation timer
	anim->Update();

	//Get new coords
	Vector2 uCoords = anim->GetCurrentFrame();

	//If frame didn't change, exit
	if (oldCoords.x == uCoords.x) return;

	//If it's in new frame, update sprite
	ChangeSprite(uCoords.x, uCoords.y);
}

void Sprite::Draw()
{
	Bind();
	RendererSingleton::GetRenderer()->Draw(*vBuffer, *iBuffer, modelId);
	Unbind();
}