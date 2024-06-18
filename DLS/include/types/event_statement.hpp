#pragma once

#include <vector>
#include <functional>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "module.hpp"
#include "miscellaneous/tick.hpp"

namespace dls {
	template <typename TFunc>
	class event_statement : public serializable<TFunc> {
		private:
			ref<module_base> _module;
			unique_base::guid _function_index;

		public:
			auto invoke(tick& tick, std::vector<void*> const& args) -> decltype(std::function<TFunc>()()) {
				std::vector<void*> input{};
				_module.value()._all_functions[_function_index].invoke(tick, args, &input);

				return input;
			}

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_module));
				file(CEREAL_NVP(_function_index));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_module));
				file(CEREAL_NVP(_function_index));
			}
	};
}
