#pragma once

#include <map>
#include "miscellaneous/math_defines.hpp"
#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"
#include "types/input/input_trigger.hpp"
#include "types/input/input_event_group.hpp"

namespace dls::input::functions {
	template <typename Decimal>
	class send_haptic : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::game& game, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

            void draw(std::string const& label) const override {

            }
	};
}

namespace dls::input::modules {
	template <typename Decimal>
	class input : public core::types::module<functions::send_haptic<Decimal>> {
		private:
			core::wrappers::type<std::map<types::input_trigger, core::wrappers::type<types::input_event_group<Decimal>>>> _actions;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_actions));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_actions);
			}

			void draw(std::string const& label) const override {
				_actions.draw("Actions");
			}
	};

	using input_t = input<math::decimal>;
}

REGISTER_MODULE("Input", dls::input::modules::input_t);
