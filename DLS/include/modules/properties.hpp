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
			properties(property_group properties) : _properties(properties) { }

			void save(os& file) const override {
				file(CEREAL_NVP(_properties));
			}

			void load(is& file) override {
				file(_properties);
			}
	};
}

REGISTER_MODULE(dls::properties);
