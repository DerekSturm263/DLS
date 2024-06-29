#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	/// <summary>
	/// Marks a refT or valT as optional. Optional parameters must have a programmer-defined default
	/// </summary>
	/// <typeparam name="T">Type to be optional (must be refT or valT)</typeparam>
	template <typename T>
	class optional : public serializable<optional<T>> {
		private:
			T _val_or_ref;
			
		public:
			optional(T def) : _val_or_ref(def) { }

			T const& value() const {
				return _val_or_ref.value();
			}

			T& value() {
				return _val_or_ref.value();
			}

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_val_or_ref));
			}

			void load(serializable_base::is& file) override {
				file(_val_or_ref);
			}
	};
}
