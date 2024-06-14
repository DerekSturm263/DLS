#pragma once

#include <variant>
#include "serializable.hpp"
#include "type_templates.hpp"

#include "animation.hpp"
#include "clip.hpp"
#include "color.hpp"
#include "entity.hpp"
#include "event.hpp"
#include "fixed.hpp"
#include "graph.hpp"
#include "input_button.hpp"
#include "mask.hpp"
#include "material.hpp"
#include "matrix.hpp"
#include "mesh.hpp"
#include "polygon.hpp"
#include "processor.hpp"
#include "quaternion.hpp"
#include "range.hpp"
#include "rect.hpp"
#include "state_machine.hpp"
#include "texture.hpp"
#include "variants.hpp"
#include "vector.hpp"

namespace dls {
	class property : public serializable {
		using any = std::variant<animation, clip, color, entity, event, fixed, graph, input_button, mask, material, matrix, mesh, polygon, processor, quaternion, range, rect, state_machine, texture, variants, vector>;

		private:
			std::string _name;
			val<any> _value;
	};
}
