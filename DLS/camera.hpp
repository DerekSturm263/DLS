#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "mask.hpp"
#include "processor.hpp"
#include "entity.hpp"

namespace dls {
	class camera : public module<> {
		private:
			type<mask<ref<entity>>> _inclusion_mask;
			type<processor<void*>> _post_processing;
	};
}
