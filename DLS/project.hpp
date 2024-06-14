#pragma once

#include "serializable.hpp"
#include "type_templates.hpp"
#include "scene.hpp"
#include "state_machine.hpp"

namespace dls {
	class project : public serializable {
		private:
			val<state_machine<ref<scene>>> _scenes;
	};
}
