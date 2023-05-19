#pragma once

namespace Archive
{
	class ImplShader
	{
	public:

		virtual void Activate() = 0;

		virtual void Pass2FloatValues(const std::string& name, float value1, float value2) = 0;
		virtual void Pass2FloatValues(std::string&& name, float value1, float value2) = 0;

		virtual ~ImplShader(){};
	private:

	};
}