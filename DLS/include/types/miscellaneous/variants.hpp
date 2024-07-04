#pragma once

#include <vector>
#include "interfaces/serializable.hpp"

namespace dls::miscellaneous {
	template <typename T>
	class variants : public serializable<variants<T>> {
		private:
			std::vector<type<T>> _variants;

		public:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_variants));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_variants));
			}
	};
}
