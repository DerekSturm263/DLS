#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "entity.hpp"

namespace dls {
	class scene : public serializable<scene> {
		private:
			val<std::vector<ref<entity>>> _entities;

		public:
			scene(val<std::vector<ref<entity>>> const& entities) : _entities(entities) { }

			val<std::vector<ref<entity>>> const& entities() const {
				return _entities;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_entities));
			}

			void load(is& file) override {
				file(_entities);
			}
	};
}
