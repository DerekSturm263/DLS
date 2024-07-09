#pragma once

#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "../properties/property_group.hpp"
#include "../state machines/state_machine.hpp"
#include "scene.hpp"

namespace dls::core::types {
	class project : public serializable<project> {
		private:
			val<std::vector<val<std::shared_ptr<system_base>>>> _systems;
			val<state_machines::types::state_machine<ref<scene>>> _scenes;
			val<properties::types::property_group> _properties;
			
		public:
			project() : _systems(), _scenes(), _properties() { }

			template <typename... Ts>
			project(std::vector<val<scene>> const& scenes, Ts const&& ... systems) : _systems(), _scenes(), _properties() {
				([&] {
					_systems.value().push_back(val<std::shared_ptr<system_base>>(std::make_shared<Ts>(systems)));
				} (), ...);

				for (auto& scn : scenes) {
					_scenes.value().add_state(ref<scene>{ scn });
				}
			}

			template <typename... Ts>
			project(std::vector<ref<scene>> const& scenes, Ts const&& ... systems) : _systems(), _scenes(), _properties() {
				([&] {
					_systems.value().push_back(val<std::shared_ptr<system_base>>(std::make_shared<Ts>(systems)));
				} (), ...);

				for (auto& scn : scenes) {
					_scenes.value().add_state(scn);
				}
			}

			state_machines::types::state_machine<ref<scene>> const& scenes() const {
				return _scenes.value();
			}

			state_machines::types::state_machine<ref<scene>>& scenes() {
				return _scenes.value();
			}

			properties::types::property_group const& properties() const {
				return _properties.value();
			}

			properties::types::property_group& properties() {
				return _properties.value();
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_systems));
				file(CEREAL_NVP(_scenes));
				file(CEREAL_NVP(_properties));
			}

			void load(is& file) override {
				file(_systems);
				file(_scenes);
				file(_properties);
			}
	};
}
