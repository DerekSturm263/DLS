#pragma once

#include <vector>
#include "serializable.hpp"

namespace dls {
	template <typename T>
	class variants : public serializable {
		private:
			std::vector<T> _variants;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_variants));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_variants));
			}
	};
}
