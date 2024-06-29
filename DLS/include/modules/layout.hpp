#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"

namespace dls {
	class layout : public module<> {
		private:
			type<vector2<int>> _dimensions;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_dimensions));
			}

			void load(is& file) override {
				file(_dimensions);
			}
	};
}

REGISTER_MODULE(dls::layout);
