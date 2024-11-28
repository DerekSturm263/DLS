#pragma once

#include "interfaces/serializable.hpp"

namespace dls::collections::types {
    template <typename TKey, typename TValue>
	class map : public core::interfaces::serializable<map<TKey, TValue>> {
		private:
			std::unordered_map<TKey, TValue> _value;
			
		public:
			map() : _value() { }

			map(size_t capacity) : _value(capacity) { }
			
			map(std::unordered_map<TKey, TValue> const& value) : _value(value) { }
			map(std::unordered_map<TKey, TValue>&& value) : _value(std::move(value)) { }

			std::unordered_map<TKey, TValue> const& value() const {
				return _value;
			}

			std::unordered_map<TKey, TValue>& value() {
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
