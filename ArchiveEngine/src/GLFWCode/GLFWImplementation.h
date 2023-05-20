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

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) override;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) override;
		virtual void SetWindowCloseCallback(std::function<void()> callbackFunc) override;
		virtual ~GLFWImplementation();

	private:

		struct Callbacks
		{
			std::function<void(const KeyPressed&)> keyPressedFunc;
			std::function<void(const KeyReleased&)> keyReleasedFunc;
			std::function<void()> windowCloseFunc{[](){}};
		} mCallbacks;

		GLFWwindow* mWindow{ nullptr };
	};
}