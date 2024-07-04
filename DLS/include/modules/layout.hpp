#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"

namespace dls::math::modules {
	template <typename VectorInteger, typename VectorDecimal>
	class layout : public core::module<> {
		private:
			type<VectorInteger> _dimensions;
			type<VectorDecimal> _spacing;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_dimensions));
			}

			void load(is& file) override {
				file(_dimensions);
			}
	};
}
