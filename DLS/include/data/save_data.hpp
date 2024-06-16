#pragma once

#include <unordered_map>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "types/property.hpp"

namespace dls {
	class save_data : public serializable {
		private:
			std::unordered_map<std::string, val<property>> _properties;
	};
}
