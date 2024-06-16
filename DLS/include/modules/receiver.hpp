#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/processor.hpp"

namespace dls {
	class receiver : public module<> {
		private:
			type<processor<void*>> _post_processor;
	};
}
