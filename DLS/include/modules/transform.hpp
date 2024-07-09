#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/math/transform.hpp"
#include "types/math/fixed.hpp"

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class transform : public core::types::module<> {
		private:
			type<types::transform<Decimal, Size>> _transform;

		public:
			transform() : _transform() { }

			void save(os& file) const override {
				file(CEREAL_NVP(_transform));
			}

			void load(is& file) override {
				file(_transform);
			}
	};
}
