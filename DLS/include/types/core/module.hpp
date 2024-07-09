#pragma once

#include "interfaces/serializable.hpp"
#include "interfaces/function.hpp"

namespace dls::core::types {
	class module_base : public serializable<module_base> {
		protected:
			std::vector<std::shared_ptr<function>> _all_functions;

			template <typename TFunc>
			friend class event;
			
		public:
			module_base() : _all_functions() { }
	};

	template <typename... TFuncTypes>
	class module : public module_base {
		protected:
			module() {
				([&] {
					_all_functions.push_back(std::make_shared<TFuncTypes>(TFuncTypes{}));
				} (), ...);
			}
	};
}

CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::types::module_base, dls::core::types::module<>);
#define REGISTER_MODULE(to_register) CEREAL_REGISTER_TYPE(to_register); CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::types::module<>, to_register);
