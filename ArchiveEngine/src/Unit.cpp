#include "pch.h"
#include "Unit.h"

namespace Archive
{
    Unit::Unit(const std::string& image, ScreenCoord coords)
        : mImage{image}, mPosition{coords}
    {
    }

    Unit::Unit(std::string&& image, ScreenCoord coords)
        : mImage{std::move(image)}, mPosition{coords}
    {
    }

    int Unit::GetWidth() const
    {
        return mImage.GetWidth();
    }

    int Unit::GetHeight() const
    {
        return mImage.GetHeight();
    }

    ScreenCoord Unit::GetCoords() const
    {
        return mPosition;
    }

    void Unit::SetCoords(ScreenCoord newCoords)
    {
        mPosition = newCoords;
    }

    void Unit::UpdateXCoord(int xAmount)
    {
        mPosition.xCoord += xAmount;
    }

    void Unit::UpdateYCoord(int yAmount)
    {
        mPosition.yCoord += yAmount;
    }

    ARCHIVE_API bool UnitsOverlap(const Unit& a, const Unit& b)
    {
        int left_a{a.mPosition.xCoord};
        int right_a{a.mPosition.xCoord + a.GetWidth()};
        int left_b{b.mPosition.xCoord};
        int right_b{b.mPosition.xCoord + b.GetWidth()};

        bool x_intersection{ (left_a <= left_b && left_b <= right_a) || (left_b <= left_a && left_a <= right_b ) };

        int bot_a{a.mPosition.yCoord};
        int top_a{a.mPosition.yCoord + a.GetHeight()};
        int bot_b{b.mPosition.yCoord};
        int top_b{b.mPosition.yCoord + b.GetHeight()};

        bool y_intersection{ (bot_a <= bot_b && bot_b <= top_a) || (bot_b <= bot_a && bot_a <= top_b) };
        
        return x_intersection && y_intersection;
    }
}