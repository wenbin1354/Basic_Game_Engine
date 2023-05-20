#include "Archive.h"
#include <iostream>

class Engine_Game_App : public Archive::ArchiveApp
{
public:
	Engine_Game_App()
	{
		SetKeyPressedCallback([this](const Archive::KeyPressed &e)
							  { MyKeyPressedFunc(e); });
		SetKeyReleasedCallback([this](const Archive::KeyReleased &e)
							   { MyKeyReleasedFunc(e); });
	}

	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(background, {0, 0});
		renderer.Draw(coin, {250, 250});
		renderer.Draw(floor, {0, 0});
		renderer.Draw(platform, {500, 200});

		renderer.Draw(player);
		renderer.Draw(player2);

		if (Archive::UnitsOverlap(player, player2))
		{
			std::cout << "Units overlap" << std::endl;
		}

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
			jump();
		}
	}

	void jump()
	{
		player.UpdateYCoord(jumpVelocity); // Apply the current jump velocity
		jumpVelocity -= gravity;		   // Decrease the jump velocity due to gravity

		// Check if the player on ground level
		if (player.GetCoords().yCoord <= groundLevel)
		{
			isJumping = false;
			jumpVelocity = 0;											// Reset the jump velocity
			player.SetCoords({player.GetCoords().xCoord, groundLevel}); // Snap the player to the ground level
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
			// Check if the player is on the ground or standing on a platform before allowing a jump
			if (!isJumping)
			{
				isJumping = true;
				jumpVelocity = initialJumpVelocity;
			}
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

private:
	Archive::Renderer renderer;

	Archive::Image background{"../Assets/Images/background.png"};
	Archive::Image coin{"../Assets/Images/coin.png"};
	Archive::Image floor{"../Assets/Images/floor.png"};
	Archive::Image platform{"../Assets/Images/platform.png"};
	Archive::Unit player{"../Assets/Images/player.png", {100, 100}};
	Archive::Unit player2{"../Assets/Images/arona.png", {400, 100}};

	bool isRightPressed{false};
	bool isLeftPressed{false};

	bool isJumping{false};
	int jumpVelocity{0};
	const int initialJumpVelocity{15};
	const int gravity{1};
	const int groundLevel{100};
};

ARCHIVE_GAME_START(Engine_Game_App);