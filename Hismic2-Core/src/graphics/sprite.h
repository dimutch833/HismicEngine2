#pragma once
#include <graphics/renderable2d.h>


namespace hismic {
	namespace graphics {

		class Sprite : public Renderable2D {
		private:

		public:
			Sprite(float x, float y, float width, float height, const maths::vec4& color, Shader& shader);
		};
	}
}