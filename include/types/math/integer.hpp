#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"

namespace dls::math::types {
	class integer : public core::interfaces::serializable<integer> {
		private:
			int _value;
			
		public:
			integer() : _value() { }
			
			integer(int value) : _value(value) { }

			int const& value() const {
				return _value;
			}

			int& value() {
				return _value;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}

			operator int const&() const {
				return _value;
			}

			operator int&() {
				return _value;
			}

			integer operator+(integer const& rhs) const {
				return integer(_value + rhs._value);
			}

			integer operator-(integer const& rhs) const {
				return integer(_value - rhs._value);
			}

			integer operator*(integer const& rhs) const {
				return integer(_value * rhs._value);
			}

			integer operator/(integer const& rhs) const {
				return integer(_value / rhs._value);
			}
	};
}
