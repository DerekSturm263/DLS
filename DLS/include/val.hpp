#pragma once

#include "unique.hpp"
#include "serializable.hpp"

namespace dls {
	/// <summary>
	/// Stores any given serializable value. Gives it a unique id so it can be referenced with refTs
	/// </summary>
	/// <typeparam name="T">Type to store (must be serializable)</typeparam>
	template <typename T>
	class val : public unique<val<T>>, public serializable {
		private:
			T _value;

		public:
			val() : _value() { }
			val(T const& value) : _value(value) { }

			T const& value() const {
				return _value;
			}

			T& value() {
				return _value;
			}

			void save(os& file) const override {
				file(cereal::make_nvp("_id", this->_id));
				file(CEREAL_NVP(_value));
			}

			void load(is& file) override {
				file(this->_id);
				file(_value);
			}
	};
}
