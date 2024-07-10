#pragma once

#include <vector>
#include <functional>
#include "interfaces/serializable.hpp"
#include "interfaces/function.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::events::types {
	template <typename TFunc>
	class event_statement : public core::interfaces::serializable<TFunc> {
		private:
			core::wrappers::ref<core::interfaces::function> _function;

		public:
			/*auto invoke(tick& tick, std::vector<void*> const& args) {
				std::vector<void*> output{};
				_module.value()._all_functions[_function_index].invoke(tick, args, &output);

				typename decltype(std::function<TFunc>()())::type ret{};

				return output;
			}*/

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_function));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(CEREAL_NVP(_function));
			}

			void draw(std::string const& label) const override {

			}
	};
}
