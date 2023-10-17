#include "Sprite.h"
#include "RendererSingleton.h"

Sprite::Sprite(const std::string& path, float vertexCol[4][4]) : mRendererID(0), mFilePath(path), mLocalBuffer(nullptr), mWidth(0), mHeight(0), mBPP(0)
{
	mRendererID = 0;
	mFilePath = path;
	mWidth = 0;
	mHeight = 0;
	mBPP = 0;
	imageID = mRendererID - 1;

	RendererSingleton::GetRenderer()->GetNewSprite(path, &mWidth, &mHeight, &mBPP, &mRendererID);

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

Sprite::~Sprite()
{
	RendererSingleton::GetRenderer()->DeleteSprite(&mRendererID);
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

int Sprite::GetWidth()
{
	return mWidth;
}

int Sprite::GetHeight()
{
	return mHeight;
}

void Sprite::Draw()
{
	Bind();
	RendererSingleton::GetRenderer()->Draw(*vBuffer, *iBuffer, modelId);
	Unbind();
}