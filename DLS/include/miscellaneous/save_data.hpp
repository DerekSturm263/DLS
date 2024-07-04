#pragma once

#include "interfaces/serializable.hpp"
#include "types/properties/property_group.hpp"

namespace dls::game {
	class save_data {
		private:
			asset<properties::property_group> _asset;
			instance<properties::property_group> _instance;

		public:
			save_data() : _asset("assets/save_data.data", properties::property_group{}), _instance(_asset) { }
			~save_data() {
				_asset.set_from_instance(_instance);
			}

			properties::property const& at(std::string const& name) const {
				return _instance.value().at(name);
			}

			properties::property& at(std::string const& name) {
				return _instance.value().at(name);
			}
	};
}
