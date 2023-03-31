#pragma once
#include "pch.h"

namespace Archive
{
	class WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, std::string& windowName) = 0;
		virtual void CreateWindow(int width, int height, std::string&& windowName) = 0;

		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

	private:


	};

}