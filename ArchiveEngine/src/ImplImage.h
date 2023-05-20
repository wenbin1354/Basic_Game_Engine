#pragma once

namespace Archive
{
    class ImplImage
    {
    public:

        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        virtual void Activate() const = 0;

    private:
    
    };
}