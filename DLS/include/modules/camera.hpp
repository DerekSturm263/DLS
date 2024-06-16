#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/mask.hpp"
#include "types/processor.hpp"
#include "types/entity.hpp"

namespace dls {
	class camera : public module<> {
		private:
			type<mask<ref<entity>>> _inclusion_mask;
			type<processor<void*>> _post_processing;
	};
}

REGISTER_MODULE(dls::camera);
