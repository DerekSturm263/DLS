#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "material.hpp"

namespace dls {
	class appearance : public module<> {
		private:
			type<material> _material;
	};
}
