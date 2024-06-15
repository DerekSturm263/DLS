#pragma once

#include <vector>
#include "serializable.hpp"
#include "type_templates.hpp"
#include "property.hpp"

namespace dls {
	class property_group : public serializable {
		private:
			std::vector<val<property>> _properties;
	};
}
