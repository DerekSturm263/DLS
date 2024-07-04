#pragma once

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "interfaces/serializable.hpp"
#include "vector.hpp"
#include "matrix.hpp"

namespace dls::math {
	template <typename T>
	class quaternion : public serializable<quaternion<T>>, public glm::qua<T, glm::packed_highp> {
		private:
			using vector_type = vector<T, 3>;
			using matrix_type = matrix<T, 4, 4>;

		public:
			quaternion() : glm::qua<T, glm::packed_highp>(1, 0, 0, 0) { }

			quaternion(glm::qua<T, glm::packed_highp> const& rhs) : glm::qua<T, glm::packed_highp>(rhs) { }
			quaternion(glm::qua<T, glm::packed_highp>&& rhs) : glm::qua<T, glm::packed_highp>(rhs) { }

			quaternion(quaternion<T> const& rhs) : glm::qua<T, glm::packed_highp>(rhs) { }
			quaternion(quaternion<T>&& rhs) : glm::qua<T, glm::packed_highp>(rhs) { }
			
			quaternion(vector_type const& rotation) : glm::qua<T, glm::packed_highp>(rotation) { }

			vector_type to_euler() const {
				return glm::eulerAngles(*this);
			}

			matrix_type to_matrix() const {
				return glm::toMat4(*this);
			}

			quaternion<T>& operator =(quaternion<T> const& rhs) {
				this->data = rhs.data;
				return *this;
			}

			quaternion<T>& operator =(quaternion<T>&& rhs) {
				this->data = std::move(rhs.data);
				return *this;
			}

			void save(serializable_base::os& file) const override {
				vector_type euler{ to_euler() };
				file(CEREAL_NVP(euler));
			}

			void load(serializable_base::is& file) override {
				vector_type euler;
				file(euler);

				*this = quaternion{ euler };
			}
	};

	using quaternionc = quaternion<char>;
	using quaternions = quaternion<short>;
	using quaternioni = quaternion<int>;
	using quaternionl = quaternion<long>;
	using quaternionll = quaternion<long long>;
	using quaternionuc = quaternion<unsigned char>;
	using quaternionus = quaternion<unsigned short>;
	using quaternionui = quaternion<unsigned int>;
	using quaternionul = quaternion<unsigned long>;
	using quaternionull = quaternion<unsigned long long>;
}
