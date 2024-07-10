#pragma once

#include <map>
#include "miscellaneous/math_defines.hpp"
#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"
#include "types/events/event.hpp"

namespace dls::time::functions {
	template <typename Decimal>
	class play : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	template <typename Decimal>
	class pause : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	template <typename Decimal>
	class resume : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	template <typename Decimal>
	class stop : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

namespace dls::time::modules {
	template <typename Decimal>
	class timer : public core::types::module<functions::play<Decimal>, functions::pause<Decimal>, functions::resume<Decimal>, functions::stop<Decimal>> {
		private:
			core::wrappers::type<Decimal> _starting_time;
			core::wrappers::type<Decimal> _multiplier;
			core::wrappers::type<Decimal> _ending_time;
			core::wrappers::type<Decimal> _event_tick_rate;

			core::wrappers::type<events::types::event<void(Decimal)>> _on_begin;
			core::wrappers::type<events::types::event<void(Decimal)>> _on_timer_tick;
			core::wrappers::type<events::types::event<void(Decimal)>> _on_end;

			core::wrappers::type<std::map<Decimal, core::wrappers::type<events::types::event<void()>>>> _events;
			
		protected:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_starting_time));
				file(CEREAL_NVP(_multiplier));
				file(CEREAL_NVP(_ending_time));
				file(CEREAL_NVP(_event_tick_rate));
				file(CEREAL_NVP(_on_begin));
				file(CEREAL_NVP(_on_timer_tick));
				file(CEREAL_NVP(_on_end));
				file(CEREAL_NVP(_events));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_starting_time);
				file(_multiplier);
				file(_ending_time);
				file(_event_tick_rate);
				file(_on_begin);
				file(_on_timer_tick);
				file(_on_end);
				file(_events);
			}

			void draw(std::string const& label) const override {
				_starting_time.draw("Starting Time");
				_multiplier.draw("Multiplier");
				_ending_time.draw("Ending Time");
				_event_tick_rate.draw("Event Tick Rate");
				_on_begin.draw("On Begin");
				_on_timer_tick.draw("On Timer Tick");
				_on_end.draw("On End");
				_events.draw("Events");
			}
	};

	using timer_t = timer<math::decimal>;
}

REGISTER_MODULE("Timer", dls::time::modules::timer_t);
