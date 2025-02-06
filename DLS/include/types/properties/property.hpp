#pragma once

#include <variant>
#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"

#include "types/miscellaneous/any.hpp"

namespace dls::properties::types {
	class property : public core::interfaces::serializable<property> {
		private:
			core::wrappers::val<miscellaneous::types::any> _value;
			
		public:
			property() : _value() { }
			
			property(miscellaneous::types::any const& value) : _value(value) { }
			property(miscellaneous::types::any&& value) : _value(std::move(value)) { }

			miscellaneous::types::any const& value() const {
				return _value.value();
			}

			miscellaneous::types::any& value() {
				return _value.value();
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}

		private:
			template <typename T>
			std::string to_string(T const& t) const {
				return t;
			}

			template <>
			std::string to_string<int>(int const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<long long>(long long const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<float>(float const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<double>(double const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<bool>(bool const& t) const {
				return std::to_string(t);
			}

		public:
			operator std::string() const override {
				std::string output = std::visit([&](auto&& arg) { return to_string(arg); }, value().value());
				return output;
			}

			template <typename T>
			property& operator=(T const& rhs) {
				_value.value().value() = rhs;
				return *this;
			}
	};
}
