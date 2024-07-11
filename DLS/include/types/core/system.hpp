#pragma once

#include "interfaces/serializable.hpp"
#include "interfaces/function.hpp"

namespace dls::core::functions {
	class set_sys_enabled : public interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

            void draw(std::string const& label) const override {

            }
	};
}

namespace dls::core::types {
    class system_base : public interfaces::serializable<system_base> {
		protected:
			std::vector<std::unique_ptr<interfaces::function>> _all_functions;

			template <typename TFunc>
			friend class event;

		public:
            system_base() : _all_functions() { }
            ~system_base() { }

            /// <summary>
            /// Initialize is called immediately when the application is loaded. This is useful for initializing global logic and data.
            /// </summary>
            virtual bool initialize() { return true; }

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
		public:
            using base_type = typename system<TFuncTypes...>;

		protected:
            system() {
                std::unique_ptr<interfaces::function> ptr = std::make_unique<functions::set_sys_enabled>(functions::set_sys_enabled{});
                _all_functions.push_back(std::move(ptr));

				([&] {
                    std::unique_ptr<interfaces::function> ptr = std::make_unique<TFuncTypes>(TFuncTypes{});

					_all_functions.push_back(std::move(ptr));
				} (), ...);
			}
    };
}

#define REGISTER_SYSTEM(name, derived)								                        \
	CEREAL_REGISTER_TYPE_WITH_NAME(derived, name);									        \
	CEREAL_REGISTER_POLYMORPHIC_RELATION(derived::base_type, derived);			            \
	CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::types::system_base, derived::base_type);
