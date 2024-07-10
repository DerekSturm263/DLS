#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"
#include "types/graphics/mesh.hpp"
#include "types/shapes/polygon.hpp"
#include "callbacks/collision_callback_context.hpp"

namespace dls::simulation::modules {
	template <typename Decimal, glm::length_t Size>
	class structure : public core::types::module<> {
		public:
			enum class passthrough_type {
				stop = 1 << 0,
				pass = 1 << 1,
				one_way = 1 << 2
			};

		private:
			core::wrappers::type<graphics::types::mesh> _mesh;

			core::wrappers::type<shapes::types::polygon<Decimal, Size>> _collision_shape;
			core::wrappers::type<passthrough_type> _passthrough_method;

			core::wrappers::type<events::types::event<void(callbacks::collision_callback_context<Decimal, Size> const&)>> _on_collision_enter;
			core::wrappers::type<events::types::event<void(callbacks::collision_callback_context<Decimal, Size> const&)>> _on_collision_tick;
			core::wrappers::type<events::types::event<void(callbacks::collision_callback_context<Decimal, Size> const&)>> _on_collision_exit;

			void save(os& file) const override {
				file(CEREAL_NVP(_mesh));
				file(CEREAL_NVP(_collision_shape));
				file(CEREAL_NVP(_passthrough_method));
				file(CEREAL_NVP(_on_collision_enter));
				file(CEREAL_NVP(_on_collision_tick));
				file(CEREAL_NVP(_on_collision_exit));
			}

			void load(is& file) override {
				file(_mesh);
				file(_collision_shape);
				file(_passthrough_method);
				file(_on_collision_enter);
				file(_on_collision_tick);
				file(_on_collision_exit);
			}

			void draw(std::string const& label) const override {
				_mesh.draw("Mesh");
				_collision_shape.draw("Collision Shape");
				_passthrough_method.draw("Passthrough Method");
				_on_collision_enter.draw("On Collision Enter");
				_on_collision_tick.draw("On Collision Tick");
				_on_collision_exit.draw("On Collision Exit");
			}
	};

	using structure_t = structure<math::decimal, math::dimensions>;
}

REGISTER_MODULE("Structure", dls::simulation::modules::structure_t);
