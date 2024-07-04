#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/state machines/state_machine.hpp"
#include "types/events/event.hpp"

namespace dls::state_machines::modules {
	template <typename T>
	class state_machine_resolver : public core::module<> {
		private:
			type<state_machine<T>> _state_machine;
			type<events::event<void(T)>> _on_resolve;

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
