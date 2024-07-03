#pragma once

#include "miscellaneous/tick.hpp"

namespace dls {
    class system {
        protected:
            /// <summary>
            /// On Initialize is called immediately when the application is loaded. This is useful for initializing global logic and data.
            /// </summary>
            virtual void initialize() = 0;
            
            /// <summary>
            /// On Scene Load is called when a scene is loaded. This is useful for initializing scene-specific values like lists of vals.
            /// </summary>
            virtual void on_scene_load() = 0;
            
            /// <summary>
            /// On Tick is called every tick, which is exactly 60 times a second.
            /// </summary>
            /// <param name="tick">The current tick being executed.</param>
            virtual void on_tick(tick& tick) = 0;
            
            /// <summary>
            /// On Scene Unload is called when a scene is unloaded. This is useful for shutting down scene-specific values like lists of vals.
            /// </summary>
            virtual void on_scene_unload() = 0;

            /// <summary>
            /// On Shutdown is called right before the application is unloaded. This is useful for shutting down global logic and data.
            /// </summary>
            virtual void shutdown() = 0;

            friend class system_manager;
    };
}
