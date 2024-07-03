#pragma once

#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "property_group.hpp"
#include "scene.hpp"
#include "state_machine.hpp"

namespace dls {
	class project : public serializable<project> {
		private:
			val<state_machine<ref<scene>>> _scenes;
			val<property_group> _properties;
			
		public:
			project() : _scenes() { }
			project(std::vector<val<scene>> const& scenes) : _scenes() {
				for (auto& scn : scenes) {
					_scenes.value().add_state(ref<scene>{scn});
				}
			}

			val<state_machine<ref<scene>>> const& scenes() const {
				return _scenes;
			}

			val<property_group> const& properties() const {
				return _properties;
			}

			val<property_group>& properties() {
				return _properties;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_scenes));
				file(CEREAL_NVP(_properties));
			}

			void load(is& file) override {
				file(_scenes);
				file(_properties);
			}
	};
}
