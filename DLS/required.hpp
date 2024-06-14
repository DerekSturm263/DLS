#pragma once

#include "serializable.hpp"

namespace dls {
	/// <summary>
	/// Marks a refT or valT as required. Required parameters will prevent a scene from loading if it isn't assigned
	/// </summary>
	/// <typeparam name="T">Type to be required (must be refT or valT)</typeparam>
	template <typename T>
	class required : public serializable {
		private:
			T _val_or_ref;

		public:
			required() : _val_or_ref() { }

			auto const& value() {
				return _val_or_ref.value();
			}
	};
}
