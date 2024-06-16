#pragma once

#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include "interfaces/serializable.hpp"

namespace dls {
	template <typename T, glm::length_t Size>
	class vector : public serializable, public glm::vec<Size, T, glm::packed_highp> {
		public:
			vector() : glm::vec<Size, T, glm::packed_highp>(0) { }
			
			vector(glm::vec<Size, T, glm::packed_highp> const& rhs) : glm::vec<Size, T, glm::packed_highp>(rhs) { }
			vector(vector<T, Size> const& rhs) : glm::vec<Size, T, glm::packed_highp>(rhs) { }
			vector(vector<T, Size> const&& rhs) : glm::vec<Size, T, glm::packed_highp>(rhs) { }

			vector(T scalar) : glm::vec<Size, T, glm::packed_highp>(scalar) { }
			vector(T x, T y) : glm::vec<Size, T, glm::packed_highp>(x, y) { }
			vector(T x, T y, T z) : glm::vec<Size, T, glm::packed_highp>(x, y, z) { }
			vector(T x, T y, T z, T w) : glm::vec<Size, T, glm::packed_highp>(x, y, z, w) { }

			void save(os& file) const override {
				for (int i = 0; i < Size; ++i) {
					file((*this)[i]);
				}
			}

			void load(is& file) override {
				for (int i = 0; i < Size; ++i) {
					file((*this)[i]);
				}
			}
	};

	template <typename T>
	using vector2 = vector<T, 2>;

	template <typename T>
	using vector3 = vector<T, 3>;

	template <typename T>
	using vector4 = vector<T, 4>;
}
