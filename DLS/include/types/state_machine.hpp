#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "state_machine_state.hpp"
#include "state_machine_transition.hpp"
#include "type templates/type_templates.hpp"

namespace dls {
	template <typename T>
	class state_machine : public serializable {
		private:
			std::vector<val<state_machine_state<T>>> _states;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_states));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_states));
			}
	};
}
