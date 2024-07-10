#pragma once

#include <string>
#include <iostream>
#include "types/core/system.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::debug::functions {
	class out : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	class in : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

namespace dls::debug::systems {
	class debug : public core::types::system<functions::out, functions::in> {
        private:
            core::wrappers::type<std::string> _file_name;

        public:
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

REGISTER_SYSTEM("Debug", dls::debug::systems::debug);
