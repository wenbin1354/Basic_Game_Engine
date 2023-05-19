#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"

namespace Archive
{
	
	OpenGLShader::OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile)
	{
		// vertex shader
		std::string vShader;
		std::ifstream vFile{ vertexFile };
		std::string line;
		while (std::getline(vFile, line))
		{
			vShader += line;
			vShader += "\n";
		}
		vFile.close();
		const char* cVShader = vShader.c_str();

		unsigned int vertex;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &cVShader, NULL);
		glCompileShader(vertex);
		
		int success;
		char infoLog[1024];
		
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: VERTEX \n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}


		// fragment shader
		std::string fShader;
		std::ifstream fFile { fragmentFile };
		while (std::getline(fFile, line))
		{
			fShader += line;
			fShader += "\n";
		}
		fFile.close();
		const char* cFShader = fShader.c_str();

		unsigned int fragment;
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &cFShader, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: FRAGMENT \n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}


		// shader Program
		mProgram = glCreateProgram();
		glAttachShader(mProgram, vertex);
		glAttachShader(mProgram, fragment);
		glLinkProgram(mProgram);

		glGetShaderiv(mProgram, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(mProgram, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: PROGRAM \n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
		// delete the shaders as they're linked into our program now and no longer necessary
		glDeleteShader(vertex);
		glDeleteShader(fragment);
		
	}

	OpenGLShader::OpenGLShader(std::string&& vertexFile, std::string&& fragmentFile)
	{
		// vertex shader
		std::string vShader;
		std::ifstream vFile { vertexFile };
		std::string line;
		while (std::getline(vFile, line))
		{
			vShader += line;
			vShader += "\n";
		}
		vFile.close();
		const char* cVShader = vShader.c_str();

		unsigned int vertex;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &cVShader, NULL);
		glCompileShader(vertex);

		int success;
		char infoLog[1024];

		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: VERTEX \n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}



		// fragment shader
		std::string fShader;
		std::ifstream fFile { fragmentFile };
		while (std::getline(fFile, line))
		{
			fShader += line;
			fShader += "\n";
		}
		fFile.close();
		const char* cFShader = fShader.c_str();

		unsigned int fragment;
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &cFShader, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: FRAGMENT \n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}

		// shader Program
		mProgram = glCreateProgram();
		glAttachShader(mProgram, vertex);
		glAttachShader(mProgram, fragment);
		glLinkProgram(mProgram);

		glGetShaderiv(mProgram, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(mProgram, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: PROGRAM \n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
		// delete the shaders as they're linked into our program now and no longer necessary
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(mProgram);
	}

	void OpenGLShader::Activate()
	{
		glUseProgram(mProgram);
	}

	void OpenGLShader::Pass2FloatValues(const std::string& name, float value1, float value2)
	{
		glUseProgram(mProgram);
		GLint location { glGetUniformLocation(mProgram, name.c_str()) };
		glUniform2f(location, value1, value2);
	}

	void OpenGLShader::Pass2FloatValues(std::string&& name, float value1, float value2)
	{
		glUseProgram(mProgram);
		GLint location { glGetUniformLocation(mProgram, name.c_str()) };
		glUniform2f(location, value1, value2);
	}

}