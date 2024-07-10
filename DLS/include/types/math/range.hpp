#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::math::types {
	/// <summary>
	/// Represents a range between a minimum and a maximum value.
	/// </summary>
	/// <typeparam name="T">The type for the range. Must have an subtraction operator overload.</typeparam>
	template <typename T>
	class range : public core::interfaces::serializable<range<T>> {
		private:
			core::wrappers::type<T> _min;
			core::wrappers::type<T> _max;

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

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_min));
				file(CEREAL_NVP(_max));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_min);
				file(_max);
			}

			void draw(std::string const& label) const override {
				_min.draw("Min");
				_max.draw("Max");
			}
	};
}
