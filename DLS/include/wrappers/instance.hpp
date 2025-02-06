#pragma once

#include "interfaces/serializable.hpp"
#include "asset.hpp"
#include "val.hpp"

namespace dls::core::wrappers {
	// Runtime instance of an asset so that the original doesn't get modified
	template <typename T>
	class instance {
		private:
			val<T> _value;

			template <typename U>
			friend class asset;

		public:
			instance() : _value() { }

			instance(asset<T> const& asset) : _value(asset._value) { }
			instance(asset<T>&& asset) : _value(std::move(asset._value)) { }

			instance(instance<T> const& rhs) : _value(rhs._value) { }
			instance(instance<T>&& rhs) : _value(std::move(rhs._value)) { }

			T const& value() const {
				return _value.value();
			}

			T& value() {
				return _value.value();
			}

			instance<T>& operator=(instance<T> const& rhs) {
				_value = rhs._value;
				return *this;
			}

			instance<T>& operator=(instance<T>&& rhs) {
				_value = std::move(rhs._value);
				return *this;
			}
	};
}
