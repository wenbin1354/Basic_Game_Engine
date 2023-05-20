#include "Player.h"

Player::Player(const std::string &image, Archive::ScreenCoord coords)
    : Unit(image, coords)
{
}

Player::Player(std::string &&image, Archive::ScreenCoord coords)
    : Unit(std::move(image), coords)
{
}

void Player::Jump(int& jumpVelocity, int gravity, int groundLevel, bool& isJumping)
{
    UpdateYCoord(jumpVelocity); // Apply the current jump velocity
    jumpVelocity -= gravity;    // Decrease the jump velocity due to gravity

    // Check if the player on ground level
    if (GetCoords().yCoord <= groundLevel)
    {
        isJumping = false;
        jumpVelocity = 0;                             // Reset the jump velocity
        SetCoords({GetCoords().xCoord, groundLevel}); // Snap the player to the ground level
    }
}