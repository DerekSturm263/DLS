#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"

namespace dls {
	class layout : public module<> {
		private:
			type<int> _width;
			type<int> _height;
	};
}

REGISTER_MODULE(dls::layout);
