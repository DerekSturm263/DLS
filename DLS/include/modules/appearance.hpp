#pragma once

#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::graphics::types {
	class material;
	class mesh;
}

namespace dls::graphics::functions {
	class set_parameter : public core::interfaces::function<void()> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& args) const override {

			}
	};
}

namespace dls::graphics::modules {
	class appearance : public core::types::module<functions::set_parameter> {
		private:
			core::wrappers::type<types::material> _material;
			core::wrappers::type<types::mesh> _mesh;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_material));
				file(CEREAL_NVP(_mesh));
			}

			void load(is& file) override {
				file(_material);
				file(_mesh);
			}

			void draw(std::string const& label) const override {
				_material.draw("Material");
				_mesh.draw("Mesh");
			}
	};
}

REGISTER_MODULE("Appearance", dls::graphics::modules::appearance);
