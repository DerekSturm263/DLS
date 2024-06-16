#pragma once

#include "types/fixed.hpp"

namespace dls {
	class math {
        public:
			template <typename T>
			T lerp(T const& a, T const& b, fixed<32> t) {
				return a.lerp(b, t);
			}
	};
}
