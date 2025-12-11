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

	sonicIdleFrames.push_back(Frame(43, 74, sonicSpriteSheetHeight - 65, sonicSpriteSheetHeight - 24));
	sonicIdleFrames.push_back(Frame(74, 105, sonicSpriteSheetHeight - 65, sonicSpriteSheetHeight - 24));
	sonicIdleFrames.push_back(Frame(105, 137, sonicSpriteSheetHeight - 65, sonicSpriteSheetHeight - 24));
	sonicIdleFrames.push_back(Frame(137, 169, sonicSpriteSheetHeight - 65, sonicSpriteSheetHeight - 24));
	sonicIdleFrames.push_back(Frame(169, 199, sonicSpriteSheetHeight - 65, sonicSpriteSheetHeight - 24));
	sonicIdleFrames.push_back(Frame(199, 230, sonicSpriteSheetHeight - 65, sonicSpriteSheetHeight - 24));
	sonicIdleFrames.push_back(Frame(230, 260, sonicSpriteSheetHeight - 65, sonicSpriteSheetHeight - 24));
	sonicIdleFrames.push_back(Frame(22, 54, sonicSpriteSheetHeight - 112, sonicSpriteSheetHeight - 73));
	sonicIdleFrames.push_back(Frame(54, 82, sonicSpriteSheetHeight - 112, sonicSpriteSheetHeight - 73));
	sonicIdleFrames.push_back(Frame(82, 115, sonicSpriteSheetHeight - 112, sonicSpriteSheetHeight - 73));
	sonicIdleFrames.push_back(Frame(115, 150, sonicSpriteSheetHeight - 112, sonicSpriteSheetHeight - 73));
	sonicIdleFrames.push_back(Frame(150, 180, sonicSpriteSheetHeight - 112, sonicSpriteSheetHeight - 73));

	sonicRunFrames.push_back(Frame(276, 304, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(304, 335, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(335, 377, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(377, 417, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(417, 455, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(455, 490, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(490, 520, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(520, 555, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(555, 593, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(593, 634, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(642, 672, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));
	sonicRunFrames.push_back(Frame(672, 705, sonicSpriteSheetHeight - 159, sonicSpriteSheetHeight - 117));

	sonicSprintFrames.push_back(Frame(285, 317, sonicSpriteSheetHeight - 206, sonicSpriteSheetHeight - 170));
	sonicSprintFrames.push_back(Frame(321, 353, sonicSpriteSheetHeight - 206, sonicSpriteSheetHeight - 170));
	sonicSprintFrames.push_back(Frame(359, 391, sonicSpriteSheetHeight - 206, sonicSpriteSheetHeight - 170));
	sonicSprintFrames.push_back(Frame(398, 427, sonicSpriteSheetHeight - 206, sonicSpriteSheetHeight - 170));
	sonicSprintFrames.push_back(Frame(437, 468, sonicSpriteSheetHeight - 206, sonicSpriteSheetHeight - 170));
	sonicSprintFrames.push_back(Frame(476, 508, sonicSpriteSheetHeight - 206, sonicSpriteSheetHeight - 170));
	sonicSprintFrames.push_back(Frame(517, 549, sonicSpriteSheetHeight - 206, sonicSpriteSheetHeight - 170));
	sonicSprintFrames.push_back(Frame(555, 584, sonicSpriteSheetHeight - 206, sonicSpriteSheetHeight - 170));

	sonicJumpFrames.push_back(Frame(51, 83, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 175));
	sonicJumpFrames.push_back(Frame(90, 124, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 175));
	sonicJumpFrames.push_back(Frame(139, 170, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 173));
	sonicJumpFrames.push_back(Frame(185, 215, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 171));
	sonicJumpFrames.push_back(Frame(230, 259, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 172));
	sonicJumpFrames.push_back(Frame(200, 225, sonicSpriteSheetHeight - 267, sonicSpriteSheetHeight - 223));
	sonicJumpFrames.push_back(Frame(155, 190, sonicSpriteSheetHeight - 266, sonicSpriteSheetHeight - 222));
	sonicJumpFrames.push_back(Frame(200, 225, sonicSpriteSheetHeight - 267, sonicSpriteSheetHeight - 223));
	sonicJumpFrames.push_back(Frame(230, 259, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 172));
	sonicJumpFrames.push_back(Frame(185, 215, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 171));
	sonicJumpFrames.push_back(Frame(139, 170, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 173));
	sonicJumpFrames.push_back(Frame(90, 124, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 175));
	sonicJumpFrames.push_back(Frame(51, 83, sonicSpriteSheetHeight - 213, sonicSpriteSheetHeight - 175));
	
	sonic = new Sprite("res/Sonic_Mania_Sprite_Sheet.png", sonicIdleFrames.at(0));
	sonic->Scale(32, 32);
	sonic->Translate(100.0f, 200.0f);

	sonicIdleAnim = new Animation(3, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicIdleFrames);
	sonicRunAnim = new Animation(0.4f, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicRunFrames);
	sonicSprintAnim = new Animation(0.2f, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicSprintFrames);

	sonicJumpAnim = new Animation(1.0f, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicJumpFrames);
	sonicJumpAnim->SetFrameDuration(0, 0.03f);
	sonicJumpAnim->SetFrameDuration(1, 0.03f);
	sonicJumpAnim->SetFrameDuration(2, 0.03f);
	sonicJumpAnim->SetFrameDuration(3, 0.03f);
	sonicJumpAnim->SetFrameDuration(4, 0.03f);
	sonicJumpAnim->SetFrameDuration(5, 0.03f);
	sonicJumpAnim->SetFrameDuration(6, 0.7f);
	
	static_cast<Sprite*>(sonic)->AddAnimation(sonicIdleAnim);
	static_cast<Sprite*>(sonic)->AddAnimation(sonicRunAnim);
	static_cast<Sprite*>(sonic)->AddAnimation(sonicSprintAnim);
	static_cast<Sprite*>(sonic)->AddAnimation(sonicJumpAnim);
	
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

	if (IsKeyJustReleased(KEY_SPACE) && isGrounded)
	{
		verticalVelocity = jumpForce; // Instant upwards impulse
		isGrounded = false; // Inmediately fly
	}
	
	// Move player in Y
	float moveY = verticalVelocity * deltaTime;
	sonic->Translate(0, moveY);
    
	// Reset floor state before checking
	//isGrounded = false; 

	level1TileMap->SetPlayerHorizontalVelocity(horizontalVelocity);
	// Check collisions (This fixes position if player goes through ground)
	level1TileMap->CheckCollision(sonic, &verticalVelocity, &isGrounded);

	Vector2 pos   = sonic->GetTranslation();
	Vector2 scale = sonic->GetScale();

	float halfW = std::abs(scale.x) / 2.0f;
	float halfH = std::abs(scale.y) / 2.0f;

	// World bounds (mainly for window collision check)
	float worldMinX = 0.0f;
	float worldMaxX = level1TileMap->GetWorldWidth() - sonic->GetScale().x;

	// Left-hand side of window
	if (pos.x - halfW < worldMinX)
	{
		pos.x = worldMinX + halfW;
		horizontalVelocity = 0;
	}

	// Right-hand side of window
	if (pos.x + halfW > worldMaxX)
	{
		pos.x = worldMaxX - halfW;
		horizontalVelocity = 0;
	}

	// Bottom side of window (extra protection layer)
	float worldMinY = 0.0f;
	if (pos.y - halfH < worldMinY)
	{
		pos.y = worldMinY + halfH;
		verticalVelocity = 0;
		isGrounded = true;
	}

	sonic->SetTranslation(pos.x, pos.y);
	
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

	// --- Compute horizontal speed with inertia ---
	if (moveVectorPlayer1.x != 0) 
	{
		// Accelerate in pressed direction
		horizontalVelocity += moveVectorPlayer1.x * acceleration * deltaTime;
    
		// Limit horizontal velocity to max speed sprint
		if (horizontalVelocity > maxSpeedSprint) horizontalVelocity = maxSpeedSprint;
		if (horizontalVelocity < -maxSpeedSprint) horizontalVelocity = -maxSpeedSprint;
	}
	else 
	{
		// Friction (gradual stop)
		if (horizontalVelocity > 0) 
		{
			horizontalVelocity -= friction * deltaTime;
			if (horizontalVelocity < 0) horizontalVelocity = 0; // Full stop
		}
		else if (horizontalVelocity < 0) 
		{
			horizontalVelocity += friction * deltaTime;
			if (horizontalVelocity > 0) horizontalVelocity = 0; // Full stop
		}
	}

	// --- Apply movement ---

	if (horizontalVelocity != 0)
	{
		float moveX = horizontalVelocity * deltaTime;
		sonic->Translate(moveX, 0);
    
		// FLIP (Look left/right according to real speed, not input)
		if (horizontalVelocity > 0) sonic->SetScale(32, 32);  
		if (horizontalVelocity < 0) sonic->SetScale(-32, 32); 
	}

	// --- (ANIMATION STATE MACHINE) ---
    
	int currentAnimIndex; // By default Idle (0)

	if (!isGrounded) 
	{
		// Flying state has max priority
		currentAnimIndex = 3;
	}
	else if (abs(horizontalVelocity) > 20.0f) // Any movement detected
	{
		if (abs(horizontalVelocity) > maxSpeedRun) 
		{
			currentAnimIndex = 2; // Sprint (hight speed)
		}
		else 
		{
			currentAnimIndex = 1; // Run (medium speed)
		}
	}
	else 
	{
		currentAnimIndex = 0; // Idle
	}

	// Update correct animation
	static_cast<Sprite*>(sonic)->UpdateFrame(currentAnimIndex);

	#pragma endregion

	if (IsKeyJustReleased(KEY_O))
	{
		debugCollisionSquares = !debugCollisionSquares;
	}
	
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