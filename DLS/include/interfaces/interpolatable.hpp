#pragma once

#include "miscellaneous/math_defines.hpp"

namespace dls::math::interfaces {
	template <typename T>
	class interpolatable {
        protected:
			virtual T lerp(T const&, math::decimal) const = 0;
			virtual math::decimal inverse_lerp(T const&, T const&) const = 0;
	};
}
