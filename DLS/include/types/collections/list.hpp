#pragma once

#include "interfaces/serializable.hpp"

namespace dls::collections::types {
    template <typename T>
	class list : public core::interfaces::serializable<list<T>> {
		private:
			std::vector<T> _value;
			
		public:
			list() : _value() { }

			list(size_t capacity) : _value(capacity) { }

			list(std::vector<T> const& value) : _value(value) { }
			list(std::vector<T>&& value) : _value(std::move(value)) { }

			template <typename... Ts>
			list(Ts const& ... values) : _value() {
				([&] {
					_value.push_back(values);
				} (), ...);
			}

			template <typename... Ts>
			list(Ts&& ... values) : _value() {
				([&] {
					_value.push_back(std::move(values));
				} (), ...);
			}

			std::vector<T> const& value() const {
				return _value;
			}

			std::vector<T>& value() {
				return _value;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}
	};
}
