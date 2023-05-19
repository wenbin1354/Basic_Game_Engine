#include "pch.h"
#include "Shader.h"
#include "OpenGLCode/OpenGLShader.h"

namespace Archive
{
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef ARCHIVE_OPENGL
		mImplementation = std::unique_ptr<ImplShader>{ new OpenGLShader{ vertexFile, fragmentFile } };
#else 
		#ONLY_OPENGL_IS_IMPLEMENTED_AT_THE_MOMENT
#endif // ARCHIVE_OPENGL

	}

	Shader::Shader(std::string&& vertexFile, std::string&& fragmentFile)
	{
#ifdef ARCHIVE_OPENGL
		mImplementation = std::unique_ptr<ImplShader>{ new OpenGLShader{ std::move(vertexFile), std::move(fragmentFile) } };
#else 
		#ONLY_OPENGL_IS_IMPLEMENTED_AT_THE_MOMENT
#endif // ARCHIVE_OPENGL
	}

	void Shader::Activate()
	{
		mImplementation->Activate();
	}

	void Shader::Pass2FloatValues(const std::string& name, float value1, float value2)
	{
		mImplementation->Pass2FloatValues(name, value1, value2);
	}

	void Shader::Pass2FloatValues(std::string&& name, float value1, float value2)
	{
		mImplementation->Pass2FloatValues(name, value1, value2);
	}

}