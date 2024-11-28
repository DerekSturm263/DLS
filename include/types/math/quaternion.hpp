#pragma once

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "interfaces/serializable.hpp"
#include "vector.hpp"
#include "matrix.hpp"

namespace dls::math::types {
	template <typename T>
	class quaternion : public core::interfaces::serializable<quaternion<T>>, public glm::qua<T, glm::packed_highp> {
		private:
			using vector_type = vector<T, 3>;
			using matrix_type = matrix<T, 4, 4>;

		public:
			quaternion() : glm::qua<T, glm::packed_highp>(1, 0, 0, 0) { }

			quaternion(glm::qua<T, glm::packed_highp> const& rhs) : glm::qua<T, glm::packed_highp>(rhs) { }
			quaternion(glm::qua<T, glm::packed_highp>&& rhs) : glm::qua<T, glm::packed_highp>(std::move(rhs)) { }

			quaternion(quaternion<T> const& rhs) : glm::qua<T, glm::packed_highp>(rhs) { }
			quaternion(quaternion<T>&& rhs) : glm::qua<T, glm::packed_highp>(std::move(rhs)) { }
			
			quaternion(vector_type const& rotation) : glm::qua<T, glm::packed_highp>(rotation) { }
			quaternion(vector_type&& rotation) : glm::qua<T, glm::packed_highp>(std::move(rotation)) { }

			vector_type to_euler() const {
				return glm::eulerAngles(*this);
			}

			matrix_type to_matrix() const {
				return glm::toMat4(*this);
			}

			quaternion<T>& operator=(quaternion<T> const& rhs) {
				*this = rhs;
				return *this;
			}

			quaternion<T>& operator=(quaternion<T>&& rhs) {
				*this = std::move(rhs);
				return *this;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(to_euler()));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				vector_type euler;
				file(euler);

				*this = quaternion{ euler };
			}
	};
}
