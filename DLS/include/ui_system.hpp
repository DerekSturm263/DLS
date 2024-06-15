#pragma once

#include "module_system.hpp"
#include "ui_element.hpp"

namespace dls {
    class ui_system : public module_system<ui_element>{
        protected:
            void on_scene_load(ui_element&) override;
            void on_enable(ui_element&) override;
            void on_start(ui_element&) override;
            void on_tick(tick&, ui_element&) override;
            void on_quit(ui_element&) override;
            void on_disable(ui_element&) override;
            void on_scene_unload(ui_element&) override;
    };
}
