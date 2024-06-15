#pragma once

#include "serializable.hpp"
#include "module.hpp"

namespace dls {
	class entity : public serializable {
		private:
			// TODO: Store the vals somewhere!
			val<std::vector<ref<module_base>>> _modules;
	};
}
