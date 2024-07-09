#pragma once

namespace dls {
	class math {
        public:
			template <typename T>
			T lerp(T const& a, T const& b, fixed32 t) {
				return a.lerp(b, t);
			}

			template <typename T>
			fixed32 inverse_lerp(T const& a, T const& b, T const& v) {
				return a.inverse_lerp(b, v);
			}
	};
}
