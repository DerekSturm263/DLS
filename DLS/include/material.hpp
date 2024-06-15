#pragma once

#include "serializable.hpp"
#include "type_templates.hpp"
#include "shader.hpp"
#include "material_settings.hpp"

namespace dls {
	class material : public serializable {
		private:
			required<ref<shader>> _shader;
			type<material_settings> _settings;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_shader));
				file(CEREAL_NVP(_settings));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_shader));
				file(CEREAL_NVP(_settings));
			}
	};
}
