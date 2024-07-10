#pragma once

#include "interfaces/serializable.hpp"
#include "state_machine_state.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::state_machines::types {
	template <typename T>
	class state_machine_transition : public core::interfaces::serializable<state_machine_transition<T>> {
		private:
			core::wrappers::ref<state_machine_state<T>> _from;
			core::wrappers::ref<state_machine_state<T>> _to;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_from));
				file(CEREAL_NVP(_to));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_from);
				file(_to);
			}

			void draw(std::string const& label) const override {

			}
	};
}
