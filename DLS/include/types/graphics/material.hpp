#pragma once

#include <string>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "shader.hpp"
#include "material_settings.hpp"

namespace dls::graphics::types {
	class material : public core::interfaces::serializable<material> {
		private:
			core::wrappers::type<shader> _shader;
			core::wrappers::type<material_settings> _settings;

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
				file(_shader);
				file(_settings);
			}

			void draw(std::string const& label) const override {
				_shader.draw("Shader");
				_settings.draw("Settings");
			}
	};
}
