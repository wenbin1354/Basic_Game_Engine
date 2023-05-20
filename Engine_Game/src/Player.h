#pragma once

#include "Archive.h"
#include "Platform.h"

class Player : public Archive::Unit
{
public:

    Player(const std::string& image, Archive::ScreenCoord coords);
    Player(std::string&& image, Archive::ScreenCoord coords);

    void Jump(int& jumpVelocity, int gravity, int groundLevel, bool& isJumping);
};