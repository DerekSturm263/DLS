#pragma once

#include <glm/mat4x4.hpp>
#include "interfaces/serializable.hpp"

namespace dls::math::types {
	template <typename T, glm::length_t Rows, glm::length_t Columns>
	class matrix : public core::interfaces::serializable<matrix<T, Rows, Columns>>, public glm::mat<Rows, Columns, T, glm::packed_highp> {
		public:
			matrix() : glm::mat<Columns, Rows, T, glm::packed_highp>(0) { }
			matrix(T scalar) : glm::mat<Columns, Rows, T, glm::packed_highp>(scalar) {}
			
			matrix(glm::mat<Columns, Rows, T, glm::packed_highp> const& rhs) : glm::mat<Columns, Rows, T, glm::packed_highp>(0) {
				std::memcpy(this, &rhs, sizeof(matrix<T, Rows, Columns>));
            }
			matrix(glm::mat<Columns, Rows, T, glm::packed_highp>&& rhs) : glm::mat<Columns, Rows, T, glm::packed_highp>(0) {
				std::memmove(this, &rhs, sizeof(matrix<T, Rows, Columns>));
				rhs = {};
            }

			matrix(matrix<T, Rows, Columns> const& rhs) : glm::mat<Columns, Rows, T, glm::packed_highp>(0) {
				std::memcpy(this, &rhs, sizeof(matrix<T, Rows, Columns>));
            }
			matrix(matrix<T, Rows, Columns>&& rhs) : glm::mat<Columns, Rows, T, glm::packed_highp>(0) {
				std::memmove(this, &rhs, sizeof(matrix<T, Rows, Columns>));
				rhs = {};
            }
			
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

			matrix<T, Rows, Columns>& operator=(matrix<T, Rows, Columns> const& rhs) {
				std::memcpy(this, &rhs, sizeof(matrix<T, Rows, Columns>));

				return *this;
			}

			matrix<T, Rows, Columns>& operator=(matrix<T, Rows, Columns>&& rhs) {
				std::memmove(this, &rhs, sizeof(matrix<T, Rows, Columns>));
				rhs = {};

				return *this;
			}
	};
}
