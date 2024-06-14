#pragma once

#include "module_system.hpp"
#include "collision.hpp"

namespace dls {
    class collision_system : public module_system<collision> {
        protected:
            void on_scene_load(collision&) override;
            void on_enable(collision&) override;
            void on_start(collision&) override;
            void on_tick(tick&, collision&) override;
            void on_quit(collision&) override;
            void on_disable(collision&) override;
            void on_scene_unload(collision&) override;
    };
}
