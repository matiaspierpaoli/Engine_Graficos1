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
#define KEY_SPACE 32

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

	float zoomX = 4.0f;
	float zoomY = 3.37f;
	
	OnStart(windowWidth, windowHeight, "Game", zoomX, zoomY);

	traslateX = 0.f;
	traslateY = 0.f;
	
	defaultTranslation.x = 150.0f;
	defaultTranslation.y = 150.0f; 

	defaultRotation = 10.0f;

	defaultScale.x = 10.0f;
	defaultScale.y = 10.0f;

	int battleCityAtlasWidth = 400;
	int battleCityAtlastHeight = 256;

	tankMoveUpFrames.push_back(Frame(1, 13, battleCityAtlastHeight - 174, battleCityAtlastHeight - 160));
	tankMoveUpFrames.push_back(Frame(18, 29, battleCityAtlastHeight - 175, battleCityAtlastHeight - 160));
	tankMoveLeftFrames.push_back(Frame(32, 46, battleCityAtlastHeight - 173, battleCityAtlastHeight - 161));
	tankMoveLeftFrames.push_back(Frame(48, 62, battleCityAtlastHeight - 173, battleCityAtlastHeight - 161));
	tankMoveDownFrames.push_back(Frame(65, 77, battleCityAtlastHeight - 175, battleCityAtlastHeight - 161));
	tankMoveDownFrames.push_back(Frame(81, 93, battleCityAtlastHeight - 175, battleCityAtlastHeight - 161));
	tankMoveRightFrames.push_back(Frame(97, 108, battleCityAtlastHeight - 173, battleCityAtlastHeight - 161));
	tankMoveRightFrames.push_back(Frame(113, 127, battleCityAtlastHeight - 173, battleCityAtlastHeight - 161));
	
	tank = new Sprite("res/Battle City/Battle City Atlas.png", tankMoveUpFrames.at(0));
	tank->Scale(16, 16);
	tank->Translate(20.0f, 50.0f);

	
	tankMoveUpAnim = new Animation(0.2f, battleCityAtlasWidth, battleCityAtlastHeight, tankMoveUpFrames);
	tankMoveLeftAnim = new Animation(0.2f, battleCityAtlasWidth, battleCityAtlastHeight, tankMoveLeftFrames);
	tankMoveDownAnim = new Animation(0.2f, battleCityAtlasWidth, battleCityAtlastHeight, tankMoveDownFrames);
	tankMoveRightAnim = new Animation(0.2f, battleCityAtlasWidth, battleCityAtlastHeight, tankMoveRightFrames);

	static_cast<Sprite*>(tank)->AddAnimation(tankMoveUpAnim);
	static_cast<Sprite*>(tank)->AddAnimation(tankMoveLeftAnim);
	static_cast<Sprite*>(tank)->AddAnimation(tankMoveDownAnim);
	static_cast<Sprite*>(tank)->AddAnimation(tankMoveRightAnim);
	
	level1TileMap = new TileMap(*collisionManager);
	if (!level1TileMap->ImportTileMap("res/Battle City/battle city.tmx")) {
		std::cout << "Fallo al cargar mapa" << std::endl;
	}

	bricksLayer = level1TileMap->FindLayerIndex("Bricks");
	treesLayer = level1TileMap->FindLayerIndex("Trees");
}

void Game::DeInit()
{
	if (tank != nullptr)
	{
		delete tank;
		tank = nullptr;
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

	int currentAnimIndex = -1; 

	// Check collisions (This fixes position if player goes through ground)
	level1TileMap->CheckCollision(tank, nullptr, nullptr);
	
	#pragma region Input Player 1

	if (IsKeyPressed(KEY_A))
	{
		moveVectorPlayer1.x = -1;	
	}
	else if (IsKeyPressed(KEY_D))
	{
		moveVectorPlayer1.x = 1;	
	}
	else
	{
		moveVectorPlayer1.x = 0;
	}
	
	if (IsKeyPressed(KEY_W))
	{
		moveVectorPlayer1.y = 1;	
	}
	else if (IsKeyPressed(KEY_S))
	{
		moveVectorPlayer1.y = -1;	
	}
	else
	{
		moveVectorPlayer1.y = 0;
	}
	
	if (IsKeyPressed(KEY_Q))
		tank->Rotate(defaultRotation * deltaTime);

	if (IsKeyPressed(KEY_E))
		tank->Rotate(-defaultRotation * deltaTime);

	if (IsKeyPressed(KEY_X))
		scaleVectorPlayer1 = 1;
	else if (IsKeyPressed(KEY_Z))
		scaleVectorPlayer1 = -1;
	else
		scaleVectorPlayer1 = 0;

	if (moveVectorPlayer1.x != 0) 
	{
		if (moveVectorPlayer1.x > 0)
			currentAnimIndex = TankDirections::Right;
		else if (moveVectorPlayer1.x < 0) 
			currentAnimIndex = TankDirections::Left;
	}
	
	if (moveVectorPlayer1.y != 0)
	{
		if (moveVectorPlayer1.y > 0) 
		{
			currentAnimIndex = TankDirections::Up;
		}
		else if (moveVectorPlayer1.y < 0) 
		{
			currentAnimIndex = TankDirections::Down;
		}
	}
	

	if (scaleVectorPlayer1 != 0)
	{
		float growthX = scaleVectorPlayer1 * defaultScale.x * time->GetDeltaTime();
		float growthY = scaleVectorPlayer1 * defaultScale.y * time->GetDeltaTime();
		tank->Scale(growthX, growthY);
	}
	
	// --- Apply movement ---

	if (moveVectorPlayer1.x != 0 || moveVectorPlayer1.y != 0)
	{
		float moveX = moveVectorPlayer1.x * defaultTranslation.x * deltaTime;
		float moveY = moveVectorPlayer1.y * defaultTranslation.y * deltaTime;
		tank->Translate(moveX, moveY);
	}
		
	// Update correct animation
	if (currentAnimIndex != -1)
		static_cast<Sprite*>(tank)->UpdateFrame(currentAnimIndex);

	#pragma endregion

	if (IsKeyJustReleased(KEY_O))
	{
		debugCollisionSquares = !debugCollisionSquares;
	}
	
	level1TileMap->DrawLayers(0, bricksLayer, debugCollisionSquares);
	static_cast<Sprite*>(tank)->Draw();
	level1TileMap->DrawLayers(treesLayer,level1TileMap->GetLayerCount(), debugCollisionSquares);
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