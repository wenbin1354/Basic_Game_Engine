#include "Platform.h"

Platform::Platform(Archive::ScreenCoord coords)
    : Unit("../Assets/Images/platform.png", coords)
{
}

bool Platform::IsPlayerOnPlatform(const Unit& player) const
{
    int left_a = player.GetCoords().xCoord;
    int right_a = player.GetCoords().xCoord + player.GetWidth();
    int left_b = GetCoords().xCoord + 15;
    int right_b = GetCoords().xCoord + GetWidth() - 15;
    bool x_intersection = (left_a <= left_b && left_b <= right_a) || (left_b <= left_a && left_a <= right_b);

    int bot_a = player.GetCoords().yCoord;
    int top_a = player.GetCoords().yCoord + player.GetHeight();
    int bot_b = GetCoords().yCoord;
    int top_b = GetCoords().yCoord + GetHeight();
    bool y_intersection = (bot_a <= bot_b && bot_b <= top_a) || (bot_b <= bot_a && bot_a <= top_b);

    int playerCeiling = player.GetCoords().yCoord - 5;
    bool playerAbovePlatform = playerCeiling >= GetCoords().yCoord;

    return x_intersection && y_intersection && playerAbovePlatform;
}
