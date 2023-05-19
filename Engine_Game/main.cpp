#include "Archive.h"
#include <iostream>

class Engine_Game_App : public Archive::ArchiveApp
{
public:
	Engine_Game_App()
	{
		Archive::GameWindow::Init();
		Archive::GameWindow::CreateWindow(800, 600, "Test");
	}

	virtual void OnUpdate() override
	{
		
	}
};

ARCHIVE_GAME_START(Engine_Game_App);