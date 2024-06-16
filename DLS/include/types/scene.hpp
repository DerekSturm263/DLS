#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "entity.hpp"

namespace dls {
	class scene : public serializable {
		private:
			val<std::vector<ref<entity>>> _entities;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_entities));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_entities));
			}
	};
}
