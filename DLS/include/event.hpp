#pragma once

#include <vector>
#include "serializable.hpp"
#include "event_func.hpp"

namespace dls {
	template <typename TFunc>
	class event : public serializable {
		private:
			std::vector<val<event_func<TFunc>>> _funcs;
			
		public:
			auto invoke(tick& tick, std::vector<void*> const& args) {
				typename decltype(std::function<TFunc>()())::type ret{};

				for (auto& func : _funcs) {
					ret += func.value().invoke(tick, args);
				}

				return ret;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_funcs));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_funcs));
			}
	};
}
