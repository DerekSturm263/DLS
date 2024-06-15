#pragma once

#include <unordered_map>
#include "serializable.hpp"
#include "type_templates.hpp"
#include "property.hpp"

namespace dls {
	class save_data : public serializable {
		private:
			std::unordered_map<std::string, val<property>> _properties;
	};
}
