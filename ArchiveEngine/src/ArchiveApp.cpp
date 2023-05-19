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
	void ArchiveApp::Run()
	{
		Renderer renderer;

		////// Texture //////

		Image image{"../Assets/Images/arona.png"};
		image.Activate();

		/// Shader ///

		Shader sProgram{"../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl"};
		sProgram.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		mNextFrameTime = std::chrono::steady_clock::now();

		while(true)
		{
			renderer.Clear();
			renderer.Draw(image, {200, 100});

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			GameWindow::SwapBuffers();
			GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}

}
