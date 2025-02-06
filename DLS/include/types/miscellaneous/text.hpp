#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"

namespace dls::miscellaneous::types {
	class text : public core::interfaces::serializable<text> {
		private:
			std::string _value;
			
		public:
			text() : _value() { }
			
			text(std::string const& value) : _value(value) { }
			text(std::string&& value) : _value(std::move(value)) { }

			text(text const& rhs) : _value(rhs._value) {}
			text(text&& rhs) : _value(std::move(rhs._value)) {}

			std::string const& value() const {
				return _value;
			}

			std::string& value() {
				return _value;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}

			operator std::string const&() const {
				return _value;
			}

			operator std::string&() {
				return _value;
			}
			
			operator std::string() {
				return _value;
			}

			text& operator=(text const& rhs) {
				_value = rhs._value;

				return *this;
			}

			text& operator=(text&& rhs) {
				_value = std::move(rhs._value);

				return *this;
			}

			bool operator==(text const& rhs) const {
				return _value == rhs._value;
			}
	};
}

template <>
struct std::hash<dls::miscellaneous::types::text> {
	std::size_t operator()(dls::miscellaneous::types::text const& text) const noexcept {
        return std::hash<std::string>{}(text.value());
    }
};
