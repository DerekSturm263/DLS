#pragma once

#include <vector>
#include "miscellaneous/tick.hpp"
#include "unique.hpp"
#include "gui_drawable.hpp"

namespace dls::core::interfaces {
	class function : public unique<function>, public gui::interfaces::gui_drawable {
		public:
			virtual void invoke(game::tick&, std::vector<void*> const&, std::vector<void*>&) const = 0;
	};
}
