#pragma once

#include "interfaces/serializable.hpp"
#include "state_machine_state.hpp"
#include "type templates/type_templates.hpp"

namespace dls::state_machines::types {
	template <typename T>
	class state_machine_transition : public serializable<state_machine_transition<T>> {
		private:
			ref<state_machine_state<T>> _from;
			ref<state_machine_state<T>> _to;

		public:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_from));
				file(CEREAL_NVP(_to));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_from));
				file(CEREAL_NVP(_to));
			}
	};
}
