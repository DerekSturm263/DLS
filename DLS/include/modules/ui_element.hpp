#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/events/event.hpp"
#include "callbacks/ui_element_callback_context.hpp"

namespace dls::gui::modules {
	template <typename T>
	class ui_element : public core::module<> {
		private:
			type<events::event<void(ui_element_callback_context const&)>> _on_hover;
			type<events::event<void(ui_element_callback_context const&)>> _on_select;
			type<events::event<void(ui_element_callback_context const&)>> _on_press;
			type<events::event<void(ui_element_callback_context const&)>> _on_hold_tick;
			type<events::event<void(ui_element_callback_context const&)>> _on_release;
			type<events::event<void(ui_element_callback_context const&)>> _on_deselect;
			type<events::event<void(ui_element_callback_context const&)>> _on_unhover;

			T* _held_data;

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
