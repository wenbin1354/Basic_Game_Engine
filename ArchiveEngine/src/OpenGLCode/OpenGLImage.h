#pragma once

#include "pch.h"
#include "../ImplImage.h"

namespace Archive
{
    class OpenGLImage : public ImplImage
    {
    public:
        OpenGLImage(const std::string &imageFile);
        OpenGLImage(std::string &&imageFile);
        ~OpenGLImage();

        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        virtual void Activate() const override;

    private:
        int mWidth;
        int mHeight;
        unsigned int mTexture;
    };
}