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
			glGenVertexArrays(1,&m_VAO);
			glGenBuffers(1,&m_VBO);


			glBindVertexArray(m_VAO);
			glBindBuffer(GL_ARRAY_BUFFER,m_VBO);
			glBufferData(GL_ARRAY_BUFFER,RENDERER_BUFFER_SIZE,NULL,GL_DYNAMIC_DRAW);
			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);
			glVertexAttribPointer(SHADER_VERTEX_INDEX,3,GL_FLOAT,GL_FALSE,RENDERER_VERTEX_SIZE,(const GLvoid*)0);
			glVertexAttribPointer(SHADER_COLOR_INDEX,4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(3 * GL_FLOAT));
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}
