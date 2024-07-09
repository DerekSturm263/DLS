#pragma once

#include "types/math/fixed.hpp"
#include "types/math/transform.hpp"

namespace dls::math {
	const int precision = 512;
	const glm::length_t dimensions = 3;
	//using decimal = math::fixed<long long, precision>;
	using decimal = float;

	using vector_t = math::types::vector<decimal, dimensions>;
	using matrix_t = math::types::matrix<decimal, dimensions + 1, dimensions + 1>;
	using quaternion_t = math::types::quaternion<decimal>;
	using transform_t = math::types::transform<decimal, dimensions>;
}
