#pragma once

#include "interfaces/system.hpp"

namespace dls::graphics::systems {
	class graphics : public system<> {
        public:
            void save(os& file) const override {

            }

            void load(is& file) override {

            }
	};
}
