#pragma once

#include <optional>
#include <type_traits>
#include "interfaces/serializable.hpp"
#include "interfaces/function.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::core::functions {
	class set_sys_enabled : public interfaces::function<std::tuple<>, std::tuple<>> {
		public:
            void invoke(game::game& game, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

            }

            void draw(std::string const& label) const override {

            }
	};
}

namespace dls::core::types {
    class system_base : public interfaces::serializable<system_base> {
		protected:
			std::unordered_map<size_t, wrappers::val<std::unique_ptr<interfaces::function_base>>> _functions;

			template <typename TFunc>
			friend class event;

		public:
            system_base() : _functions() { }
            system_base(system_base&& rhs) : _functions(std::move(rhs._functions)) { }

            /// <summary>
            /// Initialize is called immediately when the application is loaded. This is useful for initializing global logic and data.
            /// </summary>
            virtual bool initialize(game::game& game) { return true; }

            /// <summary>
            /// On Scene Load is called when a scene is loaded. This is useful for initializing scene-specific values like lists of vals.
            /// </summary>
            virtual void on_scene_load(game::game& game) { }

            /// <summary>
            /// On Tick is called every tick, which is exactly 60 times a second or however often specified in the time system.
            /// </summary>
            /// <param name="tick">The current tick being executed.</param>
            virtual void on_tick(game::game& game) { }

            /// <summary>
            /// On Scene Unload is called when a scene is unloaded. This is useful for shutting down scene-specific values like lists of vals.
            /// </summary>
            virtual void on_scene_unload(game::game& game) { }

            /// <summary>
            /// Shutdown is called right before the application is unloaded. This is useful for shutting down global logic and data.
            /// </summary>
            virtual void shutdown(game::game& game) { }

            template <typename T>
            std::optional<T const*> get_function() const {
                size_t index = typeid(T).hash_code();

                if (_functions.contains(index))
                    return static_cast<T const*>(_functions.at(index).value().get());

                return std::nullopt;
            }
    };

    template <typename... TFuncTypes>
    class system : public system_base {
		public:
            using base_type = typename system<TFuncTypes...>;

		protected:
            system() {
                std::unique_ptr<interfaces::function_base> ptr = std::make_unique<functions::set_sys_enabled>(functions::set_sys_enabled{});
                _functions.insert(std::make_pair(typeid(functions::set_sys_enabled).hash_code(), std::move(ptr)));

				([&] {
                    std::unique_ptr<interfaces::function_base> ptr = std::make_unique<TFuncTypes>(TFuncTypes{});

					_functions.insert(std::make_pair(typeid(TFuncTypes).hash_code(), std::move(ptr)));
				} (), ...);
			}
    };
}

#define REGISTER_SYSTEM(name, derived)								                        \
	CEREAL_REGISTER_TYPE_WITH_NAME(derived, name);									        \
	CEREAL_REGISTER_POLYMORPHIC_RELATION(derived::base_type, derived);			            \
	CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::types::system_base, derived::base_type);
