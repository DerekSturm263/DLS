#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "state_machine_state.hpp"
#include "state_machine_transition.hpp"
#include "type templates/type_templates.hpp"

namespace dls {
	template <typename T>
	class state_machine : public serializable<state_machine<T>> {
		private:
			std::vector<val<state_machine_state<T>>> _states;
			std::vector<val<state_machine_transition<T>>> _transitions;

		public:
			void add_state(T const& state) {
				_states.push_back(val<state_machine_state<T>>{state});
			}

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_states));
				file(CEREAL_NVP(_transitions));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_states));
				file(CEREAL_NVP(_transitions));
			}
	};
}
