#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	template <typename T, std::size_t Size>
	class transform : public serializable {
		private:
			using vector_type = vector<T, Size>;
			using quaternion_type = quaternion<T>;
			using matrix_type = matrix<T, Size + 1, Size + 1>;

			vector_type _position;
			quaternion_type _rotation;
			vector_type _scale;

			mutable matrix_type _matrix;
			mutable bool _is_dirty;

		public:
			transform() : _position(vector_type()), _rotation(quaternion_type()), _scale(vector_type(1)), _matrix(matrix_type(1)), _is_dirty(true) { }
			transform(vector_type const& position, vector_type const& rotation, vector_type const& scale) : _position(position), _rotation(quaternion_type(rotation)), _scale(scale), _matrix(matrix_type(1)), _is_dirty(true) { }

            void translate(vector_type const& position, vector_type const& rotation, vector_type const& scale) {
                set_position(get_position() + position);
                set_rotation(get_rotation() + rotation);
                set_scale(get_scale() + scale);
            }

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

            vector_type get_position() const {
                return _position;
            }
            vector_type get_rotation() const {
                return _rotation.to_euler();
            }
            vector_type get_scale() const {
                return _scale;
            }

            matrix_type get_matrix() const {
                if (_is_dirty) {
                    matrix_type model = matrix_type(1);

                    model = glm::scale(model, _scale);

                    matrix_type rot_mat = _rotation.to_matrix();
                    model = model * rot_mat;

                    model = glm::translate(model, _position);

                    _matrix = model;
                    _is_dirty = false;
                }

                return _matrix;
            }

			void save(os& file) const override {
				file(CEREAL_NVP(_position));
				file(CEREAL_NVP(_rotation));
				file(CEREAL_NVP(_scale));
			}

			void load(is& file) override {
				file(_position);
				file(_rotation);
				file(_scale);
			}
	};
}
