#pragma once

#include <vector>
#include "interfaces/system.hpp"

namespace dls {
    class system_manager : public system {
        protected:
            void initialize() override;
            void on_scene_load() override;
            void on_tick(tick&) override;
            void on_scene_unload() override;
            void shutdown() override;

        private:
            std::vector<system*> _systems;

            system_manager(std::vector<system*> const& systems) : _systems(systems) { }
            
            friend class engine;
    };
}
