#pragma once

#include <map>
#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/event.hpp"
#include "types/fixed.hpp"

namespace dls {
	class timer : public module<> {
		private:
			type<fixed<32>> _starting_time;
			type<fixed<32>> _multiplier;
			type<fixed<32>> _ending_time;
			type<fixed<32>> _event_tick_rate;

			type<event<void(fixed<32>)>> _on_begin;
			type<event<void(fixed<32>)>> _on_timer_tick;
			type<event<void(fixed<32>)>> _on_end;

			std::map<type<fixed<32>>, type<event<void()>>> _events;
			
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

REGISTER_MODULE(dls::timer);
