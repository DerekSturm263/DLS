#pragma once

#include "serializable.hpp"

namespace dls {
	template <typename T>
	class rect : public serializable {
		private:
			T _bottomLeft;
			T _bottomRight;
			T _topLeft;
			T _topRight;

		public:
			T area();
	};
}
