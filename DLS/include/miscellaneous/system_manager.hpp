#pragma once

#include <vector>
#include "types/core/system.hpp"
#include "game.hpp"

namespace dls::systems {
    class system_manager {
        private:
            std::vector<core::types::system_base*> _systems;

        public:
            system_manager() : _systems() { }
            system_manager(std::vector<core::types::system_base*> const& systems) : _systems(systems) { }
            system_manager(std::vector<core::types::system_base*>&& systems) : _systems(std::move(systems)) { }

            bool initialize(game::game&);
            void on_scene_load(game::game&);
            void on_tick(game::game&);
            void on_scene_unload(game::game&);
            void shutdown(game::game&);
    };
}
