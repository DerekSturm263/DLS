#pragma once

#include <iostream>
#include "types/core/system.hpp"
#include "types/miscellaneous/text.hpp"
#include "miscellaneous/game.hpp"

namespace dls::debug::functions {
	class out {};
}

namespace dls::debug::systems {
	class debug : public core::types::system<functions::out> {
		private:
            core::wrappers::val<miscellaneous::types::text> _file_path;

            std::ofstream _output;

        public:
            debug(std::string const& file_path) : _file_path(file_path) { }
            debug(std::string&& file_path) : _file_path(std::move(file_path)) { }

            void initialize(miscellaneous::game& game) override {
                _output = std::ofstream{_file_path};
            }

            void shutdown(miscellaneous::game& game) override {
                _output.close();
            }

            void out(std::string const& message) {
                _output << message << std::endl;
            }

            void save(core::interfaces::serializable_base::os& file) const override {
                file(CEREAL_NVP(_file_path));
            }

            void load(core::interfaces::serializable_base::is& file) override {
                file(_file_path);
            }
    };
}