#pragma once

#include <vector>
#include "interfaces/engine_system.hpp"

namespace dls {
    class engine_system_manager : public engine_system {
        protected:
            void initialize() override;
            void update(tick&) override;
            void shutdown() override;

        private:
            std::vector<engine_system*> _systems;

            engine_system_manager(std::vector<engine_system*> const&);
            
            friend class engine;
    };
}
