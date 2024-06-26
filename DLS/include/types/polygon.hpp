#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "vector.hpp"

namespace dls {
	template <typename T, std::size_t Size>
	class polygon : public serializable<polygon<T, Size>> {
		private:
			std::vector<type<vector<T, Size>>> _points;
			
		public:
			polygon() : _points() { }
			polygon(std::vector<type<vector<T, Size>>> const& points) : _points(points) { }

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_points));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_points));
			}
	};
}
