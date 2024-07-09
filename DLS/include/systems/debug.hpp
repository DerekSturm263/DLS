#pragma once

#include <string>
#include <iostream>
#include "interfaces/system.hpp"

namespace dls::debug::systems {
	class debug : public system<> {
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
