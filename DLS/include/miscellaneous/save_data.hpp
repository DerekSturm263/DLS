#pragma once

#include "interfaces/serializable.hpp"
#include "types/properties/property_group.hpp"

namespace dls::game {
	class save_data {
		private:
			asset<properties::types::property_group> _asset;
			instance<properties::types::property_group> _instance;

		public:
			save_data() : _asset("assets/save_data.data", properties::types::property_group{}), _instance(_asset) { }
			~save_data() {
				_asset.set_from_instance(_instance);
			}

			properties::types::property const& at(std::string const& name) const {
				return _instance.value().at(name);
			}

			properties::types::property& at(std::string const& name) {
				return _instance.value().at(name);
			}
	};
}
