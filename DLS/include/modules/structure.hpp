#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/mesh.hpp"

namespace dls {
	class structure : public module<> {
		private:
			type<mesh> _mesh;
	};
}

REGISTER_MODULE(dls::structure);
