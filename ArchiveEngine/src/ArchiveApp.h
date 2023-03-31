#pragma once
#include "ArchiveUtil.h"

namespace Archive
{
	class ARCHIVE_API ArchiveApp
	{
	public:
		virtual void OnUpdate() = 0;

		void Run();

	private:

	};



}
