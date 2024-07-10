#pragma once

#include <string>
#include <iostream>
#include "interfaces/system.hpp"

namespace dls::debug::functions {
	class out : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};

	class in : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};
}

namespace dls::debug::systems {
	class debug : public system<functions::out, functions::in> {
        private:
            std::string _file_name;

        public:
            void save(os& file) const override {
                file(CEREAL_NVP(_file_name));
            }

            void load(is& file) override {
                file(_file_name);
            }
	};
}
