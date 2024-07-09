#pragma once

#include <vector>
#include "miscellaneous/tick.hpp"
#include "unique.hpp"

namespace dls {
	class function : public unique<function> {
		public:
			virtual void invoke(game::tick&, std::vector<void*> const&, std::vector<void*>&) const = 0;
	};
}
