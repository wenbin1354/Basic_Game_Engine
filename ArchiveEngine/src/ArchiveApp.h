#pragma once

#include "pch.h"
#include "ArchiveUtil.h"

constexpr int FPS{60};

namespace Archive
{
	class ARCHIVE_API ArchiveApp
	{
	public:
		virtual void OnUpdate() = 0;

		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{std::chrono::milliseconds{1000} / FPS };

		std::chrono::steady_clock::time_point mNextFrameTime{std::chrono::steady_clock::now()};
	};

}
