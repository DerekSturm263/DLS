#pragma once

#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "../properties/property_group.hpp"
#include "../state machines/state_machine.hpp"
#include "scene.hpp"

namespace dls::core {
	class project : public serializable<project> {
		private:
			val<state_machines::state_machine<ref<scene>>> _scenes;
			val<properties::property_group> _properties;
			
		public:
			project() : _scenes() { }
			project(std::vector<val<scene>> const& scenes) : _scenes() {
				for (auto& scn : scenes) {
					_scenes.value().add_state(ref<scene>{scn});
				}
			}

			state_machines::state_machine<ref<scene>> const& scenes() const {
				return _scenes.value();
			}

			properties::property_group const& properties() const {
				return _properties.value();
			}

			properties::property_group& properties() {
				return _properties.value();
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
