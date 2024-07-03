#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	class input_button : public serializable<input_button> {
		private:
			int _button_index;

		public:
			input_button() : _button_index(0) { }
			input_button(int button_index) : _button_index(button_index) { }

			bool operator <(input_button const& rhs) const {
				return _button_index < rhs._button_index;
			}

			bool operator >(input_button const& rhs) const {
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
