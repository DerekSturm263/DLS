#pragma once

#include "serializable.hpp"

namespace dls {
	template <std::size_t Precision>
	class fixed : public serializable {
		private:
			signed long long _internal;
	};
}
