#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "../math/vector.hpp"

namespace dls::shapes::types {
	template <typename T, std::size_t Size>
	class rect : public serializable<rect<T, Size>> {
		private:
			type<math::types::vector<T, Size>> _corners[Size * 2];
			
		public:
			rect() : _corners() { }
			rect(type<vector<T, Size>> (const& corners)[Size * 2]) : _corners(corners) { }

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_corners));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_corners));
			}
	};
}
