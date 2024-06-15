#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "event.hpp"
#include "ui_element_callback_context.hpp"

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

			void* _stored_data;
	};
}

REGISTER_MODULE(dls::ui_element);
