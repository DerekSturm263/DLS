#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "../math/vector.hpp"

namespace dls::shapes::types {
	template <typename T, std::size_t Size>
	class ellipse : public core::interfaces::serializable<ellipse<T, Size>> {
		private:
			math::types::vector<core::wrappers::type<T>, Size> _dimensions[Size];
			
		public:
			ellipse() : _dimensions() { }
			ellipse(core::wrappers::type<vector<T, Size>> (const& dimensions)[Size]) : dimensions(points) { }

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_dimensions));
			}

			void load(serializable_base::is& file) override {
				file(_dimensions);
			}

			void draw(std::string const& label) const override {
				_dimensions->draw("Dimensions");
			}
	};
}
