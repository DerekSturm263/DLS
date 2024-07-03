#pragma once

#include "types/fixed.hpp"

namespace dls {
	template <typename T>
	class interpolatable {
        protected:
			virtual T lerp(T const&, fixed32) const = 0;
			virtual fixed32 inverse_lerp(T const&, T const&) const = 0;
	};
}
