#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"

namespace dls::miscellaneous {
	class game;
}

namespace dls::core::types {
    class system_base : public interfaces::serializable<system_base> {
		public:
            system_base() { }
            system_base(system_base&& rhs) { }

            virtual ~system_base() { }

            /// <summary>
            /// Initialize is called immediately when the application is loaded. This is useful for initializing global logic and data.
            /// </summary>
            virtual void initialize(miscellaneous::game& game) { }

            /// <summary>
            /// On Tick is called every tick, which is exactly however many times is specified in the time system.
            /// </summary>
            virtual void tick(miscellaneous::game& game) { }

            /// <summary>
            /// Update is called every frame, which is as often as possible.
            /// </summary>
            virtual void update() { }

            /// <summary>
            /// Shutdown is called right before the application is unloaded. This is useful for shutting down global logic and data.
            /// </summary>
            virtual void shutdown(miscellaneous::game& game) { }
    };

    template <typename... TFuncTypes>
    class system : public system_base {
		public:
            using base_type = system<TFuncTypes...>;
    };
}

#define REGISTER_SYSTEM(Name, Derived)								                        \
	CEREAL_REGISTER_TYPE_WITH_NAME(Derived, Name);									        \
	CEREAL_REGISTER_POLYMORPHIC_RELATION(Derived::base_type, Derived);			            \
	CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::types::system_base, Derived::base_type);
