#pragma once

#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include "interfaces/serializable.hpp"
#include "interfaces/interpolatable.hpp"
#include "interfaces/randomly_generatable.hpp"

namespace dls {
	template <typename T, glm::length_t Size>
	class vector : public serializable<vector<T, Size>>, public interpolatable<vector<T, Size>>, public glm::vec<Size, T, glm::packed_highp> {
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

			void save(serializable_base::os& file) const override {
				for (int i = 0; i < Size; ++i) {
					file((*this)[i]);
				}
			}

			void load(serializable_base::is& file) override {
				for (int i = 0; i < Size; ++i) {
					file((*this)[i]);
				}
			}

			vector<T, Size> lerp(vector<T, Size> const& b, fixed<32> t) const override {
				vector<T, Size> output{};

				for (int i = 0; i < Size; ++i) {
					output[i] = *this + (b - *this) * t;
				}

				return output;
			}

			fixed<32> inverse_lerp(vector<T, Size> const& b, vector<T, Size> const& v) const override {
				
			}
	};

	template <typename T>
	using vector2 = vector<T, 2>;

	template <typename T>
	using vector3 = vector<T, 3>;

	template <typename T>
	using vector4 = vector<T, 4>;
}
