#pragma once

#include <string>
#include <iostream>
#include "interfaces/system.hpp"

namespace dls::debug::systems {
	class debug : public system {
        protected:
            void initialize() override;
            void shutdown() override;

        private:
            const std::string _file_name;
            FILE* _debug_file;

        public:
            static void log(std::string const&);
            static void logf(const char*...);
	};
}
