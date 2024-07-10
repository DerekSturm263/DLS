#pragma once

#include "wrappers/wrappers.hpp"
#include "types/core/system.hpp"
#include "types/properties/property_group.hpp"

namespace dls::serialization::functions {
	class get : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

            void draw(std::string const& label) const override {

            }
	};
	
	class set : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

            void draw(std::string const& label) const override {

            }
	};
}

namespace dls::serialization::systems {
	class save_data : public core::types::system<functions::get, functions::set> {
		private:
			core::wrappers::asset<properties::types::property_group> _asset;
			core::wrappers::instance<properties::types::property_group> _instance;

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

			void save(serializable_base::os& file) const override {

			}

			void load(serializable_base::is& file) override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

REGISTER_SYSTEM("Save Data", dls::serialization::systems::save_data);
