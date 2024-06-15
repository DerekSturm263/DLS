#pragma once

#include "serializable.hpp"

namespace dls {
	template <typename T>
	class range : public serializable {
		private:
			T _min;
			T _max;

		public:
			T difference();
	};
}
