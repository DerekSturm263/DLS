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
	class module : module_base {
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
