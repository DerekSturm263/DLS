#pragma once

#include "module_system.hpp"
#include "input.hpp"

namespace dls {
    class input_system : public module_system<input> {
        protected:
            void on_scene_load(input&) override;
            void on_enable(input&) override;
            void on_start(input&) override;
            void on_tick(tick&, input&) override;
            void on_quit(input&) override;
            void on_disable(input&) override;
            void on_scene_unload(input&) override;
    };
}
