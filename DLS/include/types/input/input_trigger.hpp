#pragma once

#include "interfaces/serializable.hpp"

namespace dls::input {
	class input_trigger : public serializable<input_trigger> {
		private:
			int _button_index;

		public:
			input_trigger() : _button_index(0) { }
			input_trigger(int button_index) : _button_index(button_index) { }

			bool operator <(input_trigger const& rhs) const {
				return _button_index < rhs._button_index;
			}

			bool operator >(input_trigger const& rhs) const {
				return _button_index > rhs._button_index;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_button_index));
			}

			void load(is& file) override {
				file(_button_index);
			}
	};
}
