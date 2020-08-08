#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"
#include <maths/maths.h>

namespace hismic {
	namespace graphics {
		class Renderable2D {
		protected:
			maths::vec3 m_Position;
			maths::vec2 m_Size;
			maths::vec4 m_Color;

			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
		protected:
			Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color) 
				: m_Position(position),m_Size(size),m_Color(color)
			{
				m_VertexArray = new VertexArray();
				GLfloat vertices[] = {
					0,0,0,
					0,position.y,0,
					position.x,position.y,0,
					position.x,0,0

				};
				GLfloat colors[] = {
					color.x,color.y,color.z,color.w,
					color.x,color.y,color.z,color.w,
					color.x,color.y,color.z,color.w,
					color.x,color.y,color.z,color.w
				};
				m_VertexArray->addBuffers(new Buffer(vertices,4*3,3),0);
				m_VertexArray->addBuffers(new Buffer(colors, 4 * 4, 4), 1);

				GLushort indices[] = {0,1,2,2,3,0};
				m_IndexBuffer = new IndexBuffer(indices,6);
			}
			virtual ~Renderable2D()
			{
				delete m_VertexArray;
				delete m_IndexBuffer;
			}
			inline const maths::vec3& getPosition() const { return m_Position; }
			inline const maths::vec2& getSize() const { return m_Size; }
			inline const maths::vec4& getColor() const { return m_Color; }
	  };

	}
}
