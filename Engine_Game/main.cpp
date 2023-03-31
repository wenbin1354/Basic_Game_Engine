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
		std::cout << "Gaming is running" << std::endl;
		Archive::GameWindow::SwapBuffers();
		Archive::GameWindow::PollEvents();
	}
};

ARCHIVE_GAME_START(Engine_Game_App);