#pragma once

#include <GL/glew.h>
#include <utils/fileutils.h>
#include <utils/Logger.h>
#include <vector>

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

			void enable() const;
			void disable() const;

		private:
			GLuint load();
		};
	
	}
}