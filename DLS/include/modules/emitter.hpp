#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/core/entity.hpp"

namespace dls::emitter::modules {
	template <typename T>
	class emitter : public core::module<> {
		private:
			type<T> _to_emit;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_to_emit));
			}

			void load(is& file) override {
				file(_to_emit);
			}
	};
}
