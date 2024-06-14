#pragma once

#include "module_system.hpp"
#include "sender.hpp"

namespace dls {
    class send_system : public module_system<sender> {
        protected:
            void on_scene_load(sender&) override;
            void on_enable(sender&) override;
            void on_start(sender&) override;
            void on_tick(tick&, sender&) override;
            void on_quit(sender&) override;
            void on_disable(sender&) override;
            void on_scene_unload(sender&) override;
    };
}
