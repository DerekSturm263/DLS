#pragma once

#include "interfaces/serializable.hpp"
#include "types/math/vector.hpp"

namespace dls::graphics::types {
	class texture : public core::interfaces::serializable<texture> {
		private:
			math::types::vector2<int> _dimensions;
			unsigned int _id;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_dimensions));
			}

			void load(is& file) override {
				file(_dimensions);
			}

			void draw(std::string const& label) const override {
				_dimensions.draw("Dimensions");
			}
	};
}
