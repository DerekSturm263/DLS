#pragma once

#include <stb/stb_image.h>
#include <stdexcept>
#include "interfaces/serializable.hpp"
#include "types/miscellaneous/text.hpp"
#include "types/math/vector.hpp"

namespace dls::graphics::types {
    template <glm::length_t Size>
	class texture : public core::interfaces::serializable<texture<Size>> {
		private:
			miscellaneous::types::text _file_path;
			math::types::vector<int, Size> _dimensions;

			mutable unsigned int _id;

		public:
			void create() const {
        		/*glGenTextures(1, &_id);
        		glBindTexture(GL_TEXTURE_2D, _id);
    
		        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		        int width, height, nrChannels;
        		unsigned char* data = stbi_load(source_name.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);
        		
				if (data) {
            		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            		glGenerateMipmap(GL_TEXTURE_2D);
		        } else {
        		    throw std::invalid_argument("Texture: Could not load " + _file_path);
		        }

        		stbi_image_free(data);*/
			}

			void destroy() const {
				//glDeleteTextures(1, &_id);
			}

			math::types::vector<float, Size> get_uvs(unsigned int frame_index) const {
	    		return math::types::vector<float, Size>{
					(1.0F / _dimensions.x) * (frame_index % _dimensions.x),
                    (1.0F / _dimensions.y) * (frame_index / _dimensions.x)
				};
    		}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_file_path));
				file(CEREAL_NVP(_dimensions));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_file_path);
				file(_dimensions);
			}
	};
}
