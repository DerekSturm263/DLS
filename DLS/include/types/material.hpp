#pragma once

#include <string>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "shader.hpp"
#include "material_settings.hpp"

namespace dls {
	class material : public serializable<material> {
		private:
			type<shader> _shader;
			type<material_settings> _settings;

		public:
			template <typename T>
			void set(std::string const& name, T const& value) {
				_settings.value().value().values().at(name) = value;
			}

			void use() {
				//_shader.value().value().use();

				/*for (auto& value : _settings.value().value().values()) {
					_shader.value().value().set(value.first, value.second);
				}*/
			}

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
