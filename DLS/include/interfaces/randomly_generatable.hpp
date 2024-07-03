#pragma once

#include "systems/random.hpp";

namespace dls {
	template <typename T>
	class randomly_generatable {
        protected:
			virtual T random() const = 0;
			virtual T random_range(T const&, T const&) const = 0;
	};
}
