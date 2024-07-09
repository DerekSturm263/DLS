#pragma once

#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "../events/event.hpp"
#include "callbacks/input_callback_context.hpp"

namespace dls::input::types {
	template <typename T>
	class input_event_group : public serializable<input_event_group<T>> {
		private:
			val<events::types::event<void(callbacks::input_callback_context<T> const&)>> _on_begin;
			val<events::types::event<void(callbacks::input_callback_context<T> const&)>> _on_hold_tick;
			val<events::types::event<void(callbacks::input_callback_context<T> const&)>> _on_end;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_on_begin));
				file(CEREAL_NVP(_on_hold_tick));
				file(CEREAL_NVP(_on_end));
			}

			void load(is& file) override {
				file(_on_begin);
				file(_on_hold_tick);
				file(_on_end);
			}
	};
}
