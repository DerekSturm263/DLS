#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "interfaces/function.hpp"

namespace dls::core {
	class module_base : public serializable<module_base> {
		protected:
			std::vector<function*> _all_functions;

			template <typename TFunc>
			friend class event;
			
		public:
			module_base() : _all_functions() { }
			virtual ~module_base() { }
	};

	template <typename... TFuncTypes>
	class module : public module_base {
		protected:
			module() {
				(_all_functions.push_back(new TFuncTypes()), ...);
			}

			~module() {
				for (auto& function : _all_functions) {
					delete function;
				}
			}
	};
}

CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::module_base, dls::core::module<>);
#define REGISTER_MODULE(to_register) CEREAL_REGISTER_TYPE(to_register); CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::module<>, to_register);
