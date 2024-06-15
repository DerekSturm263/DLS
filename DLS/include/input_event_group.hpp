#pragma once

#include "serializable.hpp"
#include "type_templates.hpp"
#include "event.hpp"
#include "input_callback_context.hpp"

namespace dls {
	class input_event_group : public serializable {
		private:
			val<event<void(input_callback_context const&)>> _on_press;
			val<event<void(input_callback_context const&)>> _on_hold_tick;
			val<event<void(input_callback_context const&)>> _on_release;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_on_press));
				file(CEREAL_NVP(_on_hold_tick));
				file(CEREAL_NVP(_on_release));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_on_press));
				file(CEREAL_NVP(_on_hold_tick));
				file(CEREAL_NVP(_on_release));
			}
	};
}
