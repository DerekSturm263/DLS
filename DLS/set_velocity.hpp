#pragma once

#include "function.hpp"

namespace dls {
	class set_velocity : public function {
		public:
			void invoke(tick&, std::vector<void*> const&) override;
	};
}
