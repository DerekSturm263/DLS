#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "event_func.hpp"

namespace dls::events::types {
	template <typename TFunc>
	class event : public core::interfaces::serializable<event<TFunc>> {
		private:
			std::vector<core::wrappers::type<event_func<TFunc>>> _funcs;
			
		public:
			/*auto invoke(tick& tick, std::vector<void*> const& args) {
				typename decltype(std::function<TFunc>()())::type ret{};

				for (auto& func : _funcs) {
					ret += func.value().invoke(tick, args);
				}

				return ret;
			}*/

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_funcs));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(CEREAL_NVP(_funcs));
			}

			void draw(std::string const& label) const override {

			}
	};
}
