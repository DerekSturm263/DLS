#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "../properties/property_group.hpp"
#include "../state machines/state_machine.hpp"
#include "scene.hpp"

namespace dls::core::types {
	class project : public interfaces::serializable<project> {
		private:
			wrappers::val<std::vector<wrappers::val<std::unique_ptr<system_base>>>> _systems;
			wrappers::val<state_machines::types::state_machine<wrappers::ref<scene>>> _scenes;
			wrappers::val<properties::types::property_group> _properties;
			
		public:
			project() : _systems(), _scenes(), _properties() { }

			template <typename... Ts>
			project(std::vector<core::wrappers::val<scene>> const& scenes, Ts&& ... systems) : _systems(), _scenes(), _properties() {
				/*([&] {
					std::unique_ptr<system_base> ptr = std::make_unique<Ts>(std::move(systems));
					wrappers::val<std::unique_ptr<system_base>> val{ std::move(ptr) };

					_systems.value().push_back(std::move(val));
				} (), ...);*/

				for (auto& scn : scenes) {
					_scenes.value().add_state(wrappers::ref<scene>{ scn });
				}
			}

			template <typename... Ts>
			project(std::vector<core::wrappers::ref<scene>> const& scenes, Ts&& ... systems) : _systems(), _scenes(), _properties() {
				/*([&] {
					std::unique_ptr<system_base> ptr = std::make_unique<Ts>(std::move(systems));
					wrappers::val<std::unique_ptr<system_base>> val{ std::move(ptr) };

					_systems.value().push_back(std::move(val));
				} (), ...);*/

				for (auto& scn : scenes) {
					_scenes.value().add_state(scn);
				}
			}

			std::vector<system_base*> systems() const {
				std::vector<system_base*> output{};

				/*for (auto& system : _systems.value()) {
					output.push_back(system.value().get());
				}*/

				return output;
			}

			state_machines::types::state_machine<core::wrappers::ref<scene>> const& scenes() const {
				return _scenes.value();
			}

			state_machines::types::state_machine<core::wrappers::ref<scene>>& scenes() {
				return _scenes.value();
			}

			properties::types::property_group const& properties() const {
				return _properties.value();
			}

			properties::types::property_group& properties() {
				return _properties.value();
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				//file(CEREAL_NVP(_systems));
				file(CEREAL_NVP(_scenes));
				file(CEREAL_NVP(_properties));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				//file(_systems);
				file(_scenes);
				file(_properties);
			}

			void draw(std::string const& label) const override {
				//_systems.draw("Systems");
				_scenes.draw("Scenes");
				_properties.draw("Properties");
			}
	};
}
