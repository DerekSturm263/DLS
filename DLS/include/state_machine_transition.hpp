#pragma once

#include "serializable.hpp"
#include "state_machine_state.hpp"
#include "type_templates.hpp"

namespace dls {
	template <typename T>
	class state_machine_transition : public serializable {
		private:
			ref<state_machine_state<T>> _from;
			ref<state_machine_state<T>> _to;
	};
}
