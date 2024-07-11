#pragma once

#include <vector>
#include "types/core/system.hpp"

namespace dls::systems {
    class system_manager {
        private:
            std::vector<core::types::system_base*> _systems;

        public:
            system_manager() : _systems() { }
            system_manager(std::vector<core::types::system_base*> const& systems) : _systems(systems) { }
            system_manager(std::vector<core::types::system_base*>&& systems) : _systems(std::move(systems)) { }

            bool initialize();
            void on_scene_load();
            void on_tick(game::tick&);
            void on_scene_unload();
            void shutdown();
    };
}
