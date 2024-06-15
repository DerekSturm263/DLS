#pragma once

#include "serializable.hpp"
#include "type_templates.hpp"
#include "shader.hpp"
#include "material_settings.hpp"

namespace dls {
	class material : public serializable {
		private:
			required<ref<shader>> _shader;
			material_settings _settings;
	};
}
