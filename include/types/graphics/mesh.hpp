#pragma once

#include "interfaces/serializable.hpp"
#include "types/collections/list.hpp"

namespace dls::graphics::types {
	class mesh : public core::interfaces::serializable<mesh> {
		private:
			collections::types::list<float> _vertices;
			collections::types::list<unsigned int> _indices;
			
			mutable unsigned int _vbo, _vao, _ebo;

		public:
			void create() const {
				/*glGenVertexArrays(1, &_vao);
        		glGenBuffers(1, &_vbo);
        		glGenBuffers(1, &_ebo);
        		glBindVertexArray(_vao);

		        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * _vertices.value().size(), _vertices.value().data(), GL_DYNAMIC_DRAW);

		        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _indices.value().size(), _indices.value().data(), GL_DYNAMIC_DRAW);

		        // Position.
        		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		        glEnableVertexAttribArray(0);

        		// Color.
        		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        		glEnableVertexAttribArray(1);

		        // Texture Coords.
        		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		        glEnableVertexAttribArray(2);

        		glBindBuffer(GL_ARRAY_BUFFER, 0);
		        glBindVertexArray(0);*/
			}

			void destroy() const {
		        /*glDeleteVertexArrays(1, &_vao);
        		glDeleteBuffers(1, &_vbo);
        		glDeleteBuffers(1, &_ebo);*/
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_vertices));
				file(CEREAL_NVP(_indices));
			}

			void load(is& file) override {
				file(_vertices);
				file(_indices);
			}
	};
}
