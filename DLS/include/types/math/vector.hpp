#pragma once

#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include "interfaces/serializable.hpp"

namespace dls::math::types {
	template <typename T, glm::length_t Size>
	class vector : public core::interfaces::serializable<vector<T, Size>>, public glm::vec<Size, T, glm::packed_highp> {
		public:
			vector() : glm::vec<Size, T, glm::packed_highp>(0) { }
			
			vector(glm::vec<Size, T, glm::packed_highp> const& rhs) : glm::vec<Size, T, glm::packed_highp>(rhs) { }
			vector(glm::vec<Size, T, glm::packed_highp>&& rhs) : glm::vec<Size, T, glm::packed_highp>(rhs) { }

			vector(vector<T, Size> const& rhs) : glm::vec<Size, T, glm::packed_highp>(rhs) { }
			vector(vector<T, Size>&& rhs) : glm::vec<Size, T, glm::packed_highp>(rhs) { }

			vector(T scalar) : glm::vec<Size, T, glm::packed_highp>(scalar) { }
			vector(T x, T y) : glm::vec<Size, T, glm::packed_highp>(x, y) { }
			vector(T x, T y, T z) : glm::vec<Size, T, glm::packed_highp>(x, y, z) { }
			vector(T x, T y, T z, T w) : glm::vec<Size, T, glm::packed_highp>(x, y, z, w) { }

			vector<T, Size>& operator =(vector<T, Size> const& rhs) {
				for (int i = 0; i < Size; ++i) {
					(*this)[i] = rhs[i];
				}
				
				return *this;
			}

			vector<T, Size>& operator =(vector<T, Size>&& rhs) {
				for (int i = 0; i < Size; ++i) {
					(*this)[i] = std::move(rhs[i]);
				}

				return *this;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				for (int i = 0; i < Size; ++i) {
					file((*this)[i]);
				}
			}

			void load(core::interfaces::serializable_base::is& file) override {
				for (int i = 0; i < Size; ++i) {
					file((*this)[i]);
				}
			}

			void draw(std::string const& label) const override {

			}
	};

	template <typename T>
	using vector2 = vector<T, 2>;

	template <typename T>
	using vector3 = vector<T, 3>;

	template <typename T>
	using vector4 = vector<T, 4>;

	template <glm::length_t Size>
	using vectorc = vector<char, Size>;

	template <glm::length_t Size>
	using vectors = vector<short, Size>;

	template <glm::length_t Size>
	using vectori = vector<int, Size>;

	template <glm::length_t Size>
	using vectorl = vector<long, Size>;

	template <glm::length_t Size>
	using vectorll = vector<long long, Size>;

	template <glm::length_t Size>
	using vectoruc = vector<unsigned char, Size>;

	template <glm::length_t Size>
	using vectorus = vector<unsigned short, Size>;

	template <glm::length_t Size>
	using vectorui = vector<unsigned int, Size>;

	template <glm::length_t Size>
	using vectorul = vector<unsigned long, Size>;

	template <glm::length_t Size>
	using vectorull = vector<unsigned long long, Size>;

	template <glm::length_t Size>
	using vectorf = vector<float, Size>;

	template <glm::length_t Size>
	using vectord = vector<double, Size>;
}
