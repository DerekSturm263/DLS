#pragma once

#include <unordered_map>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "property.hpp"

namespace dls {
	class property_group : public serializable<property_group> {
		private:
			mutable std::unordered_map<std::string, val<property>> _properties;
			
		public:
			property const& at(std::string const& name) const {
				return _properties[name].value();
			}

			property& at(std::string const& name) {
				return _properties[name].value();
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_properties));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_properties));
			}
	};
}
