#pragma once

#include "systems/random.hpp";

namespace dls::math::interfaces {
	template <typename T>
	class randomly_generatable {
        protected:
			virtual T random() const = 0;
			virtual T random_range(T const&, T const&) const = 0;
	};
}
