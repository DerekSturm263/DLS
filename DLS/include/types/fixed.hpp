#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	template <std::size_t Precision>
	class fixed : public serializable<fixed<Precision>> {
		private:
			long long _internal;

		public:
			fixed() : _internal(0) { }

			fixed(long long _fraction) : _internal(_fraction) { }
			fixed(fixed const& rhs) : _internal(rhs._internal) { }
			fixed(fixed const&& rhs) : _internal(rhs._internal) { }

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_internal));
			}

			void load(serializable_base::is& file) override {
				file(_internal);
			}

			fixed<Precision> operator +(fixed<Precision> const& rhs) const {
				return fixed(_internal + rhs._internal);
			}

			fixed<Precision> operator -(fixed<Precision> const& rhs) const {
				return fixed(_internal - rhs._internal);
			}

			fixed<Precision> operator *(fixed<Precision> const& rhs) const {
				return fixed(_internal * rhs._internal);
			}

			fixed<Precision> operator /(fixed<Precision> const& rhs) const {
				return fixed(_internal / rhs._internal);
			}

			bool operator >(fixed<Precision> const& rhs) const {
				return _internal > rhs._internal;
			}

			bool operator <(fixed<Precision> const& rhs) const {
				return _internal < rhs._internal;
			}

			fixed<Precision>& operator =(fixed<Precision> const& rhs) {
				_internal = rhs._internal;
				return *this;
			}
	};
}
