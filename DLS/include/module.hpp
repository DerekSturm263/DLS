#pragma once

#include <vector>
#include "serializable.hpp"
#include "function.hpp"

namespace dls {
	class module_base : public serializable {
		protected:
			std::vector<function*> _all_functions;

			template <typename TFunc>
			friend class event;
	};

	template <typename... TFuncTypes>
	class module : public module_base {
		private:
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

#define REGISTER_MODULE(to_register) CEREAL_REGISTER_TYPE(to_register); CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::module<>, to_register); CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::module_base, dls::module<>)
