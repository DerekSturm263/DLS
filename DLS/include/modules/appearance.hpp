#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/material.hpp"

namespace dls {
	class appearance : public module<> {
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

REGISTER_MODULE(dls::appearance);
