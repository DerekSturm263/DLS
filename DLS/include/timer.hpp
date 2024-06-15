#pragma once

#include <unordered_map>
#include "module.hpp"
#include "type_templates.hpp"
#include "event.hpp"
#include "fixed.hpp"

namespace dls {
	class timer : public module<> {
		private:
			type<fixed<32>> _starting_time;
			type<fixed<32>> _multiplier;
			type<fixed<32>> _ending_time;
			type<fixed<32>> _event_tick_rate;

			type<event<void(fixed<32>)>> _on_begin;
			type<event<void(fixed<32>)>> _on_tick;
			type<event<void(fixed<32>)>> _on_end;

			std::unordered_map<type<fixed<32>>, type<event<void()>>> _events;
			
		protected:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}

REGISTER_MODULE(dls::timer);
