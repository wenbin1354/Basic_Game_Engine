#include "pch.h"
#include "ArchiveApp.h"
#include "ArchiveUtil.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Shader.h"
#include "Image.h"
#include "Renderer.h"
#include "GameWindow.h"

namespace Archive
{
	ArchiveApp::ArchiveApp()
	{
		GameWindow::Init();
		GameWindow::CreateWindow(1280, 720, "Coin Game");

		SetWindowCloseCallback([this]() { DefaultWindowCloseHandler(); });
	}


	void ArchiveApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose)
		{
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Archive::GameWindow::SwapBuffers();
			Archive::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}

	void ArchiveApp::SetKeyPressedCallback(std::function<void(const KeyPressed &)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}

	void ArchiveApp::SetKeyReleasedCallback(std::function<void(const KeyReleased &)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}

	void ArchiveApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GameWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void ArchiveApp::DefaultWindowCloseHandler()
	{
		mGameWindowShouldClose = true;
	}

}
