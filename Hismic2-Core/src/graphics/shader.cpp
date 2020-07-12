#include "shader.h"


namespace hismic {
	namespace graphics {
		Shader::Shader(const char* vertPath, const char* fragPath)
			: m_VertPath(vertPath),m_FragPath(fragPath)
		{
			m_ShaderID = load();
		}
		Shader::~Shader()
		{
			glDeleteProgram(m_ShaderID);
		}
		void Shader::enable() const
		{
			glUseProgram(m_ShaderID);
		}
		void Shader::disable() const
		{
			glUseProgram(0);
		}
		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = FileUtils::read_file(m_VertPath);
			std::string fragSourceString = FileUtils::read_file(m_FragPath);

			const char *vertSource = vertSourceString.c_str();
			const char *fragSource = fragSourceString.c_str();

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				m_Log.PrintLog(&error[0],4);
				glDeleteShader(vertex);
				return 0;
			}
			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				m_Log.PrintLog(&error[0], 5);
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}
	}
}
