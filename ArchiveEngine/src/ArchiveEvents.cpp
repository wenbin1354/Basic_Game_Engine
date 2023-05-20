#include "pch.h"
#include "ArchiveEvents.h"

namespace Archive
{
    KeyPressed::KeyPressed(int keyCode)
        : mKeyCode(keyCode)
    {
    }

    int KeyPressed::GetKeyCode() const
    {
        return mKeyCode;
    }

    KeyReleased::KeyReleased(int keyCode)
        : mKeyCode(keyCode)
    {
    }

    int KeyReleased::GetKeyCode() const
    {
        return mKeyCode;
    }
}