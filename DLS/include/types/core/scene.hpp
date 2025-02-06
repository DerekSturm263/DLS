#pragma once

#include "types/collections/list.hpp"
#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"
#include "wrappers/ref.hpp"
#include "types/properties/property_group.hpp"
#include "types/core/window.hpp"
#include "entity.hpp"

namespace dls::core::types {
	class scene : public interfaces::serializable<scene> {
		private:
			wrappers::val<collections::types::list<wrappers::ref<entity>>> _entities;
			wrappers::val<core::types::window> _window;
			wrappers::val<properties::types::property_group> _properties;

		public:
			scene() : _entities(), _window(), _properties() { }
			scene(collections::types::list<wrappers::val<entity>> const& entities, core::types::window const& window) : _entities(), _window(window), _properties() {
				std::copy(entities.value().begin(), entities.value().end(), std::back_inserter(_entities.value().value()));
			}
			scene(collections::types::list<wrappers::ref<entity>> const& entities, core::types::window const& window) : _entities(entities), _window(window), _properties() { }

			collections::types::list<wrappers::ref<entity>> const& entities() const {
				return _entities.value();
			}

			collections::types::list<wrappers::ref<entity>>& entities() {
				return _entities.value();
			}

			core::types::window const& window() const {
				return _window.value();
			}

			core::types::window& window() {
				return _window.value();
			}

			properties::types::property_group const& properties() const {
				return _properties.value();
			}

			properties::types::property_group& properties() {
				return _properties.value();
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_entities));
				file(CEREAL_NVP(_window));
				file(CEREAL_NVP(_properties));
			}

			void load(is& file) override {
				file(_entities);
				file(_window);
				file(_properties);
			}
	};
}
