#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/event.hpp"
#include "callbacks/ui_element_callback_context.hpp"

namespace dls {
	class ui_element : public module<> {
		private:
			type<event<void(ui_element_callback_context const&)>> _on_hover;
			type<event<void(ui_element_callback_context const&)>> _on_select;
			type<event<void(ui_element_callback_context const&)>> _on_press;
			type<event<void(ui_element_callback_context const&)>> _on_hold_tick;
			type<event<void(ui_element_callback_context const&)>> _on_release;
			type<event<void(ui_element_callback_context const&)>> _on_deselect;
			type<event<void(ui_element_callback_context const&)>> _on_unhover;

			void* _held_data;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_on_hover));
				file(CEREAL_NVP(_on_select));
				file(CEREAL_NVP(_on_press));
				file(CEREAL_NVP(_on_hold_tick));
				file(CEREAL_NVP(_on_release));
				file(CEREAL_NVP(_on_deselect));
				file(CEREAL_NVP(_on_unhover));
			}

			void load(is& file) override {
				file(_on_hover);
				file(_on_select);
				file(_on_press);
				file(_on_hold_tick);
				file(_on_release);
				file(_on_deselect);
				file(_on_unhover);
			}
	};
}

REGISTER_MODULE(dls::ui_element);
