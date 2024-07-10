#pragma once

#include "interfaces/serializable.hpp"

namespace dls::state_machines::types {
	template <typename T>
	class state_machine_state : public core::interfaces::serializable<state_machine_state<T>> {
		private:
			T _value;

		public:
			state_machine_state() : _value() { }
			state_machine_state(T value) : _value(value) { }

			T const& value() const {
				return _value;
			}

			T& value() {
				return _value;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}

			void draw(std::string const& label) const override {

			}
	};
}
