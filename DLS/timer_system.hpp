#pragma once

#include "module_system.hpp"
#include "timer.hpp"

namespace dls {
    class timer_system : public module_system<timer> {
        protected:
            void on_scene_load(timer&) override;
            void on_enable(timer&) override;
            void on_start(timer&) override;
            void on_tick(tick&, timer&) override;
            void on_quit(timer&) override;
            void on_disable(timer&) override;
            void on_scene_unload(timer&) override;
    };
}
