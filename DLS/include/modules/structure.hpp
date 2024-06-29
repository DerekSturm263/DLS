#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/mesh.hpp"
#include "types/polygon.hpp"
#include "callbacks/collision_callback_context.hpp"

namespace dls {
	class structure : public module<> {
		public:
			enum class passthrough_type {
				stop = 1 << 0,
				pass = 1 << 1
			};

		private:
			type<mesh> _mesh;

			type<polygon<fixed<32>, 3>> _collision_shape;
			type<passthrough_type> _passthrough_type;

			type<event<void(collision_callback_context const&)>> _on_collision_enter;
			type<event<void(collision_callback_context const&)>> _on_collision_tick;
			type<event<void(collision_callback_context const&)>> _on_collision_exit;

			void save(os& file) const override {
				file(CEREAL_NVP(_mesh));
				file(CEREAL_NVP(_collision_shape));
				file(CEREAL_NVP(_passthrough_type));
				file(CEREAL_NVP(_on_collision_enter));
				file(CEREAL_NVP(_on_collision_tick));
				file(CEREAL_NVP(_on_collision_exit));
			}

			void load(is& file) override {
				file(_mesh);
				file(_collision_shape);
				file(_passthrough_type);
				file(_on_collision_enter);
				file(_on_collision_tick);
				file(_on_collision_exit);
			}
	};
}

REGISTER_MODULE(dls::structure);
