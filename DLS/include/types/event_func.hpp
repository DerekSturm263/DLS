#pragma once

#include <vector>
#include <functional>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "module.hpp"
#include "miscellaneous/tick.hpp"
#include "types/event_statement.hpp"

namespace dls {
	template <typename TFunc>
	class event_func : public serializable<event_func<TFunc>> {
		private:
			std::vector<val<event_statement<TFunc>>> _statements;
			
		public:
			/*auto invoke(tick& tick, std::vector<void*> const& args) {
				typename decltype(std::function<TFunc>()())::type ret{};

				for (auto& func : _statements) {
					ret += func.value().invoke(tick, args);
				}

				return ret;
			}*/

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_statements));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_statements));
			}
	};
}
