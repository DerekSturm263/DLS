#pragma once

#include "function.hpp"

namespace dls {
	class set_acceleration : public function {
		public:
			void invoke(tick&, std::vector<void*> const&, std::vector<void*>*) override;
	};
}
