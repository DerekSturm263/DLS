#pragma once

#include "serializable.hpp"

namespace dls {
	/// <summary>
	/// Marks a refT or valT as optional. Optional parameters must have a programmer-defined default
	/// </summary>
	/// <typeparam name="T">Type to be optional (must be refT or valT)</typeparam>
	template <typename T>
	class optional : public serializable {
		private:
			T _val_or_ref;

		public:
			optional(T default) : _val_or_ref(default) { }

			auto const& value() {
				return _val_or_ref.value();
			}
	};
}
