#include "pch.h"

#include "GLFWImplementation.h"
#include "GLFW/glfw3.h"

namespace Archive
{
	void GLFWImplementation::CreateWindow(int width, int height, std::string& windowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);
	}

	void GLFWImplementation::CreateWindow(int width, int height, std::string&& windowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);
	}


	void GLFWImplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}

	void GLFWImplementation::PollEvents()
	{
		glfwPollEvents();
	}


	int GLFWImplementation::GetWidth() const
	{
		return 0;
	}

	int GLFWImplementation::GetHeight() const
	{
		return 0;
	}
}
