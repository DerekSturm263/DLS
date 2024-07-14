#pragma once

#include <variant>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "types/math/vector.hpp"
#include "../events/event.hpp"

namespace dls::input::types {
	class input_trigger;

	template <typename T>
	class input_event_group : public core::interfaces::serializable<input_event_group<T>> {
		private:
			core::wrappers::type<events::types::event<void(input_trigger const&, std::variant<bool, T, math::types::vector2<T>>)>> _on_begin;
			core::wrappers::type<events::types::event<void(input_trigger const&, std::variant<bool, T, math::types::vector2<T>>)>> _on_hold_tick;
			core::wrappers::type<events::types::event<void(input_trigger const&, std::variant<bool, T, math::types::vector2<T>>)>> _on_end;

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
