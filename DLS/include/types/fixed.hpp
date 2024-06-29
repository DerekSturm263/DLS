#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	template <std::size_t Precision>
	class fixed : public serializable<fixed<Precision>> {
		private:
			long long _internal;

		public:
			fixed() : _internal(0) { }

			fixed(long long fraction) : _internal(fraction) { }
			fixed(fixed<Precision> const& rhs) : _internal(rhs._internal) { }
			fixed(fixed<Precision>&& rhs) : _internal(rhs._internal) { }

			fixed<Precision> operator +(fixed<Precision> const& rhs) const {
				return fixed(_internal + rhs._internal);
			}

			fixed<Precision>& operator ++() {
				_internal += Precision;
				return *this;
			}

			fixed<Precision>& operator +=(fixed<Precision> const& rhs) {
				_internal = *this + rhs;
				return *this;
			}

			fixed<Precision> operator -(fixed<Precision> const& rhs) const {
				return fixed(_internal - rhs._internal);
			}

			fixed<Precision>& operator --() {
				_internal -= Precision;
				return *this;
			}

			fixed<Precision>& operator -=(fixed<Precision> const& rhs) {
				_internal = *this - rhs;
				return *this;
			}

			fixed<Precision> operator *(fixed<Precision> const& rhs) const {
				return fixed(_internal * rhs._internal);
			}

			fixed<Precision>& operator *=(fixed<Precision> const& rhs) {
				_internal = *this * rhs;
				return *this;
			}

			fixed<Precision> operator /(fixed<Precision> const& rhs) const {
				return fixed(_internal / rhs._internal);
			}

			fixed<Precision>& operator /=(fixed<Precision> const& rhs) {
				_internal = *this / rhs;
				return *this;
			}

			bool operator >(fixed<Precision> const& rhs) const {
				return _internal > rhs._internal;
			}

			bool operator >=(fixed<Precision> const& rhs) const {
				return _internal >= rhs._internal;
			}

			bool operator <(fixed<Precision> const& rhs) const {
				return _internal < rhs._internal;
			}

			bool operator <=(fixed<Precision> const& rhs) const {
				return _internal <= rhs._internal;
			}

			bool operator ==(fixed<Precision> const& rhs) const {
				return _internal == rhs._internal;
			}

			bool operator !=(fixed<Precision> const& rhs) const {
				return !(_internal == rhs._internal);
			}

			fixed<Precision>& operator =(fixed<Precision> const& rhs) {
				_internal = rhs._internal;
				return *this;
			}

			fixed<Precision>& operator =(fixed<Precision>&& rhs) {
				_internal = std::move(rhs._internal);
				return *this;
			}

			operator float() const {
				return _internal / static_cast<float>(Precision);
			}

			operator double() const {
				return _internal / static_cast<double>(Precision);
			}

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_internal));
			}

			void load(serializable_base::is& file) override {
				file(_internal);
			}
	};
}
