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
	windowWidth = 1920;
	windowHeight = 1080;

	OnStart(1920, 1080, "Game");

	traslateX = 0.f;
	traslateY = 0.f;
	
	defaultTranslation.x = 150.0f;
	defaultTranslation.y = 150.0f; 

	defaultRotation = 10.0f;

	defaultScale.x = 10.0f;
	defaultScale.y = 10.0f;

	int sonicSpriteSheetWidth = 830;
	int sonicSpriteSheetHeight = 465;
	

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

	sonic = new Sprite("res/Sonic_Mania_Sprite_Sheet.png", 12, sonicIdleFrames.at(0));
	sonic->Scale(35, 35);
	sonic->Translate(100.0f, 200.0f);

	sonicIdleAnim = new Animation(3, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicIdleFrames);
	sonicRunAnim = new Animation(0.8, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicRunFrames);

	static_cast<Sprite*>(sonic)->AddAnimation(sonicIdleAnim);
	static_cast<Sprite*>(sonic)->AddAnimation(sonicRunAnim);

	level1TileMap = new TileMap();
	if (!level1TileMap->ImportTileMap("res/Dungeon/dungeon.tmx")) {
		std::cout << "Fallo al cargar mapa" << std::endl;
	}
	
	isMovingForward1 = false;
	isMovingBackward1 = false;
	isMovingLeft1 = false;
	isMovingRight1 = false;

	isMovingForward2 = false;
	isMovingBackward2 = false;
	isMovingLeft2 = false;
	isMovingRight2 = false;
}

void Game::DeInit()
{
	if (sonic != nullptr)
	{
		delete sonic;
		sonic = nullptr;
	}

	if (level1TileMap != nullptr)
	{
		delete level1TileMap;
		level1TileMap = nullptr;
	}
}

void Game::Update()
{
	float rawDltaTime = time->GetDeltaTime();
	float deltaTime = (rawDltaTime > 0.05f) ? 0.05f : rawDltaTime;

	// Apply gravity
	// If not grounded, fall velocity increases
	verticalVelocity -= gravity * deltaTime;
	// Speed limit
	if (verticalVelocity < -1000.0f) verticalVelocity = -1000.0f;

	// Move player in Y
	float moveY = verticalVelocity * deltaTime;
	sonic->Translate(0, moveY);
    
	// Reset floor state before checking
	isGrounded = false; 

	// Check collisions (This fixes position if player goes through ground)
	level1TileMap->CheckCollision(sonic, &verticalVelocity, &isGrounded);
	
	#pragma region Input Player 1

	if (IsKeyPressed(KEY_A))
	{
		moveVectorPlayer1.x = -1;	
		isMovingForward1 = false;
		isMovingBackward1 = false;
		isMovingLeft1 = true;
		isMovingRight1 = false;
	}
	else if (IsKeyPressed(KEY_D))
	{
		moveVectorPlayer1.x = 1;	
		isMovingForward1 = false;
		isMovingBackward1 = false;
		isMovingLeft1 = false;
		isMovingRight1 = true;
	}
	else
	{
		moveVectorPlayer1.x = 0;
		isMovingLeft1 = false;
		isMovingRight1 = false;
	}
	
	if (IsKeyPressed(KEY_Q))
		sonic->Rotate(defaultRotation * deltaTime);

	if (IsKeyPressed(KEY_E))
		sonic->Rotate(-defaultRotation * deltaTime);

	if (IsKeyPressed(KEY_X))
		scaleVectorPlayer1 = 1;
	else if (IsKeyPressed(KEY_Z))
		scaleVectorPlayer1 = -1;
	else
		scaleVectorPlayer1 = 0;

	if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0)
	{
		static_cast<Sprite*>(sonic)->UpdateFrame(1);

		traslateX = moveVectorPlayer1.x * defaultTranslation.x * deltaTime;
		traslateY = moveVectorPlayer1.y * defaultTranslation.y * deltaTime;

		sonic->Translate(traslateX, traslateY);
	}

	if (!scaleVectorPlayer1 == 0)
	{
		scaleX = scaleVectorPlayer1 * defaultScale.x * deltaTime;
		scaleY = scaleVectorPlayer1 * defaultScale.y * deltaTime;

		sonic->Scale(scaleX, scaleY);
	}

	if (!isMovingForward1 && !isMovingBackward1 && !isMovingLeft1 && !isMovingRight1)
	{
		static_cast<Sprite*>(sonic)->UpdateFrame(0);
	}

	#pragma endregion

	if (IsKeyJustReleased(KEY_O))
	{
		debugCollisionSquares = !debugCollisionSquares;
	}
	
	checkCollisionsWithWindow(sonic);
	
	level1TileMap->Draw(debugCollisionSquares);
	static_cast<Sprite*>(sonic)->Draw();
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
}

void Game::checkCollisionsWithWindow(Entity2D* player1)
{
	while (collisionManager->checkEntityToWindowCollision(player1, (Window*)window))
	{
		if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0 ||
			!moveVectorPlayer2.x == 0 || !moveVectorPlayer2.y == 0)
			player1->Translate(-traslateX, -traslateY);
		
		if (!scaleVectorPlayer1 == 0 || !scaleVectorPlayer2 == 0)
			player1->Scale(-scaleX, -scaleY);
	}
}