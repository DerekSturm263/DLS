#pragma once

namespace dls {
	template <typename T>
	class interpolatable {
        protected:
			virtual T lerp(T const&) const = 0;
			virtual T inverse_lerp(T const&) const = 0;
	};
}
