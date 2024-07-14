#pragma once

#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::state_machines::types {
	template <typename T>
	class state_machine;
}

namespace dls::events::types {
	template <typename TFunc>
	class event;
}

namespace dls::state_machines::modules {
	template <typename T>
	class state_machine_resolver : public core::types::module<> {
		private:
			core::wrappers::type<types::state_machine<T>> _state_machine;
			core::wrappers::type<events::types::event<void(T)>> _on_resolve;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_state_machine));
				file(CEREAL_NVP(_on_resolve));
			}

			void load(is& file) override {
				file(_state_machine);
				file(_on_resolve);
			}

			void draw(std::string const& label) const override {
				_state_machine.draw("State Machine");
				_on_resolve.draw("On Resolve");
			}
	};
}
