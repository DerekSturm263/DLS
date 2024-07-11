#pragma once

#include "interfaces/serializable.hpp"

namespace dls::graphics::types {
	class mesh : public core::interfaces::serializable<mesh> {
		private:
			float* _vertices;
			unsigned int* _indices;
			unsigned int _vbo, _vao, _ebo;

		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}

			void draw(std::string const& label) const override {

			}
	};
}
