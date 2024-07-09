#pragma once

#include "interfaces/system.hpp"

namespace dls::core::systems {
	class scene : public system<> {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
