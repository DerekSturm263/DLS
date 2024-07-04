#pragma once

#include "interfaces/serializable.hpp"

namespace dls::state_machines {
	template <typename T>
	class state_machine_state : public serializable<state_machine_state<T>> {
		private:
			T _value;

		public:
			state_machine_state() : _value() { }
			state_machine_state(T value) : _value(value) { }

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_value));
			}
	};
}
