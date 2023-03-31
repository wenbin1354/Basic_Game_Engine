#pragma once
#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace Archive
{
	class GLFWImplementation : public WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, std::string& windowName) override;
		virtual void CreateWindow(int width, int height, std::string&& windowName) override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

	private:
		GLFWwindow* mWindow{ nullptr };
	};
}