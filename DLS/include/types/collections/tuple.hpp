#pragma once

#include "interfaces/serializable.hpp"

namespace dls::collections::types {
    template <typename... Ts>
	class tuple : public core::interfaces::serializable<tuple<Ts...>> {
		private:
			std::tuple<Ts...> _value;
			
		public:
			tuple() : _value() { }

			tuple(std::tuple<Ts...> const& value) : _value(value) { }
			tuple(std::tuple<Ts...>&& value) : _value(std::move(value)) { }

			tuple(tuple<Ts...> const& rhs) : _value(rhs._value) {}
			tuple(tuple<Ts...>&& rhs) : _value(std::move(rhs._value)) {}

			std::tuple<Ts...> const& value() const {
				return _value;
			}

			std::tuple<Ts...>& value() {
				return _value;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}

			tuple<Ts...>& operator=(tuple<Ts...> const& rhs) {
				_value = rhs._value;

				return *this;
			}

			tuple<Ts...>& operator=(tuple<Ts...>&& rhs) {
				_value = std::move(rhs._value);

				return *this;
			}
	};
}
			