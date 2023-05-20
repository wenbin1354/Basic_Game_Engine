#pragma once

#include "pch.h"
#include "ArchiveUtil.h"
#include "ArchiveEvents.h"

constexpr int FPS{60};

namespace Archive
{
	class ARCHIVE_API ArchiveApp
	{
	public:
		ArchiveApp();
		virtual void OnUpdate() = 0;

		void Run();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

	private:
		std::chrono::milliseconds mFrameDuration{std::chrono::milliseconds{1000} / FPS};

		std::chrono::steady_clock::time_point mNextFrameTime{std::chrono::steady_clock::now()};

		bool mGameWindowShouldClose{false};

		void DefaultWindowCloseHandler();
	};

}
