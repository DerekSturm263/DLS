#pragma once

#include "serializable.hpp"

namespace dls {
	template <std::size_t Precision>
	class fixed : public serializable {
		private:
			long long _internal;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_internal));
			}

			void load(is& file) override {
				file(_internal);
			}
	};
}
