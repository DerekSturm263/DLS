#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"

namespace dls::math::types {
    template <typename StoredPrecision, typename ReturnedPrecision, size_t Divisor>
	class decimal : public core::interfaces::serializable<decimal<StoredPrecision, ReturnedPrecision, Divisor>> {
		private:
			StoredPrecision _value;
			
		public:
			decimal() : _value() { }
			
			decimal(ReturnedPrecision value) : _value(value) { }

			decimal(decimal<StoredPrecision, ReturnedPrecision, Divisor>& value) : _value(value) { }
			decimal(decimal<StoredPrecision, ReturnedPrecision, Divisor>&& value) : _value(std::move(value)) { }

            void set(ReturnedPrecision value) {
                _value = static_cast<StoredPrecision>(value * Divisor);
            }

			ReturnedPrecision get() const {
				return _value / (ReturnedPrecision)Divisor;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}

			operator ReturnedPrecision() const {
				return get();
			}
						
			decimal<StoredPrecision, ReturnedPrecision, Divisor> operator+(decimal<StoredPrecision, ReturnedPrecision, Divisor> const& rhs) const {
				return decimal<StoredPrecision, ReturnedPrecision, Divisor>(_value + rhs._value);
			}

			decimal<StoredPrecision, ReturnedPrecision, Divisor> operator-(decimal<StoredPrecision, ReturnedPrecision, Divisor> const& rhs) const {
				return decimal<StoredPrecision, ReturnedPrecision, Divisor>(_value - rhs._value);
			}

			decimal<StoredPrecision, ReturnedPrecision, Divisor> operator*(decimal<StoredPrecision, ReturnedPrecision, Divisor> const& rhs) const {
				return decimal<StoredPrecision, ReturnedPrecision, Divisor>(_value * rhs._value);
			}

			decimal<StoredPrecision, ReturnedPrecision, Divisor> operator/(decimal<StoredPrecision, ReturnedPrecision, Divisor> const& rhs) const {
				return decimal<StoredPrecision, ReturnedPrecision, Divisor>(_value / rhs._value);
			}

			decimal<StoredPrecision, ReturnedPrecision, Divisor>& operator=(decimal<StoredPrecision, ReturnedPrecision, Divisor> const& rhs) {
				_value = rhs._value;

				return *this;
			}

			decimal<StoredPrecision, ReturnedPrecision, Divisor>& operator=(decimal<StoredPrecision, ReturnedPrecision, Divisor>&& rhs) {
				_value = std::move(rhs._value);

				return *this;
			}
	};
}
