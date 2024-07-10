#pragma once

#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"
#include "types/graphics/material.hpp"

namespace dls::graphics::functions {
	class render : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

            void draw(std::string const& label) const override {

            }
	};
}

namespace dls::graphics::modules {
	class appearance : public core::types::module<functions::render> {
		private:
			core::wrappers::type<types::material> _material;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_material));
			}

			void load(is& file) override {
				file(_material);
			}

			void draw(std::string const& label) const override {
				_material.draw("Material");
			}
	};
}

REGISTER_MODULE("Appearance", dls::graphics::modules::appearance);
