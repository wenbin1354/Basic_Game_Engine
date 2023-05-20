#pragma once

#include "ArchiveUtil.h"

namespace Archive
{
    class ARCHIVE_API KeyPressed
    {
    public:
        KeyPressed(int keyCode);
        int GetKeyCode() const;

    private:
        int mKeyCode;
    };

    class ARCHIVE_API KeyReleased
    {
    public:
        KeyReleased(int keyCode);
        int GetKeyCode() const;

    private:
        int mKeyCode;
    };

    class ARCHIVE_API WindowClosed
    {
        
    };
}