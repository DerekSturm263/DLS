#pragma once

#include "serializable.hpp"

namespace dls {
	template <typename T>
	class pre_processor : public serializable {
		private:
			type<event<T const& (T const&)>> _event;
	};
}
