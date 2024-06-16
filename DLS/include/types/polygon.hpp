#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "vector.hpp"

namespace dls {
	template <typename T, std::size_t Size>
	class polygon : public serializable {
		private:
			std::vector<vector<T, Size>> _points;
			
		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_points));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_points));
			}
	};
}
