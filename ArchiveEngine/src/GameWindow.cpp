#include "pch.h"
#include "GameWindow.h"
#include "GLFWCode/GLFWImplementation.h"

namespace Archive
{

	void GameWindow::Init()
	{
		if (!mInstance)
			mInstance = std::unique_ptr<GameWindow>(new GameWindow);
	}

	std::unique_ptr<GameWindow>& GameWindow::GetWindow()
	{
		return mInstance;
	}

	void GameWindow::CreateWindow(int width, int height, std::string& windowName)
	{
		mInstance->mImplementation->CreateWindow(width, height, windowName);
	}

	void GameWindow::CreateWindow(int width, int height, std::string&& windowName)
	{
		mInstance->mImplementation->CreateWindow(width, height, std::move(windowName));
	}

	void GameWindow::SwapBuffers()
	{
		mInstance->mImplementation->SwapBuffers();
	}

	void GameWindow::PollEvents()
	{
		mInstance->mImplementation->PollEvents();
	}

	int GameWindow::GetWidth()
	{
		return mInstance->mImplementation->GetWidth();
	}

	int GameWindow::GetHeight()
	{
		return mInstance->mImplementation->GetHeight();
	}

	GameWindow::~GameWindow()
	{
		if (mImplementation != nullptr)
			delete mImplementation;
	}

	GameWindow::GameWindow()
	{
#ifdef ARCHIVE_GLFW
		mImplementation = new GLFWImplementation;
#else
		#ERROR_only_GLFW_is_supported
#endif // ARCHIVE_GLFW

	}
}