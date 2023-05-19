#include "pch.h"
#include "Image.h"
#include "OpenGLCode/OpenGLImage.h"

namespace Archive
{
    Image::Image(const std::string &imageFile)
    {
#ifdef ARCHIVE_OPENGL
        mImplementation = std::unique_ptr<ImplImage>{new OpenGLImage{imageFile}};
#else
        #ONLY_OPENGL_IS_IMPLEMENTED_AT_THE_MOMENT
#endif // ARCHIVE_OPENGL
    }

    Image::Image(std::string &&imageFile)
    {
#ifdef ARCHIVE_OPENGL
        mImplementation = std::unique_ptr<ImplImage>{new OpenGLImage{std::move(imageFile)}};
#else
        #ONLY_OPENGL_IS_IMPLEMENTED_AT_THE_MOMENT
#endif // ARCHIVE_OPENGL
    }

    int Image::GetWidth() const
    {
        return mImplementation->GetWidth();
    }

    int Image::GetHeight() const
    {
        return mImplementation->GetHeight();
    }

    void Image::Activate()
    {
        mImplementation->Activate();
    }
}