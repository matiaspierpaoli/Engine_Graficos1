#include "Game.h"
#include <iostream>

#pragma region keyCodes

#define KEY_W 87
#define KEY_A 65
#define KEY_S 83
#define KEY_D 68
#define KEY_Q 81
#define KEY_E 69
#define KEY_Z 90
#define KEY_X 88

#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_L 76
#define KEY_U 85
#define KEY_O 79
#define KEY_N 78
#define KEY_M 77

#pragma endregion

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{
	OnStart(512, 257, "Game");

	traslateX = 0.f;
	traslateY = 0.f;
	
	defaultTranslation.x = 50.0f;
	defaultTranslation.y = 50.0f; 

	defaultRotation = 10.0f;

	defaultScale.x = 10.0f;
	defaultScale.y = 10.0f;

	int sonicSpriteSheetWidth = 830;
	int sonicSpriteSheetHeight = 465;

#pragma region Idle 
	sonicIdleFrames.push_back(Frame(43, 74, sonicSpriteSheetHeight - 68, sonicSpriteSheetHeight - 22));
	sonicIdleFrames.push_back(Frame(74, 105, sonicSpriteSheetHeight - 68, sonicSpriteSheetHeight - 22));
	sonicIdleFrames.push_back(Frame(105, 137, sonicSpriteSheetHeight - 68, sonicSpriteSheetHeight - 22));
	sonicIdleFrames.push_back(Frame(137, 169, sonicSpriteSheetHeight - 68, sonicSpriteSheetHeight - 22));
	sonicIdleFrames.push_back(Frame(169, 199, sonicSpriteSheetHeight - 68, sonicSpriteSheetHeight - 22));
	sonicIdleFrames.push_back(Frame(199, 230, sonicSpriteSheetHeight - 68, sonicSpriteSheetHeight - 22));
	sonicIdleFrames.push_back(Frame(230, 260, sonicSpriteSheetHeight - 68, sonicSpriteSheetHeight - 22));
	sonicIdleFrames.push_back(Frame(22, 54, sonicSpriteSheetHeight - 113, sonicSpriteSheetHeight - 72));
	sonicIdleFrames.push_back(Frame(54, 82, sonicSpriteSheetHeight - 113, sonicSpriteSheetHeight - 72));
	sonicIdleFrames.push_back(Frame(82, 115, sonicSpriteSheetHeight - 113, sonicSpriteSheetHeight - 72));
	sonicIdleFrames.push_back(Frame(115, 150, sonicSpriteSheetHeight - 113, sonicSpriteSheetHeight - 72));
	sonicIdleFrames.push_back(Frame(150, 180, sonicSpriteSheetHeight - 113, sonicSpriteSheetHeight - 72));
#pragma endregion 

	#pragma region Run 
	sonicRunFrames.push_back(Frame(276, 304, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(304, 335, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(335, 377, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(377, 417, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(417, 455, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(455, 490, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(490, 520, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(520, 555, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(555, 593, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(593, 634, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(642, 672, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(672, 705, sonicSpriteSheetHeight - 162, sonicSpriteSheetHeight - 117));
#pragma endregion 


	sonic = new Sprite("res/Sonic_Mania_Sprite_Sheet.png",  12, sonicIdleFrames.at(0));
	sonic->Scale(75, 75);
	sonic->Translate(512 / 2 - 70, 257 / 2 - 30);

	sonicIdleAnim = new Animation(3, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicIdleFrames);
	sonicRunAnim = new Animation(0.8, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicRunFrames);
	
	static_cast<Sprite*>(sonic)->AddAnimation(sonicIdleAnim);
	static_cast<Sprite*>(sonic)->AddAnimation(sonicRunAnim);

#pragma endregion Cartel

	cartelFrames.push_back(Frame(130, 181, sonicSpriteSheetHeight - 372, sonicSpriteSheetHeight - 322));
	cartelFrames.push_back(Frame(181, 230, sonicSpriteSheetHeight - 372, sonicSpriteSheetHeight - 322));
	cartelFrames.push_back(Frame(230, 279, sonicSpriteSheetHeight - 372, sonicSpriteSheetHeight - 322));
	cartelFrames.push_back(Frame(279, 328, sonicSpriteSheetHeight - 372, sonicSpriteSheetHeight - 322));
	cartelFrames.push_back(Frame(328, 378, sonicSpriteSheetHeight - 372, sonicSpriteSheetHeight - 322));

	cartel = new Sprite("res/Sonic_Mania_Sprite_Sheet.png", 5, cartelFrames.at(0));
	cartel->Scale(75, 75);
	cartel->Translate(512 / 2 + 70, 257 / 2 + 40);

	cartelAnim = new Animation(3, sonicSpriteSheetWidth, sonicSpriteSheetHeight, cartelFrames);

	static_cast<Sprite*>(cartel)->AddAnimation(cartelAnim);

#pragma endregion

	background = new Sprite("res/background.png", 1, Frame(0, 512, 0, 257));
	background->Translate(512 / 2, 257 / 2);
	background->Scale(512 , 257);

	//float vertexCol1[4][4] =
	//{
	//	 0.0f,  1.0f, 0.0f, 1.0f,
	//	 0.0f,  1.0f, 0.0f, 1.0f,
	//	 0.0f,  1.0f, 0.0f, 1.0f,
	//	 0.0f,  1.0f, 0.0f, 1.0f,
	//};

	//float vertexCol2[4][4] =
	//{
	//	 0.0f,  0.0f, 1.0f, 1.0f,
	//	 0.0f,  0.0f, 1.0f, 1.0f,
	//	 0.0f,  0.0f, 1.0f, 1.0f,
	//	 0.0f,  0.0f, 1.0f, 1.0f,
	//};

	//square1 = new Square(vertexCol1);
	//square1->Scale(100, 100);
	//square1->Translate(200, 257 / 2);

	//square2 = new Square(vertexCol2);
	//square2->Scale(100, 100);
	//square2->Translate(512 - 200, 257 / 2);

	isMovingForward = false;
	isMovingBackward = false;
	isMovingLeft = false;
	isMovingRight = false;
}

void Game::DeInit()
{
	if (sonic != nullptr)
	{
		delete sonic;
		sonic = nullptr;
	}

	if (cartel != nullptr)
	{
		delete cartel;
		cartel = nullptr;
	}

	if (background != nullptr)
	{
		delete background;
		background = nullptr;
	}

	if (sonicIdleAnim != nullptr)
	{
		delete sonicIdleAnim;
		sonicIdleAnim = nullptr;
	}

	if (sonicRunAnim != nullptr)
	{
		delete sonicIdleAnim;
		sonicIdleAnim = nullptr;
	}

	if (cartelAnim != nullptr)
	{
		delete sonicIdleAnim;
		sonicIdleAnim = nullptr;
	}

	if (square1 != nullptr)
	{
		delete square1;
		square1 = nullptr;
	}

	if (square2 != nullptr)
	{
		delete square2;
		square2 = nullptr;
	}
}

void Game::Update()
{	
	static_cast<Sprite*>(cartel)->UpdateFrame(0);

	#pragma region Input

	if (IsKeyPressed(KEY_W))
	{
		moveVectorPlayer1.y = 1;
		isMovingForward = true;
		isMovingBackward = false;
		isMovingLeft = false;
		isMovingRight = false;
	}
	else if (IsKeyPressed(KEY_S))
	{
		moveVectorPlayer1.y = -1;
		isMovingForward = false;
		isMovingBackward = true;
		isMovingLeft = false;
		isMovingRight = false;
	}
	else
	{
		moveVectorPlayer1.y = 0;
	}

	if (IsKeyPressed(KEY_A))
	{
		moveVectorPlayer1.x = -1;	
		isMovingForward = false;
		isMovingBackward = false;
		isMovingLeft = true;
		isMovingRight = false;
	}
	else if (IsKeyPressed(KEY_D))
	{
		moveVectorPlayer1.x = 1;	
		isMovingForward = false;
		isMovingBackward = false;
		isMovingLeft = false;
		isMovingRight = true;
	}
	else
	{
		moveVectorPlayer1.x = 0;
	}
	
	if (IsKeyPressed(KEY_Q))
		sonic->Rotate(defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_E))
		sonic->Rotate(-defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_X))
		scaleVectorPlayer1 = 1;
	else if (IsKeyPressed(KEY_Z))
		scaleVectorPlayer1 = -1;
	else
		scaleVectorPlayer1 = 0;

	#pragma endregion

	if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0)
	{
		static_cast<Sprite*>(sonic)->UpdateFrame(1);

		traslateX = moveVectorPlayer1.x * defaultTranslation.x * time->GetDeltaTime();
		traslateY = moveVectorPlayer1.y * defaultTranslation.y * time->GetDeltaTime();

		sonic->Translate(traslateX, traslateY);
		checkCollisions(sonic, cartel);
	}

	if (!scaleVectorPlayer1 == 0)
	{
		scaleX = scaleVectorPlayer1 * defaultScale.x * time->GetDeltaTime();
		scaleY = scaleVectorPlayer1 * defaultScale.y * time->GetDeltaTime();

		sonic->Scale(scaleX, scaleY);
		checkCollisions(sonic, cartel);
	}

	if (!isMovingForward && !isMovingBackward && !isMovingLeft && !isMovingRight)
	{
		static_cast<Sprite*>(sonic)->UpdateFrame(0);
	}

	static_cast<Sprite*>(background)->Draw();
	static_cast<Sprite*>(cartel)->Draw();
	static_cast<Sprite*>(sonic)->Draw();

	/*static_cast<Square*>(square1)->Draw();
	static_cast<Square*>(square2)->Draw();*/
}

void Game::checkCollisions(Entity2D* player1, Entity2D* player2)
{
	while (collisionManager->checkEntityToEntityCollision(player1, player2))
	{
		if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0 ||
			!moveVectorPlayer2.x == 0 || !moveVectorPlayer2.y == 0)
			player1->Translate(-traslateX, -traslateY);

		if (!scaleVectorPlayer1 == 0 || !scaleVectorPlayer2 == 0)
			player1->Scale(-scaleX, -scaleY);
	}

	while (collisionManager->checkEntityToWindowCollision(player1, (Window*)window))
	{
		if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0 ||
			!moveVectorPlayer2.x == 0 || !moveVectorPlayer2.y == 0)
			player1->Translate(-traslateX, -traslateY);
		
		if (!scaleVectorPlayer1 == 0 || !scaleVectorPlayer2 == 0)
			player1->Scale(-scaleX, -scaleY);
	}
}