#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "processor.hpp"

namespace dls {
	class sender : public module<> {
		private:
			type<processor<void*>> _pre_processor;
	};
}

REGISTER_MODULE(dls::sender);
