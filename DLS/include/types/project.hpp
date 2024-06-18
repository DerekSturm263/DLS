#pragma once

#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "scene.hpp"
#include "state_machine.hpp"

namespace dls {
	class project : public serializable<project> {
		private:
			val<state_machine<ref<scene>>> _scenes;
			
		public:
			project(val<state_machine<ref<scene>>> const& scenes) : _scenes(scenes) { }

			val<state_machine<ref<scene>>> const& scenes() const {
				return _scenes;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_scenes));
			}

			void load(is& file) override {
				file(_scenes);
			}
	};
}
