#pragma once

#include <unordered_map>
#include "types/module.hpp"
#include "types/property_group.hpp"

namespace dls {
	class properties : public module<> {
		private:
			property_group _properties;
	};
}

REGISTER_MODULE(dls::properties);
