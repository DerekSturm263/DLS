#include "module.hpp"
#include "set_velocity.hpp"
#include "set_acceleration.hpp"

namespace dls {
	module::module() {

	}

	module::~module() {
		for (auto& function : _all_functions) {
			delete function;
		}
	}
}
