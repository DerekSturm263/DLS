#pragma once

#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::events::types {
	template <typename TFunc>
	class event;
}

namespace dls::gui::modules {
	template <typename T>
	class ui_element : public core::types::module<> {
		private:
			core::wrappers::type<events::types::event<void()>> _on_hover;
			core::wrappers::type<events::types::event<void()>> _on_select;
			core::wrappers::type<events::types::event<void()>> _on_press;
			core::wrappers::type<events::types::event<void()>> _on_hold_tick;
			core::wrappers::type<events::types::event<void()>> _on_release;
			core::wrappers::type<events::types::event<void()>> _on_deselect;
			core::wrappers::type<events::types::event<void()>> _on_unhover;

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

			void draw(std::string const& label) const override {
				_on_hover.draw("On Hover");
				_on_select.draw("On Select");
				_on_press.draw("On Press");
				_on_hold_tick.draw("On Hold Tick");
				_on_release.draw("On Release");
				_on_deselect.draw("On Deselect");
				_on_unhover.draw("On Unhover");
			}
	};
}
