#pragma once

namespace hismic {
	namespace maths {

		struct mat4 {
			float elements[4 * 4];

			mat4();
			mat4(float diagonal);

			static mat4 identity();

			mat4& multiply(const mat4& other);
			static mat4 orthographic(float left,float right,float top,float bottom,float near,float far);

		};

	}
}