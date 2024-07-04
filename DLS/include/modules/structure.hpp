#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/graphics/mesh.hpp"
#include "types/shapes/polygon.hpp"
#include "callbacks/collision_callback_context.hpp"

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class structure : public core::module<> {
		public:
			enum class passthrough_type {
				stop = 1 << 0,
				pass = 1 << 1,
				one_way = 1 << 2
			};

		private:
			type<graphics::mesh> _mesh;

			type<shapes::polygon<Decimal, Size>> _collision_shape;
			type<passthrough_type> _passthrough_type;

			type<events::event<void(collision_callback_context<math::vector<Decimal, Size>> const&)>> _on_collision_enter;
			type<events::event<void(collision_callback_context<math::vector<Decimal, Size>> const&)>> _on_collision_tick;
			type<events::event<void(collision_callback_context<math::vector<Decimal, Size>> const&)>> _on_collision_exit;

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
