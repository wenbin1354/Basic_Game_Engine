#pragma once

#include "pch.h"
#include "../ImplShader.h"

namespace Archive
{
	class OpenGLShader : public ImplShader
	{
	public:
		OpenGLShader(const std::string &vertexFile, const std::string &fragmentFile);
		OpenGLShader(std::string &&vertexFile, std::string &&fragmentFile);
		~OpenGLShader();

		virtual void Activate() override;

		virtual void Pass2FloatValues(const std::string &name, float value1, float value2) override;
		virtual void Pass2FloatValues(std::string &&name, float value1, float value2) override;

	private:
		unsigned int mProgram{0};
	};
}