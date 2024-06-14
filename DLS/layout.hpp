#pragma once

#include "module.hpp"
#include "type_templates.hpp"

namespace dls {
	class layout : public module<> {
		private:
			type<int> _width;
			type<int> _height;
	};
}
