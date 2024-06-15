#pragma once

#include <vector>
#include "serializable.hpp"
#include "state_machine_state.hpp"
#include "state_machine_transition.hpp"
#include "type_templates.hpp"

namespace dls {
	template <typename T>
	class state_machine : public serializable {
		private:
			std::vector<val<state_machine_state<T>>> _states;
	};
}
