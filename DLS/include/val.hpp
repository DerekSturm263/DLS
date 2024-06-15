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

		protected:
			void save(os& file) const override {
				file(CEREAL_NVP(this->_id));
				file(CEREAL_NVP(_value));
			}

			void load(is& file) const override {
				file(this->_id);
				file(_value);
			}

		public:
			val(T const& value) : _value(value) { }

			T const& value() const {
				return _value;
			}
	};
}
