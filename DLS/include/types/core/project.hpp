#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"
#include "wrappers/ref.hpp"
#include "types/collections/map.hpp"
#include "types/properties/property_group.hpp"
#include "scene.hpp"
#include "system.hpp"

namespace dls::core::types {
	class project : public interfaces::serializable<project> {
		private:
			wrappers::val<collections::types::map<size_t, wrappers::val<std::unique_ptr<system_base>>>> _systems;
			wrappers::val<collections::types::list<wrappers::ref<scene>>> _scenes;
			wrappers::val<properties::types::property_group> _properties;
			
		public:
			project() : _systems(), _scenes(), _properties() { }

			template <typename... Ts>
			project(collections::types::list<core::wrappers::val<scene>> const& scenes, Ts&& ... systems) : _systems(sizeof...(systems)), _scenes(), _properties() {
				([&] {
					std::unique_ptr<system_base> ptr = std::make_unique<Ts>(std::move(systems));
					wrappers::val<std::unique_ptr<system_base>> val{ std::move(ptr) };

					_systems.value().value().insert(std::make_pair(typeid(Ts).hash_code(), std::move(val)));
				} (), ...);

				std::copy(scenes.value().begin(), scenes.value().end(), std::back_inserter(_scenes.value().value()));
			}

			template <typename... Ts>
			project(collections::types::list<core::wrappers::ref<scene>> const& scenes, Ts&& ... systems) : _systems(sizeof...(systems)), _scenes(scenes), _properties() {
				([&] {
					std::unique_ptr<system_base> ptr = std::make_unique<Ts>(std::move(systems));
					wrappers::val<std::unique_ptr<system_base>> val{ std::move(ptr) };

					_systems.value().value().insert(std::make_pair(typeid(Ts).hash_code(), std::move(val)));
				} (), ...);
			}

			std::vector<system_base*> systems() const {
				std::vector<system_base*> output{};

				for (auto& system : _systems.value().value()) {
					output.push_back(system.second.value().get());
				}

				return output;
			}

			template <typename T>
			std::optional<T const*> get_system() const {
				size_t index = typeid(T).hash_code();

				if (_systems.value().value().contains(index))
					return static_cast<T const*>(_systems.value().value().at(index).value().get());

				return std::nullopt;
			}

			template <typename T>
			std::optional<T*> get_system() {
				size_t index = typeid(T).hash_code();

				if (_systems.value().value().contains(index))
					return static_cast<T*>(_systems.value().value().at(index).value().get());

				return std::nullopt;
			}

			collections::types::list<core::wrappers::ref<scene>> const& scenes() const {
				return _scenes.value();
			}

			collections::types::list<core::wrappers::ref<scene>>& scenes() {
				return _scenes.value();
			}

			properties::types::property_group const& properties() const {
				return _properties.value();
			}

			properties::types::property_group& properties() {
				return _properties.value();
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_systems));
				file(CEREAL_NVP(_scenes));
				file(CEREAL_NVP(_properties));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_systems);
				file(_scenes);
				file(_properties);
			}
	};
}
