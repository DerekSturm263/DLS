#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/processor.hpp"

namespace dls {
	class sender : public module<> {
		private:
			type<processor<void*>> _pre_processor;
	};
}

REGISTER_MODULE(dls::sender);
