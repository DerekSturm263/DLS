#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "state_machine_state.hpp"
#include "state_machine_transition.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::state_machines::types {
	template <typename T>
	class state_machine : public core::interfaces::serializable<state_machine<T>> {
		private:
			std::vector<core::wrappers::type<state_machine_state<T>>> _states;
			std::vector<core::wrappers::val<state_machine_transition<T>>> _transitions;

		public:
			T const& at(int i) const {
				return _states[i].value().value();
			}

			T& at(int i) {
				return _states[i].value().value();
			}

			void add_state(T const& state) {
				_states.push_back(core::wrappers::val<state_machine_state<T>>{state});
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_states));
				file(CEREAL_NVP(_transitions));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_states);
				file(_transitions);
			}

			void draw(std::string const& label) const override {
				
			}
	};
}
