#pragma once

#include <vector>
#include <optional>
#include "interfaces/system.hpp"

namespace dls::systems::systems {
    class system_manager {
        private:
            std::vector<system_base*> _systems;

        public:
            system_manager(std::vector<system_base*> const& systems) : _systems(systems) { }
            
        protected:
            void initialize();
            void on_scene_load();
            void on_tick(game::tick&);
            void on_scene_unload();
            void shutdown();
    };
}