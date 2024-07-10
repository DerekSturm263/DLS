#pragma once

#include <unordered_map>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "property.hpp"

namespace dls::properties::types {
	class property_group : public core::interfaces::serializable<property_group> {
		private:
			mutable std::unordered_map<std::string, core::wrappers::val<property>> _properties;
			
		public:
			property const& at(std::string const& name) const {
				return _properties[name].value();
			}

			property& at(std::string const& name) {
				return _properties[name].value();
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_properties));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_properties);
			}

			void draw(std::string const& label) const override {

			}
	};
}
