#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "state_machine.hpp"

namespace dls {
	class state_machine_agent : public module<> {
		private:
			type<state_machine<void*>> _state_machine;
	};
}
