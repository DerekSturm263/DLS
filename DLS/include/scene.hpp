#pragma once

#include <vector>
#include "serializable.hpp"
#include "type_templates.hpp"
#include "entity.hpp"

namespace dls {
	class scene : public serializable {
		private:
			val<std::vector<ref<entity>>> _entities;
	};
}
