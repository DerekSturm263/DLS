#pragma once

#include <array>
#include "interfaces/serializable.hpp"

namespace dls::collections::types {
    template <typename T, size_t Size>
	class array : public core::interfaces::serializable<array<T, Size>> {
		private:
			std::array<T, Size> _value;
			
		public:
			array() : _value() { }

			array(std::array<T, Size> const& value) : _value(value) { }
			array(std::array<T, Size>&& value) : _value(std::move(value)) { }

			array(T const (&value)[Size]) : _value(value) { }
			array(T (&& value)[Size]) : _value(std::move(value)) { }

			template <typename... Ts>
			array(Ts const& ... values) : _value() {
				int i = 0;
				([&] {
					_value[i++] = values;
				} (), ...);
			}

			template <typename... Ts>
			array(Ts&& ... values) : _value() {
				int i = 0;
				([&] {
					_value[i++] = std::move(values);
				} (), ...);
			}

			std::array<T, Size> const& value() const {
				return _value;
			}

			std::array<T, Size>& value() {
				return _value;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				for (int i = 0; i < Size; ++i) {
					file(_value[i]);
				}
			}

			void load(core::interfaces::serializable_base::is& file) override {
				for (int i = 0; i < Size; ++i) {
					file(_value[i]);
				}
			}
	};
}
