#pragma once

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "interfaces/serializable.hpp"
#include "vector.hpp"
#include "matrix.hpp"

namespace dls {
	template <typename T>
	class quaternion : public serializable<quaternion<T>>, public glm::qua<T, glm::packed_highp> {
		private:
			using vector_type = vector<T, 3>;
			using matrix_type = matrix<T, 4, 4>;

		public:
			quaternion() : glm::quat(1, 0, 0, 0) { }

			quaternion(glm::quat const& rhs) : glm::quat(rhs) { }
			quaternion(quaternion<T> const& rhs) : glm::quat(rhs) { }
			quaternion(quaternion<T> const&& rhs) : glm::quat(rhs) { }
			
			quaternion(vector_type const& rotation) : glm::quat(rotation) { }

			vector_type to_euler() const {
				return glm::eulerAngles(*this);
			}

			matrix_type to_matrix() const {
				return glm::toMat4(*this);
			}

			void save(serializable_base::os& file) const override {
				vector_type euler = to_euler();
				file(CEREAL_NVP(euler));
			}

			void load(serializable_base::is& file) override {
				vector_type euler;
				file(euler);

				*this = quaternion{ euler };
			}
	};
}
