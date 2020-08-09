#include "BatchRenderer2D.h"

namespace hismic {
	namespace graphics {
		BatchRenderer2D::BatchRenderer2D() {
			init();
		}
		BatchRenderer2D::~BatchRenderer2D()
		{
			delete m_IBO;
			glDeleteBuffers(1, &m_VBO);
		}
		void BatchRenderer2D::submit(const Renderable2D* renderable)
		{
		}
		void BatchRenderer2D::flush()
		{
		}
		void BatchRenderer2D::init()
		{
			glGenBuffers(1,&m_VBO);
			glBindBuffer(GL_ARRAY_BUFFER,m_VBO);
			glBufferData(GL_ARRAY_BUFFER,RENDERER_BUFFER_SIZE,NULL,GL_DYNAMIC_DRAW);
		}
	}
}
