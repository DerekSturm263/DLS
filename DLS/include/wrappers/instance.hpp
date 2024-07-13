#pragma once

#include "interfaces/serializable.hpp"
#include "asset.hpp"
#include "val.hpp"

namespace dls::core::wrappers {
	/// <summary>
	/// Runtime instance of an assetT so that the original doesn't get modified
	/// </summary>
	/// <typeparam name="T">Type to instance (must be serializable)</typeparam>
	template <typename T>
	class instance {
		private:
			val<T> _value;

			template <typename T>
			friend class asset;

		public:
			instance(asset<T> const& asset) : _value(asset._value) { }

			instance(instance<T> const& rhs) : _value(rhs._value) { }
			instance(instance<T>&& rhs) : _value(std::move(rhs._value)) { }

			T const& value() const {
				return _value.value();
			}

			T& value() {
				return _value.value();
			}

			instance<T>& operator= (instance<T> const& rhs) {
				_value = rhs._value;
				return *this;
			}

			instance<T>& operator= (instance<T>&& rhs) {
				_value = std::move(rhs._value);
				return *this;
			}
	};
}
