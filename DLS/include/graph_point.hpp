#pragma once

#include "serializable.hpp"

namespace dls {
	template <typename T>
	class graph_point : public serializable {
		private:
			T _value;
	};
}
