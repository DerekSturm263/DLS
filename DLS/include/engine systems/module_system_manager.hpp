#pragma once

#include <vector>
#include "interfaces/engine_system.hpp"

namespace dls {
    class module_system_manager : public engine_system {
        protected:
            void initialize() override;
            void update(tick&) override;
            void shutdown() override;
    };
}
