#pragma once

#include <unordered_map>
#include "module.hpp"
#include "type_templates.hpp"
#include "property.hpp"

namespace dls {
	class properties : public module<> {
		private:
			std::unordered_map<std::string, val<property>> _properties;
	};
}

REGISTER_MODULE(dls::properties);
