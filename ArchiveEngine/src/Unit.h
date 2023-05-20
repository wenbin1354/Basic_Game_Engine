#pragma once

#include "pch.h"
#include "Image.h"
#include "ArchiveUtil.h"
#include "RendererTypes.h"

namespace Archive
{
    class ARCHIVE_API Unit
    {
        public:
            Unit(const std::string& image, ScreenCoord coords);
            Unit(std::string&& image, ScreenCoord coords);

            int GetWidth() const;
            int GetHeight() const;

            ScreenCoord GetCoords() const;
            void SetCoords(ScreenCoord newCoords);
            void UpdateXCoord(int xAmount);
            void UpdateYCoord(int yAmount);

        private:
            Image mImage;
            ScreenCoord mPosition;
            friend class Renderer;
            friend ARCHIVE_API bool UnitsOverlap(const Unit& a, const Unit& b);
    };

    ARCHIVE_API bool UnitsOverlap(const Unit& a, const Unit& b);
}