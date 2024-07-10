#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "../math/vector.hpp"

namespace dls::shapes::types {
	template <typename T, std::size_t Size>
	class polygon : public core::interfaces::serializable<polygon<T, Size>> {
		private:
			std::vector<core::wrappers::type<math::types::vector<T, Size>>> _points;
			
		public:
			polygon() : _points() { }
			polygon(std::vector<core::wrappers::type<math::types::vector<T, Size>>> const& points) : _points(points) { }

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_points));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(CEREAL_NVP(_points));
			}

			void draw(std::string const& label) const override {
				for (auto& point : _points) {
					point.draw("Point");
				}
			}
	};
}
