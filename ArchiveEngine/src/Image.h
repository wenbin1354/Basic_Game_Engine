#pragma once

#include "pch.h"
#include "ArchiveUtil.h"
#include "ImplImage.h"

namespace Archive
{
	class ARCHIVE_API Image
	{
	public:
		Image(const std::string &imageFile);
		Image(std::string &&imageFile);

		int GetWidth() const;
		int GetHeight() const;
		void Activate() const;

	private:
		std::unique_ptr<ImplImage> mImplementation;
	};
}