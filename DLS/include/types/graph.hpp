#pragma once

#include <map>
#include "interfaces/serializable.hpp"
#include "graph_point.hpp"
#include "fixed.hpp"

namespace dls {
	template <typename T>
	class graph : public serializable<graph<T>> {
		private:
			std::map<fixed<32>, graph_point<T>> _points;
			
		public:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_points));
			}

			void load(serializable_base::is& file) override {
				file(_points);
			}
	};
}
