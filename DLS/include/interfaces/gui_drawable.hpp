#pragma once

#include <string>

namespace dls::gui::interfaces {
	class gui_drawable {
        public:
			virtual void draw(std::string const& label) const = 0;
	};
}
