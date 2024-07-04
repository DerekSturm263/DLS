#pragma once

#include <map>
#include "interfaces/serializable.hpp"
#include "graph_point.hpp"
#include "../math/fixed.hpp"

namespace dls::graph {
	template <typename T, typename U>
	class graph : public serializable<graph<T, U>> {
		private:
			std::map<T, graph_point<U>> _points;
			
		public:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_points));
			}

			void load(serializable_base::is& file) override {
				file(_points);
			}
	};
}
