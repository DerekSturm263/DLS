#pragma once

#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"

namespace dls::math::types {
	/// <summary>
	/// Represents a range between a minimum and a maximum value.
	/// </summary>
	/// <typeparam name="T">The type for the range. Must have an subtraction operator overload.</typeparam>
	template <typename T>
	class range : public serializable<range<T>> {
		private:
			type<T> _min;
			type<T> _max;

		public:
			T const& min() const {
				return _min.value();
			}

			T& min() {
				return _min.value();
			}

			T const& max() const {
				return _max.value();
			}

			T& max() {
				return _max.value();
			}

			T difference() {
				return _max.value() - _min.value();
			}

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_min));
				file(CEREAL_NVP(_max));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_min));
				file(CEREAL_NVP(_max));
			}
	};
}
