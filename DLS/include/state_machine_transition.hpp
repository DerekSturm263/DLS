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

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_from));
				file(CEREAL_NVP(_to));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_from));
				file(CEREAL_NVP(_to));
			}
	};
}
