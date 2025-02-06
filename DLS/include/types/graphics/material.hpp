#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/type.hpp"
#include "wrappers/val.hpp"
#include "types/miscellaneous/text.hpp"
#include "types/miscellaneous/any.hpp"
#include "types/collections/map.hpp"
#include "types/math/vector.hpp"
#include "types/math/matrix.hpp"
#include "shader.hpp"

namespace dls::graphics::types {
	class material : public core::interfaces::serializable<material> {
		private:
            class settings : public core::interfaces::serializable<settings> {
        		private:
		        	collections::types::map<miscellaneous::types::text, miscellaneous::types::any> _values;

        		public:
		        	collections::types::map<miscellaneous::types::text, miscellaneous::types::any> const& values() const {
				        return _values;
        			}
			
		        	collections::types::map<miscellaneous::types::text, miscellaneous::types::any>& values() {
				        return _values;
        			}

        			template <typename T>
		        	void set(std::string const& name, T const& value) {
				        _values.value().at(name) = value;
        			}

		        	void save(os& file) const override {
        				file(CEREAL_NVP(_values));
        			}

		        	void load(is& file) override {
        				file(_values);
        			}
	        };

			core::wrappers::type<shader> _shader;
			core::wrappers::val<settings> _settings;

		public:
			template <typename T>
			void set(std::string const& name, T const& value) {
				_settings.value().set(name, value);
			}

			void use(math::types::matrix<float, 4, 4> const& camera, math::types::matrix<float, 4, 4> const& projection, math::types::matrix<float, 4, 4> const& model, math::types::vector<float, 2> const& uv_offset, math::types::vector<float, 2> const& dimensions) const {
				_shader.value().use(camera, projection, model, uv_offset, dimensions);

				for (auto& value : _settings.value().values().value()) {
					_shader.value().set(value.first.value(), value.second.value());
				}
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_shader));
				file(CEREAL_NVP(_settings));
			}

			void load(is& file) override {
				file(_shader);
				file(_settings);
			}
	};
}
