#pragma once

#include "serializable.hpp"
#include "type_templates.hpp"
#include "module.hpp"
#include "tick.hpp"

namespace dls {
	template <typename TFunc>
	class event_func : public serializable {
		private:
			ref<module_base> _module;
			unique_base::guid _function_index;

		public:
			void invoke(tick& tick, std::vector<void*> const& args) {
				_module.value()._all_functions[_function_index].invoke(tick, args);
			}
	};
}
