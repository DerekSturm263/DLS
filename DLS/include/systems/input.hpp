#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/system.hpp"

namespace dls::input::functions {
	class set_max_players : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::game& game, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

namespace dls::input::systems {
    class input : public core::types::system<functions::set_max_players> {
		public:
			void on_tick(game::game& game) override {

			}

			void save(os& file) const override {

			}

			void load(is& file) override {

			}

			void draw(std::string const& label) const override {

			}
    };
}

REGISTER_SYSTEM("Input", dls::input::systems::input);
