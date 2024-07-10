#pragma once

#include "interfaces/serializable.hpp"

namespace dls::core::wrappers {
	/// <summary>
	/// Marks a refT or valT as required. Required parameters will prevent a scene from loading if it isn't assigned
	/// </summary>
	/// <typeparam name="T">Type to be required (must be refT or valT)</typeparam>
	template <typename T>
	class required : public interfaces::serializable<required<T>> {
		private:
			T _val_or_ref;
			
		public:
			required() : _val_or_ref() { }

			T const& value() const {
				return _val_or_ref;
			}

			T& value() {
				return _val_or_ref;
			}

			void save(interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_val_or_ref));
			}

			void load(interfaces::serializable_base::is& file) override {
				file(_val_or_ref);
			}

			void draw(std::string const& label) const override {

			}
	};
}
