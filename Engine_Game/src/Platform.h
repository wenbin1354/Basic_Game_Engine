#pragma once

#include "Archive.h"
#include "Player.h"

class Platform : public Archive::Unit
{
    public:
        Platform(Archive::ScreenCoord coords);

        bool IsPlayerOnPlatform(const Unit& player) const;
};