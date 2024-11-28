#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "interfaces/serializable.hpp"
#include "wrappers/type.hpp"
#include "vector.hpp"
#include "matrix.hpp"
#include "quaternion.hpp"

namespace dls::math::types {
	template <typename T, glm::length_t Size>
	class transformation : public core::interfaces::serializable<transformation<T, Size>> {
		private:
			using vector_type = vector<T, Size>;
			using quaternion_type = quaternion<T>;
			using matrix_type = matrix<T, Size + 1, Size + 1>;

			core::wrappers::type<vector_type> _position;
			core::wrappers::type<quaternion_type> _rotation;
			core::wrappers::type<vector_type> _scale;

			mutable matrix_type _matrix;
			mutable bool _is_dirty;

		public:
			transformation() : _position(vector_type{}), _rotation(quaternion_type{}), _scale(vector_type{ 1 }), _matrix(matrix_type{ 1 }), _is_dirty(true) { }
			
            transformation(vector_type const& position, vector_type const& rotation, vector_type const& scale) : _position(position), _rotation(quaternion_type{ rotation }), _scale(scale), _matrix(matrix_type{ 1 }), _is_dirty(true) { }
            transformation(vector_type&& position, vector_type&& rotation, vector_type&& scale) : _position(std::move(position)), _rotation(quaternion_type{ std::move(rotation) }), _scale(std::move(scale)), _matrix(matrix_type{ 1 }), _is_dirty(true) { }

            void set_position(vector_type const& position) {
                _position = position;
                _is_dirty = true;
            }

            void set_rotation(vector_type const& rotation) {
                _rotation = quaternion_type(rotation);
                _is_dirty = true;
            }

            void set_scale(vector_type const& scale) {
                _scale = scale;
                _is_dirty = true;
            }

            vector_type const& get_position() const {
                return _position;
            }

            vector_type get_rotation() const {
                return _rotation.to_euler();
            }

            vector_type const& get_scale() const {
                return _scale;
            }

            matrix_type const& get_matrix() const {
                if (_is_dirty) {
                    matrix_type model = matrix_type(1);

                    model = glm::scale(model, _scale.value());

                    matrix_type rot_mat = _rotation.value().to_matrix();
                    model = model * rot_mat;

                    model = glm::translate(model, _position.value());

                    _matrix = model;
                    _is_dirty = false;
                }

                return _matrix;
            }

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_position));
				file(CEREAL_NVP(_rotation));
				file(CEREAL_NVP(_scale));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_position);
				file(_rotation);
				file(_scale);
			}
	};
}