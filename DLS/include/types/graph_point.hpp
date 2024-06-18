#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	template <typename T>
	class graph_point : public serializable<graph_point<T>> {
		private:
			type<T> _value;

		public:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_value));
			}
	};
}
