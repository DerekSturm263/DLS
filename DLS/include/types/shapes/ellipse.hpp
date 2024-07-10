#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"

namespace dls::shapes::types {
	template <typename T, std::size_t Size>
	class ellipse : public serializable<ellipse<T, Size>> {
		private:
			math::types::vector<type<T>, Size> _dimensions[Size];
			
		public:
			ellipse() : _dimensions() { }
			ellipse(type<vector<T, Size>> (const& dimensions)[Size]) : dimensions(points) { }

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_dimensions));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_dimensions));
			}

			void draw(std::string const& label) const override {
				for (int i = 0; i < Size; ++i) {
					_dimensions[i].draw("Dimension");
				}
			}
	};
}
