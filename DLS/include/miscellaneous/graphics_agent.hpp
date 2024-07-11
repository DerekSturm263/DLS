#pragma once

#include "types/math/transform.hpp"
#include "types/graphics/material.hpp"
#include "types/graphics/mesh.hpp"

namespace dls::graphics::systems {
	template <typename T, glm::length_t Size>
	class graphics_agent {
		public:
			math::types::transform<T, Size> const& transform;
			types::material const& material;
			types::mesh const& mesh;

			graphics_agent(
				math::types::transform<T, Size> const& transform,
				types::material const& material,
				types::mesh const& mesh
			) : transform(transform), material(material), mesh(mesh) { }
	};
}
