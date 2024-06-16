#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	template <std::size_t Precision>
	class fixed : public serializable {
		private:
			long long _internal;

		public:
			fixed() : _internal(0) { }

			fixed(long long _fraction) : _internal(_fraction) { }
			fixed(fixed const& rhs) : _internal(rhs._internal) { }
			fixed(fixed const&& rhs) : _internal(rhs._internal) { }

			void save(os& file) const override {
				file(CEREAL_NVP(_internal));
			}

			void load(is& file) override {
				file(_internal);
			}
	};
}
