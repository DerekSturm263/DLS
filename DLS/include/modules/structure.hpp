#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/module.hpp"
#include "types/math/vector.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::shapes::types {
	template <typename T, glm::size_t Size>
	class polygon;
}

namespace dls::events::types {
	template <typename TFunc>
	class event;
}

namespace dls::core::types {
	class entity;
}

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
			core::wrappers::type<shapes::types::polygon<Decimal, Size>> _collider_shape;
			core::wrappers::type<passthrough_type> _passthrough_method;

			core::wrappers::type<events::types::event<void(core::types::entity const&, core::types::entity const&, const math::types::vector<Decimal, Size>)>> _on_collision_enter;
			core::wrappers::type<events::types::event<void(core::types::entity const&, core::types::entity const&, const math::types::vector<Decimal, Size>)>> _on_collision_tick;
			core::wrappers::type<events::types::event<void(core::types::entity const&, core::types::entity const&, const math::types::vector<Decimal, Size>)>> _on_collision_exit;

			void save(os& file) const override {
				file(CEREAL_NVP(_collider_shape));
				file(CEREAL_NVP(_passthrough_method));
				file(CEREAL_NVP(_on_collision_enter));
				file(CEREAL_NVP(_on_collision_tick));
				file(CEREAL_NVP(_on_collision_exit));
			}

			void load(is& file) override {
				file(_collider_shape);
				file(_passthrough_method);
				file(_on_collision_enter);
				file(_on_collision_tick);
				file(_on_collision_exit);
			}

			void draw(std::string const& label) const override {
				_collider_shape.draw("Collider Shape");
				_passthrough_method.draw("Passthrough Method");
				_on_collision_enter.draw("On Collision Enter");
				_on_collision_tick.draw("On Collision Tick");
				_on_collision_exit.draw("On Collision Exit");
			}
	};

	using structure_t = structure<math::decimal, math::dimensions>;
}

REGISTER_MODULE("Structure", dls::simulation::modules::structure_t);
