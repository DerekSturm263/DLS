#pragma once

#include "interfaces/system.hpp"

namespace dls::input::systems {
    class input : public system<> {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
    };
}
