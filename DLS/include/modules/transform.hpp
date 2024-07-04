#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/math/transform.hpp"
#include "types/math/fixed.hpp"

namespace dls::math::modules {
	template <typename Transform>
	class transform : public core::module<> {
		private:
			type<Transform> _transform;

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