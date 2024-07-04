#pragma once

#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "../events/event.hpp"
#include "callbacks/input_callback_context.hpp"

namespace dls::input {
	class input_event_group : public serializable<input_event_group> {
		private:
			val<events::event<void(input_callback_context const&)>> _on_press;
			val<events::event<void(input_callback_context const&)>> _on_hold_tick;
			val<events::event<void(input_callback_context const&)>> _on_release;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_on_press));
				file(CEREAL_NVP(_on_hold_tick));
				file(CEREAL_NVP(_on_release));
			}

			void load(is& file) override {
				file(_on_press);
				file(_on_hold_tick);
				file(_on_release);
			}
	};
}
