#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "property_group.hpp"
#include "event.hpp"
#include "entity.hpp"

namespace dls {
	class scene : public serializable<scene> {
		private:
			val<std::vector<ref<entity>>> _entities;
			val<property_group> _properties;

			type<event<void()>> _on_load;
			type<event<void()>> _on_enable;
			type<event<void()>> _on_start;
			type<event<void()>> _on_tick;
			type<event<void()>> _on_exit;
			type<event<void()>> _on_disable;
			type<event<void()>> _on_unload;

		public:
			scene() : _entities() { }
			scene(std::vector<val<entity>> const& entities) : _entities() {
				for (auto& ety : entities) {
					_entities.value().push_back(ref<entity>{ety});
				}
			}

			std::vector<ref<entity>> const& entities() const {
				return _entities.value();
			}
			/*
			property const& at(std::string const& name) const {
				return _properties.value().at(name);
			}

			property& at(std::string const& name) {
				return _properties.value().at(name);
			}
			*/
			void save(os& file) const override {
				file(CEREAL_NVP(_entities));
				//file(CEREAL_NVP(_properties));
			}

			void load(is& file) override {
				file(_entities);
				//file(_properties);
			}
	};
}
