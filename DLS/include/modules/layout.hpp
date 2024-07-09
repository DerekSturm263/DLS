#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class layout : public core::types::module<> {
		private:
			type<types::vector<int, Size>> _dimensions;
			type<types::vector<Decimal, Size>> _spacing;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_dimensions));
			}

			void load(is& file) override {
				file(_dimensions);
			}
	};
}
