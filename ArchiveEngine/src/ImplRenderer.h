#pragma once

#include "Shader.h"
#include "Image.h"
#include "RendererTypes.h"

namespace Archive
{
    class ImplRenderer
    {
    public:
        virtual void Draw(Image &image,
                          TextureBox texCoords,
                          Shader &shader,
                          ScreenCoord coords) = 0;
    
        virtual void Clear() = 0;
    };
}