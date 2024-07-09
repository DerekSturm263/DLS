#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "../properties/property_group.hpp"
#include "../events/event.hpp"
#include "entity.hpp"

namespace dls::core::types {
	class scene : public serializable<scene> {
		private:
			val<std::vector<ref<entity>>> _entities;
			val<properties::types::property_group> _properties;

			type<events::types::event<void()>> _on_start;
			type<events::types::event<void()>> _on_tick;
			type<events::types::event<void()>> _on_exit;

		public:
			scene() : _entities(), _properties(), _on_start(), _on_tick(), _on_exit() { }
			scene(std::vector<val<entity>> const& entities) : _entities(), _properties(), _on_start(), _on_tick(), _on_exit() {
				for (auto& ety : entities) {
					_entities.value().push_back(ref<entity>{ ety });
				}
			}
			scene(std::vector<ref<entity>> const& entities) : _entities(), _properties(), _on_start(), _on_tick(), _on_exit() {
				for (auto& ety : entities) {
					_entities.value().push_back(ety);
				}
			}

			std::vector<ref<entity>> const& entities() const {
				return _entities.value();
			}

			std::vector<ref<entity>>& entities() {
				return _entities.value();
			}

			properties::types::property_group const& properties() const {
				return _properties.value();
			}

			properties::types::property_group& properties() {
				return _properties.value();
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_entities));
				file(CEREAL_NVP(_properties));
				file(CEREAL_NVP(_on_start));
				file(CEREAL_NVP(_on_tick));
				file(CEREAL_NVP(_on_exit));
			}

			void load(is& file) override {
				file(_entities);
				file(_properties);
				file(_on_start);
				file(_on_tick);
				file(_on_exit);
			}
	};
}
