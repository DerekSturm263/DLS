#pragma once

#include "tick.hpp"

namespace dls {
    template <typename T>
	class module_system {
        protected:
            virtual void on_scene_load(T&) = 0;
            virtual void on_enable(T&) = 0;
            virtual void on_start(T&) = 0;
            virtual void on_tick(tick&, T&) = 0;
            virtual void on_quit(T&) = 0;
            virtual void on_disable(T&) = 0;
            virtual void on_scene_unload(T&) = 0;

            friend class module_system_manager;
	};
}
