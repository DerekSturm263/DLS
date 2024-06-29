#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/entity.hpp"

namespace dls {
	class emitter : public module<> {
		private:
			type<entity> _entity;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_entity));
			}

			void load(is& file) override {
				file(_entity);
			}
	};
}

REGISTER_MODULE(dls::emitter);
