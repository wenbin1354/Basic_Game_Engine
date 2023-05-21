#include "Archive.h"
#include "src/Coin.h"
#include "src/Platform.h"
#include "src/Player.h"
#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <time.h>

class Engine_Game_App : public Archive::ArchiveApp
{
public:
	Engine_Game_App()
	{
		SetKeyPressedCallback([this](const Archive::KeyPressed &e)
							  { MyKeyPressedFunc(e); });
		SetKeyReleasedCallback([this](const Archive::KeyReleased &e)
							   { MyKeyReleasedFunc(e); });
		RandomizePosition();
	}

	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(background, {0, 0});
		renderer.Draw(floor, {0, 0});
		renderer.Draw(goal);

		renderer.Draw(platform1);
		renderer.Draw(player);

		if(platform1.IsPlayerOnPlatform(player))
		{
			playerGroundLevel = platform1.GetCoords().yCoord+12;

		}
		else if(!platform1.IsPlayerOnPlatform(player) && !isJumping)
		{
			playerGroundLevel = groundLevel;
			jumpVelocity = fallingVelocity;
			isJumping = true;	
		}
		else
		{
			playerGroundLevel = groundLevel;
		}

		for (auto &coin : coins)
		{
			if (coin.second)
			{
				renderer.Draw(*coin.first);
			}
		}

		CheckCoinCollision(player);

		if (isRightPressed)
		{
			player.UpdateXCoord(5);
		}
		if (isLeftPressed)
		{
			player.UpdateXCoord(-5);
		}

		if (isJumping)
		{
			player.Jump(jumpVelocity, gravity, playerGroundLevel, isJumping);
		}

		if(mGameState == GameState::GameOver)
		{
			renderer.Draw(endScreen, {450, 250});
			if(isResetPressed)
			{
				isResetPressed = false;
				ChangeGameState(GameState::Start);
			}
		}

		// if goal overlaps player
		if(Archive::UnitsOverlap(player, goal))
		{
			ChangeGameState(GameState::GameOver);
		}
	}

	void MyKeyPressedFunc(const Archive::KeyPressed &e)
	{
		if (e.GetKeyCode() == ARCHIVE_KEY_RIGHT || e.GetKeyCode() == ARCHIVE_KEY_D)
		{
			isRightPressed = true;
		}
		if (e.GetKeyCode() == ARCHIVE_KEY_LEFT || e.GetKeyCode() == ARCHIVE_KEY_A)
		{
			isLeftPressed = true;
		}
		else if (e.GetKeyCode() == ARCHIVE_KEY_UP || e.GetKeyCode() == ARCHIVE_KEY_W || e.GetKeyCode() == ARCHIVE_KEY_SPACE)
		{
	
			if (!isJumping)
			{
				jumpVelocity = initialJumpVelocity;
				isJumping = true;
			}
		}
		if(e.GetKeyCode() == ARCHIVE_KEY_R)
		{
			isResetPressed = true;
		}
	}

	void MyKeyReleasedFunc(const Archive::KeyReleased &e)
	{
		if (e.GetKeyCode() == ARCHIVE_KEY_RIGHT || e.GetKeyCode() == ARCHIVE_KEY_D)
		{
			isRightPressed = false;
		}
		if (e.GetKeyCode() == ARCHIVE_KEY_LEFT || e.GetKeyCode() == ARCHIVE_KEY_A)
		{
			isLeftPressed = false;
		}
	}

	void RandomizePosition()
	{
		// reset player position
		player.SetCoords({100, 100});

		// Clear the existing coins
		coins.clear();
		coinsPosition.clear();

		std::srand(static_cast<unsigned int>(std::time(nullptr)));

		std::unique_ptr<Coin> coin = std::make_unique<Coin>(Archive::ScreenCoord{500, groundLevel + 280});
		coins[std::move(coin)] = true;
		
		int randomX = 0;
		coinsPosition.push_back(500);
		// Add coins to the map
		for (int i = 0; i < maxCoins - 1; i++)
		{
			do
			{
				randomX = (std::rand() % (Archive::GameWindow::GetWidth() - 200)) + 100;
			} while (randomX >= platform1.GetCoords().xCoord && randomX <= platform1.GetCoords().xCoord + platform1.GetWidth() && randomX >= coinsPosition[i] - 80 && randomX <= coinsPosition[i] + 80);
			
			coin = std::make_unique<Coin>(Archive::ScreenCoord{randomX, 200});
			coins[std::move(coin)] = true;
			coinsPosition.push_back(randomX);
		}

		ChangeGameState(GameState::Playing);
	}

	void CheckCoinCollision(Player &player)
	{
		for (auto &coin : coins)
		{
			if (Archive::UnitsOverlap(player, *coin.first))
			{
				coin.second = false;
			}
		}
	}

private:
	Archive::Renderer renderer;
	const int groundLevel{100};
	int playerGroundLevel{100};

	Archive::Image background{"../Assets/Images/background.png"};
	Archive::Image floor{"../Assets/Images/floor.png"};
	Archive::Image endScreen{"../Assets/Images/endscreen.png"};

	Archive::Unit goal{"../Assets/Images/goal.png", {Archive::GameWindow::GetWidth()-150 , groundLevel}};
	Player player{"../Assets/Images/player.png", {playerGroundLevel, 100}};

	Platform platform1{{500, 200}};

	std::unordered_map<std::unique_ptr<Coin>, bool> coins;
	std::vector<int> coinsPosition;
	int maxCoins{4};

	bool isRightPressed{false};
	bool isLeftPressed{false};
	bool isResetPressed{false};

	bool isJumping{false};
	int jumpVelocity{0};
	const int initialJumpVelocity{15};
	const int fallingVelocity{0};
	const int gravity{1};

	bool mGameOver{false};


	enum class GameState
	{
		Start,
		Playing,
		GameOver
	};

	GameState mGameState{GameState::Start};

	void ChangeGameState(GameState newState)
	{
		mGameState = newState;
		switch(newState)
		{
			case GameState::Start:
				RandomizePosition();
				break;
			case GameState::Playing:
				break;
			case GameState::GameOver:
				break;
		}
	};
};

ARCHIVE_GAME_START(Engine_Game_App);