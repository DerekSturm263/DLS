#pragma once

namespace dls::math::helpers {
	class math {
        public:
			template <typename T, typename Decimal>
			T lerp(T const& a, T const& b, Decimal t) {
				return a.lerp(b, t);
			}

			template <typename T, typename Decimal>
			Decimal inverse_lerp(T const& a, T const& b, T const& v) {
				return a.inverse_lerp(b, v);
			}
	};
}
