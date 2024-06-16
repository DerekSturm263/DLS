#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	template <typename T>
	class range : public serializable {
		private:
			T _min;
			T _max;

		public:
			T const& min() const {
				return _min;
			}

			T& min() {
				return _min;
			}

			T const& max() const {
				return _max;
			}

			T& max() {
				return _max;
			}

			T difference() {
				return _max - _min;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_min));
				file(CEREAL_NVP(_max));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_min));
				file(CEREAL_NVP(_max));
			}
	};
}
