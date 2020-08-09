#pragma once
#include "renderer2d.h"


namespace hismic {
	namespace graphics {
#define RENDERER_MAX_SPRITES    10000
#define RENDERER_VERTEX_SIZE    sizeof(VertexData)
#define RENDERER_SPRITE_SIZE    RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE    RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE 	RENDERER_MAX_SPRITES * 6

		class BatchRenderer2D : public Renderer2D{
		private:
			VertexArray m_VAO;
			IndexBuffer* m_IBO; // 60 000
			GLsizei m_IndexCount;
			GLuint m_VBO;
			
		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void submit(const Renderable2D* renderable) override;
		    void flush() override;
		private:
			void init();
		};
	}
}
