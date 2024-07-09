#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/core/entity.hpp"

namespace dls::miscellaneous::modules {
	template <typename T, typename Decimal>
	class emitter : public core::types::module<> {
		private:
			type<T> _object;
			type<Decimal> _rate;
			int _max;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_object));
				file(CEREAL_NVP(_rate));
				file(CEREAL_NVP(_max));
			}

			void load(is& file) override {
				file(_object);
				file(_rate);
				file(_max);
			}
	};
}
