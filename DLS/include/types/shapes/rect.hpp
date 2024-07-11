#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "../math/vector.hpp"

namespace dls::shapes::types {
	template <typename T, std::size_t Size>
	class rect : public core::interfaces::serializable<rect<T, Size>> {
		private:
			math::types::vector<core::wrappers::type<T>, Size> _dimensions[Size];
			
		public:
			rect() : _dimensions() { }
			rect(core::wrappers::type<vector<T, Size>> (const& dimensions)[Size]) : _dimensions(dimensions) { }

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
