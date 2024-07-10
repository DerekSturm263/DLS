#pragma once

#include "types/graphics/material.hpp"
#include "types/graphics/mesh.hpp"

namespace dls::graphics::systems {
	class graphics_agent {
		public:
			types::material const& material;
			types::mesh const& mesh;

			graphics_agent(types::material const& material, types::mesh const& mesh) : material(material), mesh(mesh) { }
	};
}
