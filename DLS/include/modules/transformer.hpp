#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/transform.hpp"
#include "types/fixed.hpp"

namespace dls {
	class transformer : public module<> {
		private:
			type<transform<fixed<32>, 3>> _transform;
	};
}

REGISTER_MODULE(dls::transformer);
