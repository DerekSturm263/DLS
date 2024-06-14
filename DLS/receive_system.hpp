#pragma once

#include "module_system.hpp"
#include "receiver.hpp"

namespace dls {
    class receive_system : public module_system<receiver> {
        protected:
            void on_scene_load(receiver&) override;
            void on_enable(receiver&) override;
            void on_start(receiver&) override;
            void on_tick(tick&, receiver&) override;
            void on_quit(receiver&) override;
            void on_disable(receiver&) override;
            void on_scene_unload(receiver&) override;
    };
}
