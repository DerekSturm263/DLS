#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/material.hpp"

namespace dls {
	class appearance : public module<> {
		private:
			type<material> _material;
	};
}

REGISTER_MODULE(dls::appearance);
