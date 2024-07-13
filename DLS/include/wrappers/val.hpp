#pragma once

#include "interfaces/unique.hpp"
#include "interfaces/serializable.hpp"

namespace dls::core::wrappers {
	/// <summary>
	/// Stores any given serializable value. Gives it a unique id so it can be referenced with refTs
	/// </summary>
	/// <typeparam name="T">Type to store (must be serializable)</typeparam>
	template <typename T>
	class val : public interfaces::unique<val<T>>, public interfaces::serializable<val<T>> {
		private:
			T _value;

		public:
			val() : _value() { }
			val(T const& value) : _value(value) { }
			val(T&& value) : _value(std::move(value)) { }

			val(val<T> const& rhs) : _value(rhs._value) { }
			val(val<T>&& rhs) : _value(std::move(rhs._value)) { }

			T const& value() const {
				return _value;
			}

			T& value() {
				return _value;
			}

			void save(interfaces::serializable_base::os& file) const override {
				file(cereal::make_nvp("_id", this->_id));
				file(cereal::make_nvp("_sync_type", this->_sync_type));
				file(CEREAL_NVP(_value));
			}

			void load(interfaces::serializable_base::is& file) override {
				file(this->_id);
				file(this->_sync_type);
				file(_value);
			}

			void draw(std::string const& label) const override {

			}

			val<T>& operator= (val<T> const& rhs) {
				_value = rhs._value;
				return *this;
			}

			val<T>& operator= (val<T>&& rhs) {
				_value = std::move(rhs._value);
				return *this;
			}
	};
}
