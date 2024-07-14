#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "entity.hpp"

namespace dls::properties::types {
	class property_group;
}

namespace dls::events::types {
	template <typename TFunc>
	class event;
}

namespace dls::core::types {
	class scene : public interfaces::serializable<scene> {
		private:
			wrappers::val<std::vector<wrappers::ref<entity>>> _entities;
			wrappers::val<properties::types::property_group> _properties;

			wrappers::type<events::types::event<void()>> _on_start;
			wrappers::type<events::types::event<void()>> _on_tick;
			wrappers::type<events::types::event<void()>> _on_exit;

		public:
			scene() : _entities(), _properties(), _on_start(), _on_tick(), _on_exit() { }
			scene(std::vector<wrappers::val<entity>> const& entities) : _entities(), _properties(), _on_start(), _on_tick(), _on_exit() {
				for (auto& ety : entities) {
					_entities.value().push_back(wrappers::ref<entity>{ ety });
				}
			}
			scene(std::vector<wrappers::ref<entity>> const& entities) : _entities(), _properties(), _on_start(), _on_tick(), _on_exit() {
				for (auto& ety : entities) {
					_entities.value().push_back(ety);
				}
			}

			std::vector<wrappers::ref<entity>> const& entities() const {
				return _entities.value();
			}

			std::vector<wrappers::ref<entity>>& entities() {
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

			void draw(std::string const& label) const override {
				_entities.draw("Entities");
				_properties.draw("Properties");
				_on_start.draw("On Start");
				_on_tick.draw("On Tick");
				_on_exit.draw("On Exit");
			}
	};
}
