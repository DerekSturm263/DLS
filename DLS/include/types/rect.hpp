#pragma once

#include "interfaces/serializable.hpp"
#include "vector.hpp"

namespace dls {
	template <typename T, std::size_t Size>
	class rect : public serializable {
		private:
			vector<T, Size> _bottom_left;
			vector<T, Size> _bottom_right;
			vector<T, Size> _top_left;
			vector<T, Size> _top_right;

		public:
			T volume() {
				return 0;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_bottom_left));
				file(CEREAL_NVP(_bottom_right));
				file(CEREAL_NVP(_top_left));
				file(CEREAL_NVP(_top_right));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_bottom_left));
				file(CEREAL_NVP(_bottom_right));
				file(CEREAL_NVP(_top_left));
				file(CEREAL_NVP(_top_right));
			}
	};
}
