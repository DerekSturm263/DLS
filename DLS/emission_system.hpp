#pragma once

#include "module_system.hpp"
#include "emitter.hpp"

namespace dls {
    class collision_system : public module_system<emitter> {
        protected:
            void on_scene_load(emitter&) override;
            void on_enable(emitter&) override;
            void on_start(emitter&) override;
            void on_tick(tick&, emitter&) override;
            void on_quit(emitter&) override;
            void on_disable(emitter&) override;
            void on_scene_unload(emitter&) override;
    };
}
