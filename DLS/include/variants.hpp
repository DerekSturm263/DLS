#pragma once

#include <vector>
#include "serializable.hpp"

namespace dls {
	template <typename T>
	class variants : public serializable {
		private:
			std::vector<T> _variants;
	};
}
