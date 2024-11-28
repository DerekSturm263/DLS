#pragma once

#include <optional>
#include "wrappers/val.hpp"

namespace dls::core::types {
	class module_base : public interfaces::serializable<module_base> {
        public:
            virtual ~module_base() { }
	};

    template <typename... TFuncTypes>
    class module : public module_base {
		public:
            using base_type = module<TFuncTypes...>;
    };
}

#define REGISTER_MODULE(Name, Derived)														\
	CEREAL_REGISTER_TYPE_WITH_NAME(Derived, Name);											\
	CEREAL_REGISTER_POLYMORPHIC_RELATION(Derived::base_type, Derived);						\
	CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::types::module_base, Derived::base_type);
