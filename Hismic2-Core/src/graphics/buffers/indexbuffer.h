#pragma once

#include <GL/glew.h>

namespace hismic {
	namespace graphics {
		class IndexBuffer {
		private:
			GLuint m_BufferID;
			GLuint m_Count;
		public:
			IndexBuffer(GLushort* data, GLsizei count);

			void bind() const;
			void unbind() const;
			inline GLuint getCount() { return m_Count; }
		};
	}
}