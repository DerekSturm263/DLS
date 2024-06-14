#pragma once

#include <map>
#include "serializable.hpp"
#include "graph_point.hpp"
#include "fixed.hpp"

namespace dls {
	template <typename T>
	class graph : public serializable {
		private:
			std::map<fixed<32>, graph_point<T>> _points;
	};
}
