#pragma once

#include <vector>
#include <tuple>
#include "miscellaneous/game.hpp"
#include "unique.hpp"
#include "gui_drawable.hpp"

namespace dls::core::interfaces {
	class function_base : public unique<function_base>, public gui::interfaces::gui_drawable {
		public:
			virtual void invoke(game::game& game, std::vector<void*> const& inputs, std::vector<void*>& outputs) const = 0;
	};

	template <typename Inputs, typename Outputs>
	class function : public function_base {

	};
}
