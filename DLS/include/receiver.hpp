#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "processor.hpp"

namespace dls {
	class receiver : public module<> {
		private:
			type<processor<void*>> _post_processor;
	};
}
