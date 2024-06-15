#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "polygon.hpp"
#include "event.hpp"
#include "fixed.hpp"
#include "collision_callback_context.hpp"

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
			
		protected:
			void save(os& file) const override {

			}

			void load(is& file) const override {

			}
	};
}

REGISTER_MODULE(dls::collision);
