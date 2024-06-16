#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/state_machine.hpp"

namespace dls {
	class state_machine_agent : public module<> {
		private:
			type<state_machine<void*>> _state_machine;
	};
}

REGISTER_MODULE(dls::state_machine_agent);
