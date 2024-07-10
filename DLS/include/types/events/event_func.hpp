#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "event_statement.hpp"

namespace dls::events::types {
	template <typename TFunc>
	class event_func : public core::interfaces::serializable<event_func<TFunc>> {
		private:
			std::vector<core::wrappers::val<event_statement<TFunc>>> _statements;
			
		public:
			/*auto invoke(tick& tick, std::vector<void*> const& args) {
				typename decltype(std::function<TFunc>()())::type ret{};

				for (auto& func : _statements) {
					ret += func.value().invoke(tick, args);
				}

				return ret;
			}*/

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_statements));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(CEREAL_NVP(_statements));
			}

			void draw(std::string const& label) const override {

			}
	};
}
