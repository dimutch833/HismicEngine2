#include "mat4.h"

namespace hismic {
	namespace maths {
		mat4::mat4()
		{
			for (int i = 0; i < 4 * 4; i++) {
				elements[i] = 0.0f;
			}
		}
		mat4::mat4(float diagonal)
		{
			for (int i = 0; i < 4 * 4; i++) 
				elements[i] = 0.0f;

			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}
		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}
		mat4& mat4::multiply(const mat4& other)
		{
			// TODO: insert return statement here
		}
		mat4& mat4::operator*=(const mat4& other)
		{
			// TODO: insert return statement here
		}
		mat4 mat4::orthographic(float left, float right, float bottom, float top, float, float)
		{
			return mat4();
		}
		mat4 mat4::perspective(float fov, float aspectRatio, float, float)
		{
			return mat4();
		}
		mat4 mat4::translation(const vec3& translation)
		{
			return mat4();
		}
		mat4 mat4::rotation(float angle, const vec3 axis)
		{
			return mat4();
		}
		mat4 mat4::scale(const vec3& scale)
		{
			return mat4();
		}
		mat4 operator*(mat4 left, const mat4& right)
		{
			return mat4();
		}
	}
}