#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "event_func.hpp"

namespace dls::events {
	template <typename TFunc>
	class event : public serializable<event<TFunc>> {
		private:
			std::vector<type<event_func<TFunc>>> _funcs;
			
		public:
			/*auto invoke(tick& tick, std::vector<void*> const& args) {
				typename decltype(std::function<TFunc>()())::type ret{};

				for (auto& func : _funcs) {
					ret += func.value().invoke(tick, args);
				}

				return ret;
			}*/

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_funcs));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_funcs));
			}
	};
}
