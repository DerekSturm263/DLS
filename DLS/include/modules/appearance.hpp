#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/graphics/material.hpp"

namespace dls::graphics::modules {
	class appearance : public core::module<> {
		private:
			type<material> _material;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_material));
			}

			void load(is& file) override {
				file(_material);
			}
	};
}
