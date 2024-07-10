#pragma once

#include <map>
#include "interfaces/serializable.hpp"
#include "graph_point.hpp"
#include "../math/fixed.hpp"

namespace dls::graph::types {
	template <typename T, typename U>
	class graph : public core::interfaces::serializable<graph<T, U>> {
		private:
			std::map<T, core::wrappers::type<graph_point<U>>> _points;
			
		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_points));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_points);
			}

			void draw(std::string const& label) const override {

			}
	};
}
