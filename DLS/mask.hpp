#pragma once

#include "serializable.hpp"

namespace dls {
	template <typename T>
	class mask : public serializable {
		private:
			std::size_t _internal;
	};
}
