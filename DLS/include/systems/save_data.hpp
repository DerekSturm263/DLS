#pragma once

#include "wrappers/wrappers.hpp"
#include "types/core/system.hpp"
#include "types/properties/property_group.hpp"

namespace dls::serialization::systems {
	class save_data : public core::types::system<> {
		private:
			core::wrappers::asset<properties::types::property_group> _asset;
			core::wrappers::instance<properties::types::property_group> _instance;

		public:
			save_data() : _asset("assets/save_data.data", properties::types::property_group{}), _instance(_asset) { }
			~save_data() {
				_asset.set_from_instance(_instance);
			}

			save_data(save_data&& rhs) = default;

			properties::types::property const& at(std::string const& name) const {
				return _instance.value().at(name);
			}

			properties::types::property& at(std::string const& name) {
				return _instance.value().at(name);
			}

			void save(serializable_base::os& file) const override {

			}

			void load(serializable_base::is& file) override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

REGISTER_SYSTEM("Save Data", dls::serialization::systems::save_data);
