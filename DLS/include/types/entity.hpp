#pragma once

#include "interfaces/serializable.hpp"
#include "module.hpp"
#include "type templates/type_templates.hpp"
#include "modules/modules.hpp"

namespace dls {
	class entity : public serializable<entity> {
		private:
			val<transformer> _transform;
			val<input> _input;
			val<properties> _properties;

		public:
			entity() : _transform(), _input(), _properties() { }
			entity(val<transformer> transform, val<input> input, val<properties> properties) : _transform(transform), _input(input), _properties(properties) { }

			void save(os& file) const override {
				file(CEREAL_NVP(_transform));
				file(CEREAL_NVP(_physics));
				file(CEREAL_NVP(_collision));
				file(CEREAL_NVP(_input));
				file(CEREAL_NVP(_appearance));
				file(CEREAL_NVP(_structure));
				file(CEREAL_NVP(_properties));
			}

			void load(is& file) override {
				file(_transform);
				file(_physics);
				file(_collision);
				file(_input);
				file(_appearance);
				file(_structure);
				file(_properties);
			}
	};
}
