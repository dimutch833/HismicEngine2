#pragma once


#include <corecrt_math_defines.h>

namespace hismic {
	namespace maths {
		inline float ToRadians(float degrees) {
			return degrees * (M_PI / 180.0f);
		}
	}
}