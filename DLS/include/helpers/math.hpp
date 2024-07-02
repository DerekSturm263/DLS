#pragma once

#include "types/fixed.hpp"

namespace dls {
	class math {
        public:
			template <typename T>
			T lerp(T const& a, T const& b, fixed<32> t) {
				return a.lerp(b, t);
			}

			template <typename T>
			fixed<32> inverse_lerp(T const& a, T const& b, T const& v) {
				return a.inverse_lerp(b, v);
			}
	};
}
