#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "interfaces/serializable.hpp"

namespace dls::math::types {
	template <typename T, glm::length_t Rows, glm::length_t Columns>
	class matrix : public core::interfaces::serializable<matrix<T, Rows, Columns>>, public glm::mat<Rows, Columns, T, glm::packed_highp> {
		public:
			matrix() : glm::mat<Columns, Rows, T, glm::packed_highp>(0) { }
			
			matrix(glm::mat<Columns, Rows, T, glm::packed_highp> const& rhs) : glm::mat<Columns, Rows, T, glm::packed_highp>(rhs) { }
			matrix(glm::mat<Columns, Rows, T, glm::packed_highp>&& rhs) : glm::mat<Columns, Rows, T, glm::packed_highp>(rhs) { }

			matrix(matrix<T, Rows, Columns> const& rhs) : glm::mat<Columns, Rows, T, glm::packed_highp>(rhs) { }
			matrix(matrix<T, Rows, Columns>&& rhs) : glm::mat<Columns, Rows, T, glm::packed_highp>(rhs) { }

			matrix(T scalar) : glm::mat<Columns, Rows, T, glm::packed_highp>(scalar) { }
			matrix(T a1, T a2, T a3, T b1, T b2, T b3, T c1, T c2, T c3) : glm::mat<Columns, Rows, T, glm::packed_highp>(a1, a2, a3, b1, b2, b3, c1, c2, c3) { }
			matrix(T a1, T a2, T a3, T a4, T b1, T b2, T b3, T b4, T c1, T c2, T c3, T c4, T d1, T d2, T d3, T d4) : glm::mat<Columns, Rows, T, glm::packed_highp>(a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, d1, d2, d3, d4) { }

			void save(core::interfaces::serializable_base::os& file) const override {
				for (int i = 0; i < Columns; ++i) {
					for (int j = 0; j < Rows; ++j) {
						file((*this)[i][j]);
					}
				}
			}

			void load(core::interfaces::serializable_base::is& file) override {
				for (int i = 0; i < Columns; ++i) {
					for (int j = 0; j < Rows; ++j) {
						file((*this)[i][j]);
					}
				}
			}

			void draw(std::string const& label) const override {

			}
	};

	template <typename T>
	using matrix2x2 = matrix<T, 2, 2>;

	template <typename T>
	using matrix3x3 = matrix<T, 3, 3>;

	template <typename T>
	using matrix4x4 = matrix<T, 4, 4>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixc = matrix<char, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixs = matrix<short, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixi = matrix<int, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixl = matrix<long, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixll = matrix<long long, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixuc = matrix<unsigned char, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixus = matrix<unsigned short, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixui = matrix<unsigned int, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixul = matrix<unsigned long, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixull = matrix<unsigned long long, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixf = matrix<float, Width, Height>;

	template <glm::length_t Width, glm::length_t Height>
	using matrixd = matrix<double, Width, Height>;
}
