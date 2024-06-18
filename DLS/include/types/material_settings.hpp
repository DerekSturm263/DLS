#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	class material_settings : public serializable<material_settings> {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
