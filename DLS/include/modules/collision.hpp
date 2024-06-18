#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/polygon.hpp"
#include "types/event.hpp"
#include "types/fixed.hpp"
#include "callbacks/collision_callback_context.hpp"

namespace dls {
	class collision : public module<> {
		public:
			enum class passthrough_type {
				stop = 1 << 0,
				pass = 1 << 1
			};

		private:
			type<polygon<fixed<32>, 3>> _shape;
			type<passthrough_type> _passthrough;

			type<event<void(collision_callback_context const&)>> _on_collision_enter;
			type<event<void(collision_callback_context const&)>> _on_collision_tick;
			type<event<void(collision_callback_context const&)>> _on_collision_exit;
			
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}

REGISTER_MODULE(dls::collision);
