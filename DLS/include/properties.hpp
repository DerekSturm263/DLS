#pragma once

#include <unordered_map>
#include "module.hpp"
#include "property_group.hpp"

namespace dls {
	class properties : public module<> {
		private:
			property_group _properties;
	};
}

REGISTER_MODULE(dls::properties);
