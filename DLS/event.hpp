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
			void invoke(tick& tick, std::vector<void*> const& args) {
				for (auto& func : _funcs) {
					func.value().invoke(tick, args);
				}
			}
	};
}
