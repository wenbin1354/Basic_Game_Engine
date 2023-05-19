#pragma once

#include "pch.h"
#include "ArchiveUtil.h"
#include "ImplShader.h"

namespace Archive
{
	class ARCHIVE_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		Shader(std::string&& vertexFile, std::string&& fragmentFile);

		void Activate();

		void Pass2FloatValues(const std::string& name, float value1, float value2);
		void Pass2FloatValues(std::string&& name, float value1, float value2);

	private:
		std::unique_ptr<ImplShader> mImplementation;
	};
}