#pragma once

#include "interfaces/serializable.hpp"

namespace dls::math::types {
	template <typename T, std::size_t Precision>
	class fixed : public serializable<fixed<T, Precision>> {
		private:
			T _internal;

		public:
			fixed() : _internal(0) { }

			fixed(T fraction) : _internal(fraction * Precision) { }
			fixed(fixed<T, Precision> const& rhs) : _internal(rhs._internal) { }
			fixed(fixed<T, Precision>&& rhs) : _internal(rhs._internal) {
				rhs._internal = 0;
			}

			fixed<T, Precision> operator +(fixed<T, Precision> const& rhs) const {
				return fixed(_internal + rhs._internal);
			}

			fixed<T, Precision>& operator ++() {
				_internal += Precision;
				return *this;
			}

			fixed<T, Precision>& operator +=(fixed<T, Precision> const& rhs) {
				_internal = *this + rhs;
				return *this;
			}

			fixed<T, Precision> operator -(fixed<T, Precision> const& rhs) const {
				return fixed(_internal - rhs._internal);
			}

			fixed<T, Precision>& operator --() {
				_internal -= Precision;
				return *this;
			}

			fixed<T, Precision>& operator -=(fixed<T, Precision> const& rhs) {
				_internal = *this - rhs;
				return *this;
			}

			fixed<T, Precision> operator *(fixed<T, Precision> const& rhs) const {
				return fixed(_internal * rhs._internal);
			}

			fixed<T, Precision>& operator *=(fixed<T, Precision> const& rhs) {
				_internal = *this * rhs;
				return *this;
			}

			fixed<T, Precision> operator /(fixed<T, Precision> const& rhs) const {
				return fixed(_internal / rhs._internal);
			}

			fixed<T, Precision>& operator /=(fixed<T, Precision> const& rhs) {
				_internal = *this / rhs;
				return *this;
			}

			bool operator >(fixed<T, Precision> const& rhs) const {
				return _internal > rhs._internal;
			}

			bool operator >=(fixed<T, Precision> const& rhs) const {
				return _internal >= rhs._internal;
			}

			bool operator <(fixed<T, Precision> const& rhs) const {
				return _internal < rhs._internal;
			}

			bool operator <=(fixed<T, Precision> const& rhs) const {
				return _internal <= rhs._internal;
			}

			bool operator ==(fixed<T, Precision> const& rhs) const {
				return _internal == rhs._internal;
			}

			bool operator !=(fixed<T, Precision> const& rhs) const {
				return !(_internal == rhs._internal);
			}

			fixed<T, Precision>& operator =(fixed<T, Precision> const& rhs) {
				_internal = rhs._internal;
				return *this;
			}

			fixed<T, Precision>& operator =(fixed<T, Precision>&& rhs) {
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

	template <typename T>
	using fixed128 = fixed<T, 128>;

	template <typename T>
	using fixed256 = fixed<T, 256>;

	template <typename T>
	using fixed512 = fixed<T, 512>;

	template <typename T>
	using fixed1024 = fixed<T, 1024>;

	template <typename T>
	using fixed2048 = fixed<T, 2048>;

	template <int Precision>
	using fixedc = fixed<char, Precision>;

	template <int Precision>
	using fixeds = fixed<short, Precision>;

	template <int Precision>
	using fixedi = fixed<int, Precision>;

	template <int Precision>
	using fixedl = fixed<long, Precision>;

	template <int Precision>
	using fixedll = fixed<long long, Precision>;
}
