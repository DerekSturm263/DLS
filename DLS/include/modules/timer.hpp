#pragma once

#include <map>
#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/events/event.hpp"
#include "types/math/fixed.hpp"

namespace dls::time::functions {
	template <typename Decimal>
	class play : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};

	template <typename Decimal>
	class pause : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};

	template <typename Decimal>
	class resume : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};

	template <typename Decimal>
	class stop : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};
}

namespace dls::time::modules {
	template <typename Decimal>
	class timer : public core::types::module<functions::play<Decimal>, functions::pause<Decimal>, functions::resume<Decimal>, functions::stop<Decimal>> {
		private:
			type<Decimal> _starting_time;
			type<Decimal> _multiplier;
			type<Decimal> _ending_time;
			type<Decimal> _event_tick_rate;

			type<events::types::event<void(Decimal)>> _on_begin;
			type<events::types::event<void(Decimal)>> _on_timer_tick;
			type<events::types::event<void(Decimal)>> _on_end;

			std::map<Decimal, type<events::types::event<void()>>> _events;
			
		protected:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_starting_time));
				file(CEREAL_NVP(_multiplier));
				file(CEREAL_NVP(_ending_time));
				file(CEREAL_NVP(_event_tick_rate));
				file(CEREAL_NVP(_on_begin));
				file(CEREAL_NVP(_on_timer_tick));
				file(CEREAL_NVP(_on_end));
				file(CEREAL_NVP(_events));
			}

			void load(serializable_base::is& file) override {
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
