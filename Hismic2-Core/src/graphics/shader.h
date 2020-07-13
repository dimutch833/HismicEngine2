#pragma once

#include <GL/glew.h>
#include <utils/fileutils.h>
#include <utils/Logger.h>
#include <vector>
#include <maths/maths.h>

namespace hismic {
	namespace graphics {

		class Shader {
		private:
			GLuint m_ShaderID;
			const char *m_VertPath;
			const char *m_FragPath;
			Utils::Logger m_Log;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();


			void setUniform1i(const GLchar* name, int value);
			void setUniform1f(const GLchar* name, float value);
			void setUniform2f(const GLchar* name, const maths::vec2& vector);
			void setUniform3f(const GLchar* name, const maths::vec3& vector);
			void setUniform4f(const GLchar* name, const maths::vec4& vector);
			void setUniformMat4(const GLchar* name, const maths::mat4& matrix);

			void enable() const;
			void disable() const;

		private:
			GLint getUniformLocation(const GLchar* name);
			GLuint load();
		};
	
	}
}