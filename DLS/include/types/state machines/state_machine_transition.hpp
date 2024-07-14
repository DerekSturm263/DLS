#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "../events/event.hpp"

namespace dls::state_machines::types {
	template <typename T>
	class state_machine_state;

	template <typename T>
	class state_machine_transition : public core::interfaces::serializable<state_machine_transition<T>> {
		private:
			core::wrappers::ref<state_machine_state<T>> _from;
			core::wrappers::ref<state_machine_state<T>> _to;
			core::wrappers::type<events::types::event<bool()>> _transition;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_from));
				file(CEREAL_NVP(_to));
				file(CEREAL_NVP(_transition));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_from);
				file(_to);
				file(_transition);
			}

			void draw(std::string const& label) const override {

			}
	};
}
