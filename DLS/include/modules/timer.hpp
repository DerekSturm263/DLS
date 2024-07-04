#pragma once

#include <map>
#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/events/event.hpp"
#include "types/math/fixed.hpp"

namespace dls::time::modules {
	template <typename T>
	class timer : public core::module<> {
		private:
			type<T> _starting_time;
			type<T> _multiplier;
			type<T> _ending_time;
			type<T> _event_tick_rate;

			type<events::event<void(T)>> _on_begin;
			type<events::event<void(T)>> _on_timer_tick;
			type<events::event<void(T)>> _on_end;

			std::map<T, type<events::event<void()>>> _events;
			
		protected:
			void save(os& file) const override {
				file(CEREAL_NVP(_starting_time));
				file(CEREAL_NVP(_multiplier));
				file(CEREAL_NVP(_ending_time));
				file(CEREAL_NVP(_event_tick_rate));
				file(CEREAL_NVP(_on_begin));
				file(CEREAL_NVP(_on_timer_tick));
				file(CEREAL_NVP(_on_end));
				file(CEREAL_NVP(_events));
			}

			void load(is& file) override {
				file(_starting_time);
				file(_multiplier);
				file(_ending_time);
				file(_event_tick_rate);
				file(_on_begin);
				file(_on_timer_tick);
				file(_on_end);
				file(_events);
			}
	};
}
