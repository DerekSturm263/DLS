#pragma once

#include <stdexcept>
#include <glm/gtc/type_ptr.hpp>
#include "interfaces/serializable.hpp"
#include "types/collections/list.hpp"
#include "types/miscellaneous/dropdown.hpp"

namespace dls::graphics::types {
	class shader : public core::interfaces::serializable<shader> {
		public:
			class module : public core::interfaces::serializable<module> {
				public:
					enum class type {
						vertex, fragment
					};
					using type_dropdown = miscellaneous::types::dropdown<type,
						type::vertex,
						type::fragment
					>;

				private:
					type_dropdown _type;
					miscellaneous::types::text _source;

					mutable unsigned int _id;

				public:
					unsigned int const& id() const {
						return _id;
					}

					unsigned int& id() {
						return _id;
					}

					void create() const {
        				/*unsigned int shader = glCreateShader(_type == type::vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
        				
						const char* source = _source.value().c_str();
        				glShaderSource(shader, 1, &source, nullptr);
        				glCompileShader(shader);

				        int success;
        				glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
				
				        if(!success) {
            				char log_buffer[256] = { 0 };
            				glGetShaderInfoLog(shader, sizeof(log_buffer), nullptr, log_buffer);
            				
							_id = 0;
        				} else {
	        				_id = shader;
						}*/
					}

					void destroy() const {
				        //glDeleteShader(_id);
					}

					void save(core::interfaces::serializable_base::os& file) const override {
						file(CEREAL_NVP(_type));
						file(CEREAL_NVP(_source));
					}

					void load(core::interfaces::serializable_base::is& file) override {
						file(_type);
						file(_source);
					}
			};

			

		private:
			collections::types::list<module> _modules;

			mutable int _id;
			mutable int _model_location;
			mutable int _view_location;
			mutable int _projection_location;
			mutable int _uv_location;
			mutable int _dimensions_location;

		public:
			void create() const {
				/*_id = glCreateProgram();

        		for (auto& module : _modules.value()) {
		            glAttachShader(_id, module.id());
        		}

		        glLinkProgram(_id);

		        int success;
        		glGetProgramiv(_id, GL_LINK_STATUS, &success);
        
				if(!success) {
            		char log_buffer[256] = { 0 };
            		glGetProgramInfoLog(_id, sizeof(log_buffer), nullptr, log_buffer);
            
		            throw std::logic_error("Shader: Could not link shader. " + std::string(log_buffer));
        		}

        		_model_location = glGetUniformLocation(_id, "model");
        		_view_location = glGetUniformLocation(_id, "view");
        		_projection_location = glGetUniformLocation(_id, "projection");
        		_uv_location = glGetUniformLocation(_id, "uvOffset");
        		_dimensions_location = glGetUniformLocation(_id, "dimensions");*/
			}

			void destroy() const {
		        //glDeleteProgram(_id);
			}

			template <typename T>
			void set(std::string const& name, T const& value) const {

			}

			void use(math::types::matrix<float, 4, 4> const& camera, math::types::matrix<float, 4, 4> const& projection, math::types::matrix<float, 4, 4> const& model, math::types::vector<float, 2> const& uv_offset, math::types::vector<float, 2> const& dimensions) const {
				/*glUseProgram(_id);

        		glUniformMatrix4fv(_model_location, 1, GL_FALSE, glm::value_ptr(model));
        		glUniformMatrix4fv(_view_location, 1, GL_FALSE, glm::value_ptr(camera));
        		glUniformMatrix4fv(_projection_location, 1, GL_FALSE, glm::value_ptr(projection));
        		glUniform2fv(_uv_location, 1, glm::value_ptr(uv_offset));
		        glUniform2fv(_dimensions_location, 1, glm::value_ptr(dimensions));*/
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_modules));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_modules);
			}
	};
}
