#pragma once

#include <vector>
#include "serializable.hpp"
#include "vector.hpp"

namespace dls {
	template <typename T, std::size_t Size>
	class polygon : public serializable {
		private:
			std::vector<vector<T, Size>> _points;
	};
}
