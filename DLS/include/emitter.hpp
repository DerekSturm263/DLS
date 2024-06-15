#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "entity.hpp"

namespace dls {
	class emitter : public module<> {
		private:
			type<entity> _entity;
	};
}

REGISTER_MODULE(dls::emitter);
