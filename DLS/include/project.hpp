#pragma once

#include "serializable.hpp"
#include "type_templates.hpp"
#include "scene.hpp"
#include "state_machine.hpp"

namespace dls {
	class project : public serializable {
		private:
			state_machine<ref<scene>> _scenes;
			
		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_scenes));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_scenes));
			}
	};
}
