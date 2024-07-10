#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "../events/event.hpp"
#include "callbacks/input_callback_context.hpp"

namespace dls::input::types {
	template <typename T>
	class input_event_group : public core::interfaces::serializable<input_event_group<T>> {
		private:
			core::wrappers::type<events::types::event<void(callbacks::input_callback_context<T> const&)>> _on_begin;
			core::wrappers::type<events::types::event<void(callbacks::input_callback_context<T> const&)>> _on_hold_tick;
			core::wrappers::type<events::types::event<void(callbacks::input_callback_context<T> const&)>> _on_end;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_on_begin));
				file(CEREAL_NVP(_on_hold_tick));
				file(CEREAL_NVP(_on_end));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_on_begin);
				file(_on_hold_tick);
				file(_on_end);
			}

			void draw(std::string const& label) const override {
				_on_begin.draw("On Begin");
				_on_hold_tick.draw("On Hold");
				_on_end.draw("On End");
			}
	};
}
