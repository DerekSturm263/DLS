#pragma once

#include <vector>
#include "tick.hpp"
#include "unique.hpp"

namespace dls {
	class function : public unique<function> {
		public:
			virtual void invoke(tick&, std::vector<void*> const&) = 0;
	};
}
