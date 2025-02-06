#pragma once

#include "types/core/module.hpp"
#include "wrappers/type.hpp"
#include "types/graphics/material.hpp"
#include "types/graphics/mesh.hpp"

namespace dls::graphics::functions {
	class blit {};
}

namespace dls::graphics::modules {
	class appearance : public core::types::module<functions::blit> {
		private:
			core::wrappers::type<types::material> _material;
			core::wrappers::type<types::mesh> _mesh;

		public:
			core::wrappers::type<types::material> material() const {
				return _material;
			}

			core::wrappers::type<types::mesh> mesh() const {
				return _mesh;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_material));
				file(CEREAL_NVP(_mesh));
			}

			void load(is& file) override {
				file(_material);
				file(_mesh);
			}
	};
}

REGISTER_MODULE("AppearanceModule", dls::graphics::modules::appearance);
