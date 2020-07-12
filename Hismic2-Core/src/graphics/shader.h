#pragma once

#include <GL/glew.h>
#include <utils/fileutils.h>

namespace hismic {
	namespace graphics {

		class Shader {
		private:
			GLuint shader;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void enable() const;
			void disable() const;

		};
	
	}
}