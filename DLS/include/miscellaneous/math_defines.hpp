#pragma once

#include "types/math/fixed.hpp"
#include "types/math/transform.hpp"

namespace dls::math {
	//using decimal = math::fixed<long long, precision>;
	using decimal = float;
	const glm::length_t dimensions = 3;
	const int precision = 512;

	using vector_t = math::vector<decimal, dimensions>;
	using matrix_t = math::matrix<decimal, dimensions + 1, dimensions + 1>;
	using quaternion_t = math::quaternion<decimal>;
	using transform_t = math::transform<decimal, dimensions>;
}
