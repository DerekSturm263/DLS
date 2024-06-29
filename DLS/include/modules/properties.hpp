#pragma once

#include <unordered_map>
#include "types/module.hpp"
#include "types/property_group.hpp"

namespace dls {
	class properties : public module<> {
		private:
			property_group _properties;

		public:
			properties() : _properties() { }
			properties(property_group const& properties) : _properties(properties) { }

			property const& at(std::string const& name) const {
				return _properties.at(name);
			}

			property& at(std::string const& name) {
				return _properties.at(name);
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_properties));
			}

			void load(is& file) override {
				file(_properties);
			}
	};
}

REGISTER_MODULE(dls::properties);
