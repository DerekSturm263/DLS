#pragma once

#include "interfaces/serializable.hpp"
#include "types/property_group.hpp"

namespace dls {
	class save_data {
		private:
			asset<property_group> _asset;
			instance<property_group> _instance;

		public:
			save_data() : _asset("assets/save_data.data", property_group{}), _instance(_asset) { }
			~save_data() {
				_asset.set_from_instance(_instance);
			}

			property const& at(std::string const& name) const {
				return _instance.value().at(name);
			}

			property& at(std::string const& name) {
				return _instance.value().at(name);
			}
	};
}
