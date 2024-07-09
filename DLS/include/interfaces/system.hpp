#pragma once

#include "singleton.hpp"
#include "miscellaneous/tick.hpp"

namespace dls {
    class system_base {
        public:
            /// <summary>
            /// On Initialize is called immediately when the application is loaded. This is useful for initializing global logic and data.
            /// </summary>
            virtual void initialize() = 0;
            
            /// <summary>
            /// On Scene Load is called when a scene is loaded. This is useful for initializing scene-specific values like lists of vals.
            /// </summary>
            virtual void on_scene_load() { }
            
            /// <summary>
            /// On Tick is called every tick, which is exactly 60 times a second.
            /// </summary>
            /// <param name="tick">The current tick being executed.</param>
            virtual void on_tick(game::tick& tick) { }
            
            /// <summary>
            /// On Scene Unload is called when a scene is unloaded. This is useful for shutting down scene-specific values like lists of vals.
            /// </summary>
            virtual void on_scene_unload() { }

            /// <summary>
            /// On Shutdown is called right before the application is unloaded. This is useful for shutting down global logic and data.
            /// </summary>
            virtual void shutdown() = 0;
    };

    template <typename T>
    class system : public singleton<T>, public system_base {

    };
}
