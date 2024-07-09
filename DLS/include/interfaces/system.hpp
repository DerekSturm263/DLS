#pragma once

#include "interfaces/serializable.hpp"
#include "interfaces/function.hpp"
#include "miscellaneous/tick.hpp"

namespace dls {
    class system_base : public serializable<system_base> {
		protected:
			std::vector<std::shared_ptr<function>> _all_functions;

			template <typename TFunc>
			friend class event;

		public:
            system_base() : _all_functions() { }

            /// <summary>
            /// Initialize is called immediately when the application is loaded. This is useful for initializing global logic and data.
            /// </summary>
            virtual void initialize() { }

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
            /// Shutdown is called right before the application is unloaded. This is useful for shutting down global logic and data.
            /// </summary>
            virtual void shutdown() { }
    };

    template <typename... TFuncTypes>
    class system : public system_base {
		protected:
            system() {
				([&] {
					_all_functions.push_back(std::make_shared<TFuncTypes>(TFuncTypes{}));
				} (), ...);
			}
    };
}

CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::system_base, dls::system<>);
#define REGISTER_SYSTEM(to_register) CEREAL_REGISTER_TYPE(to_register); CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::system<>, to_register);
