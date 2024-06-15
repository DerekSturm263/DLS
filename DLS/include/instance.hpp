#pragma once

#include "serializable.hpp"
#include "asset.hpp"
#include "val.hpp"

namespace dls {
	/// <summary>
	/// Runtime instance of an assetT so that the original doesn't get modified
	/// </summary>
	/// <typeparam name="T">Type to instance (must be serializable)</typeparam>
	template <typename T>
	class instance {
		private:
			val<T> _value;

		public:
			instance(asset<T> const& asset) : _value(asset._value) { }

			T const& value() const {
				return _value.value();
			}
	};
}
