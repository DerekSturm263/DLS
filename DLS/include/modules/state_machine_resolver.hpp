#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/state_machine.hpp"
#include "types/event.hpp"

namespace dls {
	class state_machine_resolver : public module<> {
		private:
			type<state_machine<void*>> _state_machine;
			type<event<void(void*)>> _on_resolve;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_state_machine));
				file(CEREAL_NVP(_on_resolve));
			}

			void load(is& file) override {
				file(_state_machine);
				file(_on_resolve);
			}
	};
}

REGISTER_MODULE(dls::state_machine_resolver);
