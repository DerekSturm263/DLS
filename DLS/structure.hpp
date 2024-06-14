#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "mesh.hpp"

namespace dls {
	class structure : public module<> {
		private:
			type<mesh> _mesh;
	};
}
