#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"

namespace dls::miscellaneous::types {
	class boolean : public core::interfaces::serializable<boolean> {
		private:
			bool _value;
			
		public:
			boolean() : _value() { }
			
			boolean(bool value) : _value(value) { }

			bool const& value() const {
				return _value;
			}

			bool& value() {
				return _value;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}

			operator bool const&() const {
				return _value;
			}

			operator bool&() {
				return _value;
			}
	};
}
