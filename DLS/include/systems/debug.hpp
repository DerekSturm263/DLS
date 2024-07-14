#pragma once

#include <string>
#include <iostream>
#include "types/core/system.hpp"
#include "wrappers/wrappers.hpp"
#include "miscellaneous/game.hpp"

namespace dls::debug::functions {
	class log_out;
}

namespace dls::debug::systems {
	class debug : public core::types::system<functions::log_out> {
        private:
            core::wrappers::type<std::string> _file_name;

        public:
			void log_out(std::string const& output) {
				std::cout << output << std::endl;
			}

			void log_in(std::string& input) {
				std::cin >> input;
			}

            void save(os& file) const override {
                file(CEREAL_NVP(_file_name));
            }

            void load(is& file) override {
                file(_file_name);
            }

			void draw(std::string const& label) const override {
				_file_name.draw("File Name");
			}
	};
}

namespace dls::debug::functions {
	class log_out : public core::interfaces::function<void(events::types::param_ref<std::string>)> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<events::types::param_ref<std::string>> const& func_args) const override {
				auto debug = game.project().get_system<systems::debug>();

				if (debug.has_value()) {
					debug.value()->log_out(std::get<0>(func_args).value(event_args));
				}
			}
	};
}

REGISTER_SYSTEM("Debug", dls::debug::systems::debug);
