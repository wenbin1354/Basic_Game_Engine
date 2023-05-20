#pragma once

#include "Archive.h"

class Coin : public Archive::Unit
{
public:
    Coin(Archive::ScreenCoord coords);
};